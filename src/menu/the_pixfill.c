/*
** fill.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:42:39 2016
** Last update Sat May 21 22:58:19 2016 
*/

#include "rt.h"

void	fill(t_bunny_pixelarray *pix, unsigned int color)
{
  int	i;

  i = -1;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      *(((unsigned int *)pix->pixels) + i) =
	color_mixer(*(((unsigned int *)pix->pixels) + i), color);
    }
}

void			make_square(t_bunny_pixelarray *pix,
				    t_bunny_position *pos,
				    t_bunny_position *size,
				    unsigned int color)
{
  t_bunny_position	idx;

  if (!pix || !pos || !size)
    return ;
  idx.y = -1;
  while (++idx.y < size->y)
    {
      idx.x = -1;
      while (++idx.x < size->x)
	{
	  if ((pos->x + idx.x >= 0 && pos->x + idx.x
	       < pix->clipable.buffer.width)
	      && (pos->y + idx.y >= 0 && pos->y + idx.y
		  < pix->clipable.buffer.height))
	    *(((unsigned int *)pix->pixels) +
	      ((pos->y + idx.y) * pix->clipable.buffer.width +
	       pos->x + idx.x)) = color;
	}
    }
}

void			menu_light(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 10;
  (*pos).y = 80;
  (*(pos + 1)).x = 120;
  (*(pos + 1)).y = 40;
  if (data->light == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 17;
  text->pos.y = 90;
  my_blitstr("LIGHTS", *data->pix, data->font, text);
}

void			menu_shine(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 140;
  (*pos).y = 80;
  (*(pos + 1)).x = 120;
  (*(pos + 1)).y = 40;
  if (data->aalias == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 157;
  text->pos.y = 90;
  my_blitstr("ALIAS", *data->pix, data->font, text);
}

void			menu_baw(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 10;
  (*pos).y = 140;
  (*(pos + 1)).x = 120;
  (*(pos + 1)).y = 40;
  if (data->baw == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 17;
  text->pos.y = 150;
  my_blitstr("B & W", *data->pix, data->font, text);
}
