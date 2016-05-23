/*
** menu_threads.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:55:21 2016
** Last update Sat May 21 22:33:43 2016 
*/

#include "rt.h"

void		menu_threads(t_data *data)
{
  t_text	text;

  fill(*(data->pix), 0x88EEEEEE);
  text.police_size = 21;
  text.pos.x = 0;
  text.pos.y = 200;
  text.x = LETTER_X;
  text.y = LETTER_Y;
  text.fg = BLACK;
  menu_threads_nb(data, &text);
  threads_animation(data, 0);
}

void			empty_square(t_bunny_pixelarray *pix,
				     t_bunny_position *pos,
				     unsigned int *color,
				     int mode)
{
  t_bunny_position	new[2];

  make_square(pix, pos, pos + 1, *color);
  if (mode == 0)
    {
      (*new).x = (*pos).x + 1;
      (*new).y = (*pos).y + 1;
      (*(new + 1)).x = (*(pos + 1)).x - 2;
      (*(new + 1)).y = (*(pos + 1)).y - 2;
    }
  else
    {
      (*new).x = (*pos).x + 1;
      (*new).y = (*pos).y + 1;
      (*(new + 1)).x = (*(pos + 1)).x - 1;
      (*(new + 1)).y = (*(pos + 1)).y - 2;
    }
  make_square(pix, new, new + 1, *(color + 1));
}

void			aff_eye(t_data *data)
{
  t_bunny_position	pos[2];
  unsigned int		colors[2];
  int			y;

  (*pos).x = 0;
  (*pos).y = 50;
  (*(pos + 1)).x = 50;
  (*(pos + 1)).y = 50;
  *colors = BLACK;
  *(colors + 1) = data->menu.focus == 0 ? 0xFFEEEEEE : 0xFF999999;
  empty_square(*data->pix, pos, colors, data->menu.focus == 0 ? 1 : 0);
  if (data->menu.focus == 0)
    {
      y = 42;
      while (++y < (*data->pix)->clipable.buffer.height)
	{
	  if (y <= 50 || y >= 100)
	    *(((unsigned int *)(*data->pix)->pixels)
	      + y * (*data->pix)->clipable.buffer.width + 50) = BLACK;
	}
    }
  my_bunny_blit(*data->pix, *data->menu.butts, pos, 1);
}

void			aff_arrows(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 100;
  my_bunny_blit(*data->pix, *(data->menu.butts + 1), &pos, 1);
  pos.x = 0;
  pos.y = (*data->pix)->clipable.buffer.height - 50;
  my_bunny_blit(*data->pix, *(data->menu.butts + 2), &pos, 1);
}

void	aff_static_icons(t_data *data)
{
  aff_eye(data);
  aff_arrows(data);
}
