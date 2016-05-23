/*
** menu.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu May  5 19:45:32 2016 Iulian Rotaru
** Last update Sat May 21 22:30:57 2016 
*/

#include "rt.h"

static void	(* const g_menu_fct[])(t_data *data) = {
  menu_menu,
  menu_threads,
  menu_obj
};

void	*menu_loop(t_data *data)
{
  if (data->first_call == 0)
    fade_away(data);
  fill(*(data->pix), 0x33EEEEEE);
  (*(g_menu_fct + data->menu.menu_status))(data);
  render_animation_left(data);
  render_animation_right(data);
  render_animation_down(data);
  bunny_blit(&((*(data->win))->buffer), &(*(data->pix))->clipable, NULL);
  bunny_blit(&((*(data->win))->buffer),
	     &(*(data->menu_tabs + data->menu.menu_status))->clipable, NULL);
  bunny_display(*(data->win));
  return (NULL);
}
