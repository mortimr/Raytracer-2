/*
** blur_end.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 21:03:15 2016
** Last update Sun May 22 21:03:17 2016 
*/

#include "rt.h"

void	apply_blur(t_bunny_pixelarray *arr,
			   unsigned int *tab)
{
  t_color	*color;
  int		i;

  i = 0;
  while (i < X_MAX * Y_MAX)
    {
      color = arr->pixels;
      color += i;
      color->full = tab[i];
      ++i;
    }
}
