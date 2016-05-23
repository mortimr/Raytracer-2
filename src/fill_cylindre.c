/*
** fill_cylindre.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 18:17:15 2016 Alif Matthias
** Last update Sun May 22 18:17:50 2016 Alif Matthias
*/

#include "rt.h"

static void	fill_other_cyl(t_fig *new, t_bunny_ini_scope *scope)
{
  *new->rgb.argb = nbr(bunny_ini_scope_get_field(scope, "rgb", 0));
  *(new->rgb.argb + 1) = nbr(bunny_ini_scope_get_field(scope, "rgb", 1));
  *(new->rgb.argb + 2) = nbr(bunny_ini_scope_get_field(scope, "rgb", 2));
  *(new->rgb.argb + 3) = 0xFF;
  new->alpha = nbr(bunny_ini_scope_get_field(scope, "alpha", 0));
  new->shine = nbr(bunny_ini_scope_get_field(scope, "shine", 0));
  new->refl = nbr(bunny_ini_scope_get_field(scope, "refl", 0));
  new->next = NULL;
}

void	fill_cylindre(t_fig *new, t_bunny_ini_scope *scope)
{
  new->type = CYLINDRE;
  new->name = sdup(bunny_ini_scope_get_field(scope, "name", 0));
  new->min.x = (double)nbr(bunny_ini_scope_get_field(scope, "limit", 0));
  new->min.y = (double)nbr(bunny_ini_scope_get_field(scope, "limit", 1));
  new->min.z = (double)nbr(bunny_ini_scope_get_field(scope, "limit", 2));
  new->dvec.x =
    (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 0)) / 100.0;
  new->dvec.y =
    (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 1)) / 100.0;
  new->dvec.z =
    (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 2)) / 100.0;
  new->pos.x = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 0));
  new->pos.y = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 1));
  new->pos.z = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 2));
  new->rot.x = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 0)) / 100.0;
  new->rot.y = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 1)) / 100.0;
  new->rot.z = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 2)) / 100.0;
  new->radius = (double)nbr(bunny_ini_scope_get_field(scope, "radius", 0));
  fill_other_cyl(new, scope);
}
