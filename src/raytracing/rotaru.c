/*
** rotaru.c for rtv2 in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 18:20:43 2016 Alif Matthias
** Last update Sun May 22 17:33:13 2016 Alif Matthias
*/

#include "rt.h"

static void	apply_matrix_x(t_vec *to_edit, const t_vec *edit)
{
  double	angle;
  double	tmp;

  angle = edit->x * M_PI / 180;
  tmp = to_edit->y;
  to_edit->y = to_edit->y * cos(angle) + to_edit->z * (-sin(angle));
  to_edit->z = tmp * sin(angle) + to_edit->z * (cos(angle));
}

static void	apply_matrix_y(t_vec *to_edit, const t_vec *edit)
{
  double	angle;
  double	tmp;

  angle = edit->y * M_PI / 180;
  tmp = to_edit->x;
  to_edit->x = to_edit->x * cos(angle) + to_edit->z * sin(angle);
  to_edit->z = -tmp * sin(angle) + to_edit->z * cos(angle);
}

static void	apply_matrix_z(t_vec *to_edit, const t_vec *edit)
{
  double	angle;
  double	tmp;

  angle = edit->z * M_PI / 180;
  tmp = to_edit->x;
  to_edit->x = to_edit->x * cos(angle) - to_edit->y * sin(angle);
  to_edit->y = tmp * sin(angle) + to_edit->y * (cos(angle));
}

void	rotaru(t_vec *ray, t_fig *tmp)
{
  if (tmp->rot.x != 0)
    apply_matrix_x(ray, &tmp->rot);
  if (tmp->rot.y != 0)
    apply_matrix_y(ray, &tmp->rot);
  if (tmp->rot.z != 0)
    apply_matrix_z(ray, &tmp->rot);
}
