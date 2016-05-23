/*
** reflects.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 14:03:02 2016 Alif Matthias
** Last update Sun May 22 17:41:18 2016 Alif Matthias
*/

#include "rt.h"

void		blin_plan(t_vec *new, const t_vec *ray, t_eko *ret)
{
  double	eq;
  t_vec		nor;
  double	tmp;

  nor = ret->fig->nvec;
  eq = norm(&nor);
  nor.x /= eq;
  nor.y /= eq;
  nor.z /= eq;
  new->x = ray->x - 2 * (tmp = scal(ray, &nor)) * nor.x;
  new->y = ray->y - 2 * tmp * nor.y;
  new->z = ray->z - 2 * tmp * nor.z;
}

void		blin_cyl(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	eq;

  nor.x = ret->pos.x - ret->fig->pos.x;
  nor.y = ret->pos.y;
  nor.z = ret->pos.z - ret->fig->pos.z;
  new->x = ray->x - 2 * scal(ray, &nor) * nor.x;
  new->y = ray->y - 2 * scal(ray, &nor) * nor.y;
  new->z = ray->z - 2 * scal(ray, &nor) * nor.z;
  eq = norm(new);
  new->x /= eq;
  new->y /= eq;
  new->z /= eq;
}

static void	normalize(t_vec *nor)
{
  double	eq;

  eq = norm(nor);
  nor->x /= eq;
  nor->y /= eq;
  nor->z /= eq;
}

void		blin_cube(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	tmp;

  mset(&nor, sizeof(t_vec));
  if ((ret->pos.x > ret->fig->pos.x - 0.1
       && ret->pos.x < ret->fig->pos.x + 0.1)
      || (ret->pos.x > ret->fig->pos.x + ret->fig->size.x - 0.1
	  && ret->pos.x < ret->fig->pos.x + ret->fig->size.x + 0.1))
    nor.x = 1;
  else if ((ret->pos.y > ret->fig->pos.y - 0.1
	    && ret->pos.y < ret->fig->pos.y + 0.1)
	   || (ret->pos.y > ret->fig->pos.y + ret->fig->size.y - 0.1
	       && ret->pos.y < ret->fig->pos.y + ret->fig->size.y + 0.1))
    nor.y = 1;
  else if ((ret->pos.z > ret->fig->pos.z - 0.1
	    && ret->pos.z < ret->fig->pos.z + 0.1)
	   || (ret->pos.z > ret->fig->pos.z + ret->fig->size.z - 0.1
	       && ret->pos.z < ret->fig->pos.z + ret->fig->size.z + 0.1))
    nor.z = 1;
  normalize(&nor);
  new->x = ray->x - 2 * (tmp = scal(ray, &nor)) * nor.x;
  new->y = ray->y - 2 * tmp * nor.y;
  new->z = ray->z - 2 * tmp * nor.z;
}

void		blin_sphere(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	eq;

  nor.x = ret->pos.x - ret->fig->pos.x;
  nor.y = ret->pos.y - ret->fig->pos.y;
  nor.z = ret->pos.z - ret->fig->pos.z;
  new->x = ray->x - 2 * scal(ray, &nor) * nor.x;
  new->y = ray->y - 2 * scal(ray, &nor) * nor.y;
  new->z = ray->z - 2 * scal(ray, &nor) * nor.z;
  eq = norm(new);
  new->x /= eq;
  new->y /= eq;
  new->z /= eq;
}
