/*
** menu_ch_rend.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:50:26 2016
** Last update Sun May 22 21:48:05 2016 
*/

#include "rt.h"

void	menu_menu_check_render(t_bunny_event_state state,
			       t_bunny_mouse_button butt,
			       t_data *data)
{
  if (data->render_state != 0 || data->menu.menu_status != 0)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(130, 360, 490, 552) == OK))
    data->render_state = 1;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(178, 320, 400, 462) == OK))
    data->menu.save.on = 1;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (data->menu.save.on == 1)
      && (cl_btw(120, 500, 105, 130) == OK))
    start_edit(data, 1, &data->menu.save.name);
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (data->menu.save.on == 1)
      && (cl_btw(40, 145, 250, 290) == OK))
    data->menu.save.mode = 1;
  menu_menu_check_render_end(state, butt, data);
}

void	menu_render_butt(t_bunny_event_state state,
			 t_bunny_mouse_button butt,
			 t_data *data)
{
  if (data->menu.menu_status != 1 || data->render_state != 0)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(100, 165, 285, 285 + 79) == OK))
    {
      data->thread_changed = data->thread_nb > 1 ? 10 : 0;
      data->thread_changed_speed = data->thread_nb > 1 ? 10.0 : 0.0;
      data->thread_nb = data->thread_nb > 1
	? data->thread_nb / 2 : data->thread_nb;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(300, 365, 285, 285 + 79) == OK))
    {
      data->thread_changed = data->thread_nb < 16 ? 10 : 0;
      data->thread_changed_speed = data->thread_nb < 16 ? 10.0 : 0.0;
      data->thread_nb = data->thread_nb < 16
	? data->thread_nb * 2 : data->thread_nb;
    }
}

void	check_idx_obj(t_data *data, int y)
{
  t_fig	*tmp;
  int	i;
  int	selected;

  i = -1;
  selected = (y - 180) / 50;
  if (selected > data->fig_nb - 1)
    return ;
  tmp = data->lights;
  while (++i < data->menu.scroll + selected && tmp)
    tmp = tmp->next;
  --i;
  if (!tmp)
    {
      tmp = data->fig;
      while (++i < data->menu.scroll + selected && tmp)
	tmp = tmp->next;
    }
  data->menu.obj_idx = tmp->idx;
  data->menu.fig_focus = tmp;
}

void	menu_obj_focus(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if (data->menu.menu_status != 2 || data->render_state != 0)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(0, 50, 50, 100) == OK))
    data->menu.focus = 0;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(0, 50, 180, 880) == OK))
    {
      check_idx_obj(data, bunny_get_mouse_position()->y);
      data->menu.focus = 1;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(0, 50, 100, 150) == OK))
    data->menu.scroll = data->menu.scroll > 0
      ? data->menu.scroll - 1 : data->menu.scroll;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(0, 50, (*data->pix)->clipable.buffer.height - 50,
		 (*data->pix)->clipable.buffer.height) == OK))
    data->menu.scroll = data->menu.scroll + 1 < data->fig_nb - 13
      ? data->menu.scroll + 1 : data->menu.scroll;
}

void	menu_eye_edits_end(t_bunny_event_state state,
			   t_bunny_mouse_button butt,
			   t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 255, 296) == OK))
    start_edit(data, 0, &data->eye.dir.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 255, 296) == OK))
    start_edit(data, 0, &data->eye.dir.z);
}
