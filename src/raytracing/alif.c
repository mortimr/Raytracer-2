/*
** alif.c for rtv2 in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 18:36:56 2016 Alif Matthias
** Last update Sun May 22 17:24:35 2016 Alif Matthias
*/

#include "rt.h"

static int	(g_alif[8][2]) =
{
  {-1, 0},
  {1, 1},
  {0, -2},
  {-1, 0},
  {2, 0},
  {0, 2},
  {-2, 0},
  {1, -1},
};

static unsigned int	apply_alif(t_color *moy, int *i)
{
  int			tmp[4];

  *i = -1;
  mset(tmp, sizeof(int) * 4);
  while (++*i < 8)
    {
      *(i + 1) = -1;
      while (++*(i + 1) < 4)
	tmp[*(i + 1)] += moy[*i].argb[*(i + 1)];
    }
  *(i + 1) = -1;
  while (++*(i + 1) < 4)
    moy[8].argb[*(i + 1)] = tmp[*(i + 1)] / 9;
  return (moy[8].full);
}

static unsigned int	no_alif(t_thd *data, t_vec *ray,
				t_bunny_position *pos, t_vec *up_pos)
{
  unsigned int		ret;

  *ray = get_ray(pos, data, up_pos);
  data->alpha = 0;
  data->refl = 0;
  ret = send_ray(ray, data, &data->data->eye, NULL);
  data->data->dists[pos->y * X_MAX + pos->x] = data->t;
  data->t = -1;
  return (ret);
}

unsigned int	alif(t_bunny_position *pos, t_thd *data, t_vec *up_pos)
{
  t_vec		ray;
  t_color	moy[9];
  int		i[2];
  unsigned int	ret;

  if (data->data->aalias == 0)
    return (no_alif(data, &ray, pos, up_pos));
  *i = -1;
  while (++*i < 8)
    {
      ray = get_ray(pos, data, up_pos);
      data->alpha = 0;
      data->refl = 0;
      moy[*i].full = send_ray(&ray, data, &data->data->eye, NULL);
      pos->x += g_alif[*i][0];
      pos->y += g_alif[*i][1];
    }
  ret = apply_alif(moy, i);
  data->data->dists[pos->y * X_MAX + pos->x] = data->t;
  data->t = -1;
  return (ret);
}
