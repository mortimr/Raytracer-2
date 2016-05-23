/*
** blur.c for RTV2 in /home/brunet_f/modules/info
**
** Made by Julien Brunet
** Login   <brunet_f@epitech.net>
**
** Started on  Sun May 22 13:19:21 2016 Julien Brunet
** Last update Sun May 22 21:34:48 2016 Julien Brunet
*/

#include "rt.h"

static void	add_color(int *rgb,
			  t_bunny_pixelarray *arr,
			  int x,
			  int y)
{
  t_color	*color;

  if (arr == NULL)
    {
      rgb[0] = 0;
      rgb[1] = 0;
      rgb[2] = 0;
    }
  else
    {
      color = arr->pixels;
      color += y * X_MAX + x;
      rgb[0] += color->argb[RED_CMP];
      rgb[1] += color->argb[GREEN_CMP];
      rgb[2] += color->argb[BLUE_CMP];
    }
}

static unsigned int	apply_average(int *rgb, int divisor)
{
  t_color		color;

  color.argb[RED_CMP] = rgb[0] / divisor;
  color.argb[GREEN_CMP] = rgb[1] / divisor;
  color.argb[BLUE_CMP] = rgb[2] / divisor;
  return (color.full);
}

static void	set_indexes(t_bunny_position *pos,
			    t_bunny_position *start,
			    t_bunny_position *end,
			    int size)
{
  start->x = pos->x - size / 2;
  start->y = pos->y - size / 2;
  if (start->x < 0)
    start->x = 0;
  if (start->y < 0)
    start->y = 0;
  end->x = pos->x + size / 2;
  end->y = pos->y + size / 2;
  if (end->x >= X_MAX)
    end->x = X_MAX - 1;
  if (end->y >= Y_MAX)
    end->y = Y_MAX - 1;
}

static unsigned int	get_average_around(t_bunny_pixelarray *arr,
					   t_bunny_position *pos,
					   int factor)
{
  t_bunny_position	start;
  t_bunny_position	end;
  int			rgb[3];
  int			x;
  int			size;
  int			divisor;

  add_color(rgb, NULL, 0, 0);
  size = 3 + (factor - 1) * 2;
  set_indexes(pos, &start, &end, size);
  divisor = 0;
  while (start.y <= end.y)
    {
      x = start.x;
      while (x <= end.x)
	{
	  add_color(rgb, arr, x, start.y);
	  ++x;
	  ++divisor;
	}
      ++(start.y);
    }
  return (apply_average(rgb, divisor));
}

void		brunet(t_bunny_pixelarray *arr,
		       unsigned int *tab,
		       int *limits)
{
  t_bunny_position	pos;
  unsigned int		tmp[X_MAX * Y_MAX];
  float			factor;
  int			index;
  float			scale;

  scale = limits[1] - limits[0];
  pos.y = 0;
  while (pos.y < Y_MAX)
    {
      pos.x = 0;
      while (pos.x < X_MAX)
	{
	  index = pos.y * X_MAX + pos.x;
	  factor = MAX_BLUR * (tab[index] - limits[0]) / scale;
	  tmp[index] = get_average_around(arr, &pos, factor);
	  ++(pos.x);
	}
      ++(pos.y);
    }
  apply_blur(arr, tmp);
}
