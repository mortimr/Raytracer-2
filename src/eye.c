/*
** eye.c for RTV2 in /home/rotaru_i
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Mon May  9 18:19:54 2016
** Last update Sun May 22 18:06:35 2016 Alif Matthias
*/

#include "rt.h"

static int	eye_man()
{
  putst_err(2, "\033[31;1m", 0);
  write(2, "Error: eye element with wrong parameters\n", 41);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  write(2, "> [eye]                                   -\n", 44);
  write(2, "> pos=\"x\",\"y\",\"z\"                         -\n", 44);
  write(2, "> dir=\"x\",\"y\",\"z\"                         -\n", 44);
  putst_err(2, "\033[33;1m", 0);
  write(2, "-------------------------------------------\n", 44);
  putst_err(2, "\033[0m", 0);
  return (EXIT_FAILURE);
}

int	check_eye(t_bunny_ini_scope *scope)
{
  if (isnum(bunny_ini_scope_get_field(scope, "pos", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "pos", 2)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dir", 0)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dir", 1)) == KO
      || isnum(bunny_ini_scope_get_field(scope, "dir", 2)) == KO)
    return (EXIT_FAILURE);
  return (GO_ON);
}

static void	fill_eye(t_data *data, t_bunny_ini_scope *scope)
{
  data->eye.pos.x = nbr(bunny_ini_scope_get_field(scope, "pos", 0));
  data->eye.pos.y = nbr(bunny_ini_scope_get_field(scope, "pos", 1));
  data->eye.pos.z = nbr(bunny_ini_scope_get_field(scope, "pos", 2));
  data->eye.dir.x = nbr(bunny_ini_scope_get_field(scope, "dir", 0));
  data->eye.dir.y = nbr(bunny_ini_scope_get_field(scope, "dir", 1));
  data->eye.dir.z = nbr(bunny_ini_scope_get_field(scope, "dir", 2));
  data->eye.filled += 1;
}

int	eye_if(t_bunny_ini_scope *scope)
{
  if (!bunny_ini_scope_get_field(scope, "pos", 0)
      || !bunny_ini_scope_get_field(scope, "pos", 1)
      || !bunny_ini_scope_get_field(scope, "pos", 2)
      || !bunny_ini_scope_get_field(scope, "dir", 0)
      || !bunny_ini_scope_get_field(scope, "dir", 1)
      || !bunny_ini_scope_get_field(scope, "dir", 2)
      || check_eye(scope) == EXIT_FAILURE)
    return (eye_man());
  return (GO_ON);
}

int	load_eye(t_bunny_ini_scope *scope, t_data *data)
{
  if (data->eye.filled > 0)
    {
      data->eye.filled += 1;
      return (data->eye.filled == 2 ? putst_err(2, EYE_NEXT, GO_ON) : GO_ON);
    }
  if (!scope || !data || eye_if(scope) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  fill_eye(data, scope);
  return (GO_ON);
}
