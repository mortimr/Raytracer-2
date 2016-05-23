/*
** plane_sphere.c for raytracer in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 16:27:41 2016 Alif Matthias
** Last update Sun May 22 17:35:27 2016 Alif Matthias
*/

#include "rt.h"

static int	check_dist(const t_vec *ray, int dist, const t_fig *elem)
{
  if (*(elem->lim) == 1 && ray->x * dist < elem->min.x)
    return (0);
  if (*(elem->lim + 1) == 1 && ray->y * dist < elem->min.y)
    return (0);
  if (*(elem->lim + 2) == 1 && ray->z * dist < elem->min.z)
    return (0);
  if (*(elem->lim + 3) == 1 && ray->x * dist > elem->max.x)
    return (0);
  if (*(elem->lim + 4) == 1 && ray->y * dist > elem->max.y)
    return (0);
  if (*(elem->lim + 5) == 1 && ray->z * dist > elem->max.z)
    return (0);
  return (1);
}

t_eko		plane(const t_vec *ray, const t_eye *eye, const t_fig *elem)
{
  double	d;
  t_eko		ret;
  double	t;

  d = - (elem->nvec.x * elem->pos.x
	 + elem->nvec.y * elem->pos.y
	 + elem->nvec.z * elem->pos.z);
  if ((t = -((elem->nvec.x * (eye->pos.x - elem->pos.x)
	      + elem->nvec.y * (eye->pos.y - elem->pos.y)
	      + elem->nvec.z * (eye->pos.z - elem->pos.z) + d)
	     / (elem->nvec.x * ray->x
		+ elem->nvec.y * ray->y
		+ elem->nvec.z * ray->z))) > 0
      && (check_dist(ray, t, elem)) == 1)
    {
      ret.pos.x = eye->pos.x + ray->x * t;
      ret.pos.y = eye->pos.y + ray->y * t;
      ret.pos.z = eye->pos.z + ray->z * t;
      ret.fig = elem;
      ret.col = elem->rgb;
      ret.t = t;
      return (ret);
    }
  ret.t = -1;
  return (ret);
}

static void	polynom(const t_vec *ray, const t_eye *eye,
			const t_fig *elem, t_vec *eq)
{
  eq->x = pow(ray->x, 2) + pow(ray->y, 2) + pow(ray->z, 2);
  eq->y = 2 * (ray->x * (eye->pos.x - elem->pos.x)
	       + ray->y * (eye->pos.y - elem->pos.y)
	       + ray->z * (eye->pos.z - elem->pos.z));
  eq->z = pow(eye->pos.x - elem->pos.x, 2)
    + pow(eye->pos.y - elem->pos.y, 2)
    + pow(eye->pos.z - elem->pos.z, 2)
    - pow(elem->radius, 2);
}

t_eko		dcircle(const t_vec *ray, const t_eye *eye, const t_fig *elem)
{
  t_vec		eq;
  double	delta;
  double	t;
  t_eko		ret;

  ret.t = -1;
  polynom(ray, eye, elem, &eq);
  if ((delta = (pow(eq.y, 2) - 4 * eq.x * eq.z)) > 0)
    {
      t = ((-eq.y - sqrt(delta)) / (2 * eq.x) >
	   (-eq.y + sqrt(delta)) / (2 * eq.x)
	   ? (-eq.y + sqrt(delta)) / (2 * eq.x) :
	   (-eq.y - sqrt(delta)) / (2 * eq.x));
      ret.pos.x = eye->pos.x + ray->x * t;
      ret.pos.y = eye->pos.y + ray->y * t;
      ret.pos.z = eye->pos.z + ray->z * t;
      if ((*elem->lim == 1 && ret.pos.y > elem->pos.y)
	  || (*elem->lim == -1 && ret.pos.y < elem->pos.y))
	return (ret);
      ret.fig = elem;
      ret.col = elem->rgb;
      ret.t = t;
      return (ret);
    }
  return (ret);
}
