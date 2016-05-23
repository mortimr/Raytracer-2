/*
** plan.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue May  3 16:00:38 2016 Iulian Rotaru
** Last update Sun May 22 22:23:43 2016 
*/

#include "rt.h"

static int	plane_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: plane element with wrong parameters\n", 43);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [plane]                                 -\n", 44);
  write(2, "> name=\"x\"string\"                         -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> rot=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> min=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> max=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> nvec=\"x\",\"y\",\"z\"                        -\n", 44);
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

static int	check_plane(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "alpha", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "shine", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "refl", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "nvec", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "nvec", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "nvec", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 2)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static int	plane_if_two(t_bunny_ini_scope *scope)
{
  if (!bunny_ini_scope_get_field(scope, "rot", 0)
      || !bunny_ini_scope_get_field(scope, "rot", 1)
      || !bunny_ini_scope_get_field(scope, "rot", 2)
      || !bunny_ini_scope_get_field(scope, "dvec", 0)
      || !bunny_ini_scope_get_field(scope, "dvec", 1)
      || !bunny_ini_scope_get_field(scope, "dvec", 2)
      || !bunny_ini_scope_get_field(scope, "rgb", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 1)
      || !bunny_ini_scope_get_field(scope, "rgb", 2)
      || !bunny_ini_scope_get_field(scope, "alpha", 0)
      || !bunny_ini_scope_get_field(scope, "shine", 0)
      || !bunny_ini_scope_get_field(scope, "refl", 0)
      || check_plane(scope) == EXIT_FAILURE)
    return (plane_man());
  return (GO_ON);
}

static int	plane_if(t_bunny_ini_scope *scope)
{
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "name", 0)
      || !bunny_ini_scope_get_field(scope, "nvec", 0)
      || !bunny_ini_scope_get_field(scope, "nvec", 1)
      || !bunny_ini_scope_get_field(scope, "nvec", 2)
      || !bunny_ini_scope_get_field(scope, "min", 0)
      || !bunny_ini_scope_get_field(scope, "min", 1)
      || !bunny_ini_scope_get_field(scope, "min", 2)
      || !bunny_ini_scope_get_field(scope, "max", 0)
      || !bunny_ini_scope_get_field(scope, "max", 1)
      || !bunny_ini_scope_get_field(scope, "max", 2))
    return (plane_man());
  return (plane_if_two(scope));
}

int	load_plane(t_bunny_ini_scope *scope, t_data *data)
{
  t_fig	*new;

  if (!scope || !data || plane_if(scope) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (!(new = callo_c(sizeof(t_fig))))
    return (EXIT_FAILURE);
  if (fill_plane(new, scope) == EXIT_FAILURE)
    return (plane_man());
  place_new(data, new);
  return (GO_ON);
}
