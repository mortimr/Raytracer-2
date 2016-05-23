/*
** sphere.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Apr 27 17:33:20 2016 Iulian Rotaru
** Last update Mon May  9 16:46:40 2016 
*/

#include "rt.h"

static int	light_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: light element with wrong parameters\n", 43);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [light]                                 -\n", 44);
  write(2, "> name=\"x\"string\"                         -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> rgb=\"red\",\"green\",\"blue\"                -\n", 44);
  write(2, "> ambiant=\"0-1\"                           -\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  putst_err(2, "\033[0m", 0);
  return (EXIT_FAILURE);
}

static int	check_light(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "rgb", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "ambiant", 0)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static void	fill_light(t_fig *new, t_bunny_ini_scope *scope)
{
  new->type = LIGHT;
  new->name = sdup(bunny_ini_scope_get_field(scope, "name", 0));
  new->pos.x = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 0));
  new->pos.y = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 1));
  new->pos.z = (double)nbr(bunny_ini_scope_get_field(scope, "pos", 2));
  *new->rgb.argb = nbr(bunny_ini_scope_get_field(scope, "rgb", 0));
  *(new->rgb.argb + 1) = nbr(bunny_ini_scope_get_field(scope, "rgb", 1));
  *(new->rgb.argb + 2) = nbr(bunny_ini_scope_get_field(scope, "rgb", 2));
  new->ambiant = nbr(bunny_ini_scope_get_field(scope, "ambiant", 0));
  new->next = NULL;
}

int	load_light(t_bunny_ini_scope *scope, t_data *data)
{
  t_fig	*new;

  if (!scope || !data)
    return (EXIT_FAILURE);
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "rgb", 0)
      || !bunny_ini_scope_get_field(scope, "name", 0)
      || !bunny_ini_scope_get_field(scope, "rgb", 1)
      || !bunny_ini_scope_get_field(scope, "rgb", 2)
      || !bunny_ini_scope_get_field(scope, "ambiant", 0)
      || check_light(scope) == EXIT_FAILURE)
    return (light_man());
  if (!(new = callo_c(sizeof(t_fig))))
    return (EXIT_FAILURE);
  fill_light(new, scope);
  place_new_light(data, new);
  return (GO_ON);
}
