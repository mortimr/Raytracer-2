/*
** sphere.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Apr 27 17:33:20 2016 Iulian Rotaru
** Last update Mon May 23 11:49:51 2016 
*/

#include "rt.h"

static int	sphere_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: sphere element with wrong parameters\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [sphere]                                -\n", 44);
  write(2, "> name=\"string\"                           -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> radius=\"size\"                           -\n", 44);
  write(2, "> limit=\"half\"                            -\n", 44);
  write(2, "> rgb=\"red\",\"green\",\"blue\"                -\n", 44);
  write(2, "> alpha=\"0-100\"                           -\n", 44);
  write(2, "> shine=\"0-100\"                           -\n", 44);
  write(2, "> refl=\"0-100\"                            -\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  putst_err(2, "\033[0m", 0);
  return (EXIT_FAILURE);
}

static int	check_sphere(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "limit", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "radius", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "alpha", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "shine", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "refl", 0)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static void	fill_sphere(t_fig *new, t_bunny_ini_scope *scope)
{
  new->type = SPHERE;
  *new->lim = nbr(bunny_ini_scope_get_field(scope, "limit", 0));
  new->name = sdup(bunny_ini_scope_get_field(scope, "name", 0));
  new->pos.x = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 0));
  new->pos.y = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 1));
  new->pos.z = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 2));
  new->radius = (double)nbr(bunny_ini_scope_get_field(scope, "radius", 0));
  *new->rgb.argb = nbr(bunny_ini_scope_get_field(scope, "rgb", 0));
  *(new->rgb.argb + 1) = nbr(bunny_ini_scope_get_field(scope, "rgb", 1));
  *(new->rgb.argb + 2) = nbr(bunny_ini_scope_get_field(scope, "rgb", 2));
  *(new->rgb.argb + 3) = 0xFF;
  new->alpha = nbr(bunny_ini_scope_get_field(scope, "alpha", 0));
  new->shine = nbr(bunny_ini_scope_get_field(scope, "shine", 0));
  new->refl = nbr(bunny_ini_scope_get_field(scope, "refl", 0));
  new->next = NULL;
}

int	load_sphere(t_bunny_ini_scope *scope, t_data *data)
{
  t_fig	*new;

  if (!scope || !data)
    return (EXIT_FAILURE);
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "radius", 0)
      || !bunny_ini_scope_get_field(scope, "limit", 0)
      || !bunny_ini_scope_get_field(scope, "name", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 1)
      || !bunny_ini_scope_get_field(scope, "rgb", 2)
      || !bunny_ini_scope_get_field(scope, "alpha", 0)
      || !bunny_ini_scope_get_field(scope, "shine", 0)
      || !bunny_ini_scope_get_field(scope, "refl", 0)
      || check_sphere(scope) == EXIT_FAILURE)
    return (sphere_man());
  if (!(new = callo_c(sizeof(t_fig))))
    return (EXIT_FAILURE);
  fill_sphere(new, scope);
  place_new(data, new);
  return (GO_ON);
}
