/*
** len_and_stuff.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:31:16 2016
** Last update Sun May 22 21:46:12 2016 
*/

#include "rt.h"

t_bunny_response	raytra_loop(t_data *data)
{
  if (data->thread_nb <= 0)
    data->thread_nb = 1;
  menu_loop(data);
  raytra_passive_mode(data);
  if (raytra_setup_threads(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  raytra_render_on(data);
  return (GO_ON);
}

int	len(const char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int	putst_err(int fd, char *str, int ret)
{
  write(fd, str, len(str));
  return (ret);
}

int	my_strcmp_start(const char *one, const char *two)
{
  int	i;

  i = -1;
  while (*(one + ++i) && *(two + i) && *(one + i) == *(two + i));
  if (!*(one + i))
    return (0);
  return (1);
}

int			load_scene(t_data *data)
{
  t_bunny_ini_scope	*scope;

  if (!data || !data->file_name)
    return (EXIT_FAILURE);
  if (!(data->ini = bunny_load_ini(data->file_name)))
    return (EXIT_FAILURE);
  if (!(scope = bunny_ini_first(data->ini)))
    return (EXIT_FAILURE);
  while ((scope = bunny_ini_next(data->ini, scope)) && scope != LAST_SCOPE)
    if (load_obj_hub(scope, data) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  bunny_delete_ini(data->ini);
  return (GO_ON);
}
