/*
** my_blitstr.c for liblap in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Feb  2 17:31:01 2016 Iulian Rotaru
** Last update Sun May 22 18:46:18 2016 Alif Matthias
*/

#include "rt.h"

void		copy_area(t_bunny_pixelarray *pix,
			  t_bunny_pixelarray *extract,
			  t_bunny_position *area,
			  t_text *text)
{
  t_area_text	v;

  v.text = text;
  v.ratio = v.text->police_size / 7;
  if (v.ratio == 0)
    v.ratio = 1;
  v.ptr = (unsigned int*) pix->pixels;
  v.ptrr = (unsigned int*) extract->pixels;
  v.blit.x = area[2].x;
  v.blit.y = area[2].y;
  v.y = 0;
  v.pix = pix;
  v.extract = extract;
  v.area = area;
  main_boucle(&v);
}

void	ps(t_bunny_position *pos, t_text *text)
{
  pos[2].x = text->pos.x;
  pos[2].y = text->pos.y;
  pos[0].y = 0;
  pos[1].y = text->y;
}

void	my_blitnbr(int nb,
		   t_bunny_pixelarray *pix,
		   t_bunny_pixelarray *text_pix,
		   t_text *text)
{
  int	i[2];
  char	buffer[11];
  int	multi;

  i[0] = 0;
  if (nb < 0)
    {
      i[0] = 1;
      nb = -nb;
      *buffer = '-';
    }
  multi = 1;
  i[1] = nb;
  while ((i[1] /= 10) != 0)
    multi *= 10;
  *(buffer + i[0]) = (nb / multi) + 48;
  while (multi != 0)
    {
      *(buffer + i[0]) = (nb / multi) + 48;
      nb = nb % multi;
      multi = multi / 10;
      ++i[0];
    }
  *(buffer + i[0]) = 0;
  my_blitstr(buffer, pix, text_pix, text);
}

void			my_blitstr(char *str,
				   t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *text_pix,
				   t_text *text)
{
  t_bunny_position	pos[3];
  int			i;
  int			ratio;

  ps(pos, text);
  if ((ratio = text->police_size / 7) && !(i = 0) && ratio == 0)
    ratio = 1;
  while (str[i])
    {
      pos[0].x = text->x * str[i];
      pos[1].x = text->x * (str[i] + 1);
      if ((str[i] != '\n' && str[i] > '\n' &&
	   pos[2].x >= 0 && pos[2].x < pix->clipable.clip_width)
	  && (pos[2].x + 6 * ratio >= 0 &&
	      pos[2].x + 6 * ratio < pix->clipable.clip_width))
	copy_area(pix, text_pix, pos, text);
      else if (str[i] == '\n')
	{
	  pos[2].y += 10 * ratio;
	  pos[2].x = text->pos.x - 6 * ratio;
	}
      i++;
      pos[2].x += 6 * ratio;
    }
}
