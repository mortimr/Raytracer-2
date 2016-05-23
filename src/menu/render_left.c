/*
** render_left.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:46:32 2016
** Last update Sat May 21 22:32:16 2016 
*/

#include "rt.h"

void	render_left_one(t_bunny_position *pos, t_color *colors, int *round)
{
  pos->x = 260;
  pos->y = 700;
  *round += 40;
  (*colors).argb[2] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
  (*(colors + 1)).argb[0] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
}

void			render_animation_left(t_data *data)
{
  static int		round;
  static t_color	colors[2];
  int			sender[2];
  t_bunny_position	pos;

  if (data->render_state == 0)
    {
      data->menu.render_butt.full = 0xFFEEEEEE;
      round = 0;
      return ;
    }
  render_left_one(&pos, colors, &round);
  *sender = ((round % 6000) < 3000 ? sqrt(round % 6000)
	     : sqrt(6000 - (round % 6000))) * 1;
  *(sender + 1) = (round % 500) < 250 ? (round % 500) / 200 + 3
    : (500 - (round % 500)) / 200 + 3;
  circle(*data->pix, &pos, sender, (*colors).full);
  *sender = (((round + 500) % 4000) < 2000 ? sqrt((round + 500) % 4000)
	     : sqrt(4000 - ((round + 500) % 4000))) * 1;
  *(sender + 1) = ((round + 500) % 500) < 250 ? ((round + 500) % 500) / 200 + 3
    : (500 - ((round + 500) % 500)) / 200 + 3;
  circle(*data->pix, &pos, sender, (*(colors + 1)).full);
  data->menu.render_butt.argb[0] = (round / 15) % (238 * 2) < 238
    ? (round / 15) % (238 * 2) : (2 * 238) - ((round / 15) % (238 * 2));
  data->menu.render_butt.argb[1] = data->menu.render_butt.argb[0];
}

void	render_right_one(t_bunny_position *pos, t_color *colors, int *round)
{
  pos->x = 240;
  pos->y = 700;
  *round += 40;
  (*colors).argb[2] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
  (*(colors + 1)).argb[0] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
}

void			render_animation_right(t_data *data)
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
  render_right_one(&pos, colors, &round);
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

void	render_down_one(t_bunny_position *pos, t_color *colors, int *round)
{
  pos->x = 250;
  pos->y = 720;
  *round += 40;
  (*colors).argb[2] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
  (*(colors + 1)).argb[0] = *round / 2 % 512 < 255 ? *round / 2 % 512
    : (512 - *round / 2 % 512);
}
