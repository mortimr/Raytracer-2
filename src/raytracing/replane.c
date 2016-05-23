/*
** replane.c for rt.h in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 18:28:38 2016 Alif Matthias
** Last update Sun May 22 18:35:46 2016 Alif Matthias
*/

#include "rt.h"

static int	fill_plane_max(t_fig *new, t_bunny_ini_scope *scope)
{
  if (cmp("none", bunny_ini_scope_get_field(scope, "max", 0)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "max", 0)) == KO)
	return (EXIT_FAILURE);
      *(new->lim + 3) = 1;
      new->max.x = (double)nbr(bunny_ini_scope_get_field(scope, "max", 0));
    }
  if (cmp("none", bunny_ini_scope_get_field(scope, "max", 1)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "max", 1)) == KO)
	return (EXIT_FAILURE);
      *(new->lim + 4) = 1;
      new->max.y = (double)nbr(bunny_ini_scope_get_field(scope, "max", 1));
    }
  if (cmp("none", bunny_ini_scope_get_field(scope, "max", 2)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "max", 2)) == KO)
	return (EXIT_FAILURE);
      *(new->lim + 5) = 1;
      new->max.z = (double)nbr(bunny_ini_scope_get_field(scope, "max", 2));
    }
  new->next = NULL;
  return (GO_ON);
}

int	fill_plane_min(t_fig *new, t_bunny_ini_scope *scope)
{
  if (cmp("none", bunny_ini_scope_get_field(scope, "min", 0)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "min", 0)) == KO)
	return (EXIT_FAILURE);
      *(new->lim) = 1;
      new->min.x = (double)nbr(bunny_ini_scope_get_field(scope, "min", 0));
    }
  if (cmp("none", bunny_ini_scope_get_field(scope, "min", 1)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "min", 1)) == KO)
	return (EXIT_FAILURE);
      *(new->lim + 1) = 1;
      new->min.y = (double)nbr(bunny_ini_scope_get_field(scope, "min", 1));
    }
  if (cmp("none", bunny_ini_scope_get_field(scope, "min", 2)) == KO)
    {
      if (isnum(bunny_ini_scope_get_field(scope, "min", 2)) == KO)
	return (EXIT_FAILURE);
      *(new->lim + 2) = 1;
      new->min.z = (double)nbr(bunny_ini_scope_get_field(scope, "min", 2));
    }
  return (fill_plane_max(new, scope));
}

int	fill_plane(t_fig *new, t_bunny_ini_scope *scope)
{
  new->type = PLANE;
  new->name = sdup(bunny_ini_scope_get_field(scope, "name", 0));
  new->pos.x = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 0));
  new->pos.y = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 1));
  new->pos.z = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 2));
  *new->rgb.argb = nbr(bunny_ini_scope_get_field(scope, "rgb", 0));
  *(new->rgb.argb + 1) = nbr(bunny_ini_scope_get_field(scope, "rgb", 1));
  *(new->rgb.argb + 2) = nbr(bunny_ini_scope_get_field(scope, "rgb", 2));
  *(new->rgb.argb + 3) = 0xFF;
  new->alpha = nbr(bunny_ini_scope_get_field(scope, "alpha", 0));
  new->shine = nbr(bunny_ini_scope_get_field(scope, "shine", 0));
  new->refl = nbr(bunny_ini_scope_get_field(scope, "refl", 0));
  new->rot.x = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 0)) / 100.0;
  new->rot.y = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 1)) / 100.0;
  new->rot.z = (double)nbr(bunny_ini_scope_get_field(scope, "rot", 2)) / 100.0;
  new->dvec.x = (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 0)) / 100.0;
  new->dvec.y = (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 1)) / 100.0;
  new->dvec.z = (double)nbr(bunny_ini_scope_get_field(scope, "dvec", 2)) / 100.0;
  new->nvec.x = (double)nbr(bunny_ini_scope_get_field(scope, "nvec", 0)) / 100.0;
  new->nvec.y = (double)nbr(bunny_ini_scope_get_field(scope, "nvec", 1)) / 100.0;
  new->nvec.z = (double)nbr(bunny_ini_scope_get_field(scope, "nvec", 2)) / 100.0;
  return (fill_plane_min(new, scope));
}
