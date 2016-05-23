/*
** cube_cone.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 16:38:38 2016 Alif Matthias
** Last update Sun May 22 22:21:09 2016 Alif Matthias
*/

#include "rt.h"

static void	poly(const t_vec *ray, const t_eye *eye,
		     const t_fig *elem, t_vec *eq)
{
  double	angle;

  angle = pow(elem->angle * M_PI / 180, 2);
  eq->x = pow(ray->x, 2) + pow(ray->z, 2) - angle * pow(ray->y, 2);
  eq->y = 2 * ((ray->x * (eye->pos.x - elem->pos.x))
	       + (ray->z * (eye->pos.z - elem->pos.z))
	       - (angle * ray->y * (eye->pos.y - elem->pos.y)));
  eq->z = pow(eye->pos.x - elem->pos.x, 2)
    + pow(eye->pos.z - elem->pos.z, 2)
    - (angle * pow(eye->pos.y - elem->pos.y, 2));
}

t_eko		cone(const t_vec *ray, const t_eye *eye, const t_fig *elem)
{
  t_vec		eq;
  double	t;
  double	delta;
  t_eko		ret;

  poly(ray, eye, elem, &eq);
  ret.t = -1;
  if ((delta = (pow(eq.y, 2) - 4 * eq.x * eq.z)) > 0)
    {
      t = ((-eq.y - sqrt(delta)) / (2 * eq.x)
	   > (-eq.y + sqrt(delta)) / (2 * eq.x)
	   ? (-eq.y + sqrt(delta)) / (2 * eq.x)
	   : (-eq.y - sqrt(delta)) / (2 * eq.x));
      ret.pos.x = eye->pos.x + ray->x * t;
      ret.pos.y = eye->pos.y + ray->y * t;
      ret.pos.z = eye->pos.z + ray->z * t;
      if (ret.pos.y > elem->pos.y)
	return (ret);
      ret.fig = elem;
      ret.col = elem->rgb;
      ret.t = t;
      return (ret);
    }
  return (ret);
}

static void	swap(double *val, double *oth)
{
  double	swp;

  swp = *val;
  *val = *oth;
  *oth = swp;
}

static int	cube_yx(const t_vec *ray, const t_eye *eye,
			const t_fig *elem, t_cub *cub)
{
  cub->ret.fig = elem;
  cub->ret.t = -1;
  cub->tmin = (elem->pos.x - eye->pos.x) / ray->x;
  cub->tmax = (elem->pos.x + elem->size.x - eye->pos.x) / ray->x;
  if (cub->tmin > cub->tmax)
    swap(&cub->tmin, &cub->tmax);
  cub->tymin = (elem->pos.y - eye->pos.y) / ray->y;
  cub->tymax = (elem->pos.y + elem->size.y - eye->pos.y) / ray->y;
  if (cub->tymin > cub->tymax)
    swap(&cub->tymin, &cub->tymax);
  if ((cub->tmin > cub->tymax) || (cub->tymin > cub->tmax))
    return (1);
  if (cub->tymin > cub->tmin)
    cub->tmin = cub->tymin;
  if (cub->tymax < cub->tmax)
    cub->tmax = cub->tymax;
  return (0);
}

t_eko	cube(const t_vec *ray, const t_eye *eye, const t_fig *elem)
{
  t_cub	cub;

  if ((cube_yx(ray, eye, elem, &cub)) != 0)
    return (cub.ret);
  cub.tzmin = (elem->pos.z - eye->pos.z) / ray->z;
  cub.tzmax = (elem->pos.z + elem->size.z - eye->pos.z) / ray->z;
  if (cub.tzmin > cub.tzmax)
    swap(&cub.tzmin, &cub.tzmax);
  if ((cub.tmin > cub.tzmax) || (cub.tzmin > cub.tmax))
    return (cub.ret);
  if (cub.tzmin > cub.tmin)
    cub.tmin = cub.tzmin;
  if (cub.tzmax < cub.tmax)
    cub.tmax = cub.tzmax;
  cub.ret.t = cub.tmin;
  cub.ret.pos.x = eye->pos.x + cub.ret.t * ray->x;
  cub.ret.pos.y = eye->pos.y + cub.ret.t * ray->y;
  cub.ret.pos.z = eye->pos.z + cub.ret.t * ray->z;
  return (cub.ret);
}
