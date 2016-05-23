/*
** cone.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue May  3 18:54:07 2016 Iulian Rotaru
** Last update Fri May 13 19:56:35 2016 
*/

#include "rt.h"

static int	cone_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: cone element with wrong parameters\n", 42);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [cone]                                  -\n", 44);
  write(2, "> name=\"x\"string\"                         -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> height=\"int\"                            -\n", 44);
  write(2, "> angle=\"int\"                             -\n", 44);
  write(2, "> rot=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> dvec=\"x\",\"y\",\"z\"                        -\n", 44);
  write(2, "> rgb=\"red\",\"green\",\"blue\"                -\n", 44);
  write(2, "> alpha=\"0-100\"                           -\n", 44);
  write(2, "> shine=\"0-100\"                           -\n", 44);
  write(2, "> refl=\"0-100\"                            -\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  putst_err(2, "\033[0m", 0);
  return (EXIT_FAILURE);
}

int	check_cone(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "height", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "angle", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "alpha", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "shine", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "refl", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 2)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static void	fill_cone(t_fig *new, t_bunny_ini_scope *scope)
{
  new->type = CONE;
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
  new->height = nbr(bunny_ini_scope_get_field(scope, "height", 0));
  new->angle = nbr(bunny_ini_scope_get_field(scope, "angle", 0));
  new->next = NULL;
}

int	cone_if(t_bunny_ini_scope *scope)
{
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "name", 0)
      || !bunny_ini_scope_get_field(scope, "height", 0)
      || !bunny_ini_scope_get_field(scope, "angle", 0)
      || !bunny_ini_scope_get_field(scope, "rot", 0)
      || !bunny_ini_scope_get_field(scope, "rot", 1)
      || !bunny_ini_scope_get_field(scope, "rot", 2)
      || !bunny_ini_scope_get_field(scope, "rgb", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 1)
      || !bunny_ini_scope_get_field(scope, "rgb", 2)
      || !bunny_ini_scope_get_field(scope, "alpha", 0)
      || !bunny_ini_scope_get_field(scope, "shine", 0)
      || !bunny_ini_scope_get_field(scope, "refl", 0)
      || !bunny_ini_scope_get_field(scope, "dvec", 0)
      || !bunny_ini_scope_get_field(scope, "dvec", 1)
      || !bunny_ini_scope_get_field(scope, "dvec", 2)
      || check_cone(scope) == EXIT_FAILURE)
    return (cone_man());
  return (GO_ON);
}

int	load_cone(t_bunny_ini_scope *scope, t_data *data)
{
  t_fig	*new;

  if (!scope || !data || cone_if(scope) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (!(new = callo_c(sizeof(t_fig))))
    return (EXIT_FAILURE);
  fill_cone(new, scope);
  place_new(data, new);
  return (GO_ON);
}
