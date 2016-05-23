/*
** utils_ray.c for raytracer in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 16:11:26 2016 Alif Matthias
** Last update Sun May 22 17:45:27 2016 Alif Matthias
*/

#include "rt.h"

double	norm(const t_vec *vec)
{
  return (sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
}

double	scal(const t_vec *vec, const t_vec *other)
{
  return (vec->x * other->x + vec->y * other->y + vec->z * other->z);
}

double	angle_vec(const t_vec *first, const t_vec *other)
{
  return (180 / M_PI * acos((first->x * other->x
			     + first->y * other->y
			     + first->z * other->z)
			    / ((norm(first) * norm(other)))));
}

void	deter_corner(t_thd *data, t_vec *ret)
{
  ret->x = data->data->eye.pos.x
    + (data->data->eye.dir.x * data->data->eye.scr_dist)
    + (data->data->eye.upvec.x * ((*(data->data->pix + 1))
				  ->clipable.buffer.height / 200.0))
    - (data->data->eye.rightvec.x * ((*(data->data->pix + 1))
				     ->clipable.buffer.width / 200.0));
  ret->y = data->data->eye.pos.y
    + (data->data->eye.dir.y * data->data->eye.scr_dist)
    + (data->data->eye.upvec.y * ((*(data->data->pix + 1))
				  ->clipable.buffer.height / 200.0))
    - (data->data->eye.rightvec.y * ((*(data->data->pix + 1))
				     ->clipable.buffer.width / 200.0));
  ret->z = data->data->eye.pos.z
    + (data->data->eye.dir.z * data->data->eye.scr_dist)
    + (data->data->eye.upvec.z * ((*(data->data->pix + 1))
				  ->clipable.buffer.height / 200.0))
    - (data->data->eye.rightvec.z * ((*(data->data->pix + 1))
				     ->clipable.buffer.width / 200.0));
}

t_vec		get_ray(t_bunny_position *blit, t_thd *data, t_vec *up_pos)
{
  t_vec		ray;
  double	nor;

  ray.x = (up_pos->x + (blit->x * (0.01) * data->data->eye.rightvec.x)
	   - (blit->y * (0.01) * data->data->eye.upvec.x))
    - data->data->eye.pos.x;
  ray.y = (up_pos->y + (blit->x * (0.01) * data->data->eye.rightvec.y)
	   - (blit->y * (0.01) * data->data->eye.upvec.y))
    - data->data->eye.pos.y;
  ray.z = (up_pos->z + (blit->x * (0.01) * data->data->eye.rightvec.z)
	   - (blit->y * (0.01) * data->data->eye.upvec.z))
    - data->data->eye.pos.z;
  nor = norm(&ray);
  ray.x /= nor;
  ray.y /= nor;
  ray.z /= nor;
  return (ray);
}
