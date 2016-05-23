/*
** strcopy.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:18:57 2016
** Last update Sun May 22 21:54:34 2016 
*/

#include "rt.h"

void	strcopy(char *one, char *two)
{
  int	i;

  i = -1;
  if (!len(one) || len(two))
    return ;
  while (*(one + ++i) && i < 4095)
    *(two + i) = *(one + i);
  *(two + i) = 0;
}

void		bentor_white(t_bunny_pixelarray *pix)
{
  int		i;
  char		moy;
  t_color	recup;

  i = -1;
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      recup.full = *(((unsigned int *)pix->pixels) + i);
      moy = (recup.argb[0] + recup.argb[1] + recup.argb[2]) / 3;
      recup.argb[0] = moy;
      recup.argb[1] = moy;
      recup.argb[2] = moy;
      *(((unsigned int *)pix->pixels) + i) = recup.full;
    }
}

void	start_edit(t_data *data, int mode, void *edit)
{
  if (data->edit.on != 0)
    return ;
  data->edit.input_mode = mode;
  data->edit.on = 1;
  data->edit.edit = edit;
  data->edit.idx = 0;
  if (mode == 1)
    {
      strcopy(*((char **)edit), data->edit.buffer);
      data->edit.idx = len(*((char **)edit));
    }
}

t_vec		cross_product(t_vec *one, t_vec *two)
{
  t_vec		ret;
  double	nor;

  ret.x = one->y * two->z - one->z * two->y;
  ret.y = one->z * two->x - one->x * two->z;
  ret.z = one->x * two->y - one->y * two->x;
  nor = norm(&ret);
  ret.x /= nor;
  ret.y /= nor;
  ret.z /= nor;
  return (ret);
}

int	cl_btw(int xmin, int xmax, int ymin, int ymax)
{
  if ((bunny_get_mouse_position()->x >= xmin
       && bunny_get_mouse_position()->x < xmax)
      && (bunny_get_mouse_position()->y > ymin
	  && bunny_get_mouse_position()->y < ymax))
    return (OK);
  return (KO);
}
