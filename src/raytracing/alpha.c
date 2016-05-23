/*
** alpha.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 14:14:26 2016 Alif Matthias
** Last update Sun May 22 17:48:00 2016 Alif Matthias
*/

#include "rt.h"

void		hamon_cyl(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	eq;
  double	angle_in;
  double	angle_out;

  nor.x = ret->pos.x - ret->fig->pos.x;
  nor.y = ret->pos.y;
  nor.z = ret->pos.z - ret->fig->pos.z;
  angle_in = angle_vec(ray, &nor);
  angle_out = asin((0.5 * sin(angle_in)) / 1.5);
  new->x = ((0.5 / 1.5) * ray->x)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.x;
  new->y = ((0.5 / 1.5) * ray->y)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.y;
  new->z = ((0.5 / 1.5) * ray->z)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.z;
  eq = norm(new);
  new->x /= -eq;
  new->y /= -eq;
  new->z /= -eq;
}

void		hamon_cube(t_vec *new, const t_vec *ray, t_eko *ret)
{
  (void)ret;
  new->x = ray->x;
  new->y = ray->y;
  new->z = ray->z;
}

void		hamon_sphere(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	eq;
  double	angle_in;
  double	angle_out;

  nor.x = ret->pos.x - ret->fig->pos.x;
  nor.y = ret->pos.y - ret->fig->pos.y;
  nor.z = ret->pos.z - ret->fig->pos.z;
  angle_in = angle_vec(ray, &nor);
  angle_out = asin((0.5 * sin(angle_in)) / 1.5);
  new->x = ((0.5 / 1.5) * ray->x)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.x;
  new->y = ((0.5 / 1.5) * ray->y)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.y;
  new->z = ((0.5 / 1.5) * ray->z)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.z;
  eq = norm(new);
  new->x /= - eq;
  new->y /= - eq;
  new->z /= - eq;
}

void		hamon_cone(t_vec *new, const t_vec *ray, t_eko *ret)
{
  t_vec		nor;
  double	eq;
  double	angle_in;
  double	angle_out;

  nor.x = ret->pos.x - ret->fig->pos.x;
  nor.y = ret->pos.y - ret->fig->pos.y;
  nor.z = ret->pos.z - ret->fig->pos.z;
  angle_in = angle_vec(ray, &nor);
  angle_out = asin((0.5 * sin(angle_in)) / 1.5);
  new->x = ((0.5 / 1.5) * ray->x)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.x;
  new->y = ((0.5 / 1.5) * ray->y)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.y;
  new->z = ((0.5 / 1.5) * ray->z)
    - (cos(angle_out) + ((0.5 / 1.5) * scal(&nor, ray))) * nor.z;
  eq = norm(new);
  new->x /= - eq;
  new->y /= - eq;
  new->z /= - eq;
}

void		hamon_plan(t_vec *new, const t_vec *ray, t_eko *ret)
{
  (void)ret;
  new->x = ray->x;
  new->y = ray->y;
  new->z = ray->z;
}
