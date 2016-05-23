/*
** fig_hub.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Apr 27 16:36:08 2016 Iulian Rotaru
** Last update Sun May 22 22:42:56 2016 Alif Matthias
*/

#include "rt.h"

static const t_fct	g_obj[] =
  {
    {"eye", load_eye},
    {"sphere", load_sphere},
    {"plane", load_plane},
    {"cone", load_cone},
    {"cylindre", load_cylindre},
    {"light", load_light},
    {"cube", load_cube},
    {0, 0}
  };

int		load_obj_hub(t_bunny_ini_scope *scope, t_data *data)
{
  int		i;
  const char	*scope_name;

  i = -1;
  if (!scope || !data)
    return (EXIT_FAILURE);
  if (!(scope_name = bunny_ini_scope_name(data->ini, scope)))
    return (EXIT_FAILURE);
  while (++i < FIG_NB + 1)
    if ((!my_strcmp_start((*(g_obj + i)).name, scope_name))
	&& ((*(g_obj + i)).fct(scope, data) == EXIT_FAILURE))
      return (EXIT_FAILURE);
  return (GO_ON);
}
