/*
** base_forms.c for raytracer in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 18:12:00 2016 Alif Matthias
** Last update Sun May 22 17:11:59 2016 Alif Matthias
*/

#include "rt.h"

double	deter_angle(t_fig *elem)
{
  t_vec	nor;

  nor.x = 0;
  nor.y = 1;
  nor.z = 0;
  return (angle_vec(&nor, &elem->dvec));
}

static void	polynom(const t_vec *ray, const t_eye *eye,
			const t_fig *elem, t_vec *eq)
{
  eq->x = pow(ray->x, 2) + pow(ray->z, 2);
  eq->y = 2 * (ray->x * (eye->pos.x - elem->pos.x)
	      + ray->z * (eye->pos.z - elem->pos.z));
  eq->z = pow(eye->pos.x - elem->pos.x, 2)
    + pow(eye->pos.z - elem->pos.z, 2)
    - pow(elem->radius, 2);
}

t_eko		cylinder(const t_vec *ray, const t_eye *eye, const t_fig *elem)
{
  t_vec		eq;
  t_eko		ret;
  double	delta;
  double	t;

  ret.t = -1;
  polynom(ray, eye, elem, &eq);
  if ((delta = (pow(eq.y, 2) - 4 * eq.x * eq.z)) > 0)
    {
      t = ((-eq.y - sqrt(delta)) / (2 * eq.x) > (-eq.y + sqrt(delta)) / (2 * eq.x)
	   ? (-eq.y + sqrt(delta)) / (2 * eq.x)
	   : (-eq.y - sqrt(delta)) / (2 * eq.x));
      ret.pos.x = eye->pos.x + ray->x * t;
      ret.pos.y = eye->pos.y + ray->y * t;
      ret.pos.z = eye->pos.z + ray->z * t;
      if ((elem->min.x != 0 && ret.pos.y < elem->min.z
      	   && ret.pos.y > elem->min.y) || elem->min.x == 0)
      	{
	  ret.fig = elem;
	  ret.t = t;
	  ret.col = elem->rgb;
	}
      return (ret);
    }
  return (ret);
}
