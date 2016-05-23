/*
** rays_details.c for dawdaw in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 13:27:26 2016 Alif Matthias
** Last update Sun May 22 22:22:20 2016 Alif Matthias
*/

#include "rt.h"

unsigned int	end_ray(t_eko *ret, t_thd *data,
			const t_vec *ray)
{
  int		save;

  save = ret->t;
  if (ret->t <= 0.1 || !ret->fig)
    return (BLACK);
  ret->col.full = ret->fig->rgb.full;
  if (data->data->light == 1)
    ret->col.full = apply_light(ret, data);
  if (data->data->refl == 1 && data->refl < MAX_REMIX)
    apply_remix(ret, data, ray);
  if (data->data->alpha == 1 && data->alpha < MAX_REMIX)
    apply_alpha(ret, data, ray);
  data->t = save;
  return (ret->col.full);
}

t_vec	diff(const t_vec *one, const t_vec *two)
{
  t_vec	ret;

  ret.x = one->x - two->x;
  ret.y = one->y - two->y;
  ret.z = one->z - two->z;
  return (ret);
}
