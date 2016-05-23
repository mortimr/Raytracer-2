/*
** menu_blur.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:44:38 2016
** Last update Sat May 21 22:55:01 2016 
*/

#include "rt.h"

void			menu_blur(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 140;
  (*pos).y = 140;
  (*(pos + 1)).x = 120;
  (*(pos + 1)).y = 40;
  if (data->blur == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 157;
  text->pos.y = 150;
  my_blitstr("BLUR", *data->pix, data->font, text);
  if (data->blur == 1)
    {
      text->pos.y = 150;
      text->police_size = 21;
      text->pos.x = 280;
      my_blitnbr(data->edit.edit == &data->blur_dist ? nbr(data->edit.buffer)
		 : data->blur_dist, *data->pix, data->font, text);
    }

}

void			menu_refl(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 270;
  (*pos).y = 80;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  if (data->refl == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 287;
  text->pos.y = 90;
  my_blitstr("REFL", *data->pix, data->font, text);
}

void			menu_alpha(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 385;
  (*pos).y = 80;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  if (data->alpha == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 392;
  text->pos.y = 90;
  my_blitstr("ALPHA", *data->pix, data->font, text);
}

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color)
{
  if ((pix && pos)
      && (pos->x >= 0 && pos->x < pix->clipable.buffer.width)
      && (pos->y >= 0 && pos->y < pix->clipable.buffer.height))
    *(((unsigned int *)pix->pixels) + pos->y
      * pix->clipable.buffer.width + pos->x) = color;
}

void			circle(t_bunny_pixelarray *pix,
			       t_bunny_position *rep,
			       int *radius,
			       unsigned int color)
{
  double		t;
  int			i;
  t_bunny_position	pos;

  i = -1;
  while (++i < *(radius + 1))
    {
      t = 0.0;
      while (t < 360.0)
	{
	  pos.x = rep[0].x + (*radius + i) * cos(t * M_PI / 180);
	  pos.y = rep[0].y + (*radius + i) * sin(t * M_PI / 180);
	  tekpixel(pix, &pos, color);
	  t += 0.3;
	}
    }
}
