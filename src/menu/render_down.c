/*
** render_down.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:48:28 2016
** Last update Sat May 21 23:19:11 2016 
*/

#include "rt.h"

void			render_animation_down(t_data *data)
{
  static int		round;
  static t_color	colors[2];
  int			sender[2];
  t_bunny_position	pos;

  if (data->render_state == 0)
    {
      round = 0;
      return ;
    }
  render_down_one(&pos, colors, &round);
  *sender = ((round % 6000) < 3000 ? sqrt(round % 6000)
	     : sqrt(6000 - (round % 6000))) * 1;
  *(sender + 1) = (round % 500) < 250 ? (round % 500) / 200 + 3
    : (500 - (round % 500)) / 200 + 3;
  circle(*data->pix, &pos, sender, (*colors).full);
  *sender = (((round + 500) % 4000) < 2000 ? sqrt((round + 500) % 4000)
	     : sqrt(4000 - ((round + 500) % 4000))) * 1;
  *(sender + 1) = ((round + 500) % 500) < 250
    ? ((round + 500) % 500) / 200 + 3
    : (500 - ((round + 500) % 500)) / 200 + 3;
  circle(*data->pix, &pos, sender, (*(colors + 1)).full);
}

void			case_one_thread(t_data *data)
{
  int			sender[2];
  t_bunny_position	pos;

  *sender = 0;
  *(sender + 1) = data->thread_nb > 2 ? 240 / (data->thread_nb) + 10 : 60;
  pos.x = 250;
  pos.y = 700;
  circle(*data->pix, &pos, sender, 0xFF333333);
}

void	set_pos(t_bunny_position *pos, double ecart, double round)
{
  pos->x = 250 + 200 * cos((double)
			   ((int)(round + ecart) % 360) * M_PI / 180);
  pos->y = 700 + 200 * sin((double)
			   ((int)(round + ecart) % 360) * M_PI / 180);
}

void		case_multi_thread(t_data *data,
				  int increm,
				  double round,
				  t_bunny_position *pos)
{
  double	ecart;
  int		sender[2];

  ecart = 0.0;
  while (++increm < data->thread_nb)
    {
      set_pos(pos, ecart, round);
      ecart += (360.0 / data->thread_nb);
      if (((int)(round / 20) % data->thread_nb == increm)
	  || ((int)((round / 20) + data->thread_nb / 2)
	      % data->thread_nb == increm
	      && data->thread_nb > 2))
	{
	  *sender = 0;
	  *(sender + 1) = data->thread_nb > 2
	    ? 240 / (data->thread_nb) + 10 : 60;
	  circle(*data->pix, pos, sender, 0xFF333333);
	}
      else
	{
	  *sender = data->thread_nb > 2 ? 240 / (data->thread_nb) : 60;
	  *(sender + 1) = 5;
	  circle(*data->pix, pos, sender, BLACK);
	}
    }
}

void			threads_animation(t_data *data, int mode)
{
  static double		round;
  int			increm;
  t_bunny_position	pos;

  increm = -1;
  if (mode == 1)
    {
      round = 0.0;
      return ;
    }
  if (data->thread_nb == 1)
    case_one_thread(data);
  else
    case_multi_thread(data, increm, round, &pos);
  round += 1.0 + data->thread_changed_speed;
  if (data->thread_changed_speed > 0.1)
    data->thread_changed_speed -= 0.2;
}
