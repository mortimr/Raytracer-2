/*
** sphere.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Apr 27 17:33:20 2016 Iulian Rotaru
** Last update Sun May 22 22:13:37 2016 Alif Matthias
*/

#include "rt.h"

static int	cylindre_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: cylindre element with wrong parameters\n", 46);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [cylindre]                              -\n", 44);
  write(2, "> name=\"x\"string\"                         -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> rot=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> dvec=\"x\",\"y\",\"z\"                        -\n", 44);
  write(2, "> radius=\"size\"                           -\n", 44);
  write(2, "> rgb=\"red\",\"green\",\"blue\"                -\n", 44);
  write(2, "> alpha=\"0-100\"                           -\n", 44);
  write(2, "> shine=\"0-100\"                           -\n", 44);
  write(2, "> refl=\"0-100\"                            -\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  putst_err(2, "\033[0m", 0);
  return (EXIT_FAILURE);
}

static int	check_cylindre(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "radius", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "limit", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "limit", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "limit", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rot", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dvec", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "alpha", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "shine", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "refl", 0)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static int	load_cyl_next(t_bunny_ini_scope *scope)
{
  if (!bunny_ini_scope_get_field(scope, "limit", 2)
      || !bunny_ini_scope_get_field(scope, "rot", 0)
      || !bunny_ini_scope_get_field(scope, "rot", 1)
      || !bunny_ini_scope_get_field(scope, "rot", 2)
      || !bunny_ini_scope_get_field(scope, "dvec", 0)
      || !bunny_ini_scope_get_field(scope, "dvec", 1)
      || !bunny_ini_scope_get_field(scope, "dvec", 2)
      || !bunny_ini_scope_get_field(scope, "alpha", 0)
      || !bunny_ini_scope_get_field(scope, "shine", 0)
      || !bunny_ini_scope_get_field(scope, "refl", 0))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		load_cylindre(t_bunny_ini_scope *scope, t_data *data)
{
  t_fig		*new;

  if (!scope || !data)
    return (EXIT_FAILURE);
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "radius", 0)
      || !bunny_ini_scope_get_field(scope, "name", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 1)
      || !bunny_ini_scope_get_field(scope, "rgb", 2)
      || !bunny_ini_scope_get_field(scope, "limit", 0)
      || !bunny_ini_scope_get_field(scope, "limit", 1)
      || load_cyl_next(scope)
      || check_cylindre(scope) == EXIT_FAILURE)
    return (cylindre_man());
  if (!(new = callo_c(sizeof(t_fig))))
    return (EXIT_FAILURE);
  fill_cylindre(new, scope);
  place_new(data, new);
  return (GO_ON);
}
