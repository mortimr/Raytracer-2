/*
** menu_del_edits.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:48:15 2016
** Last update Sun May 22 20:49:32 2016 
*/

#include "rt.h"

void	menu_delete_edits(t_bunny_event_state state,
			  t_bunny_mouse_button butt,
			  t_data *data)
{
  if (data->menu.focus != 1 || !data->menu.fig_focus
      || data->menu.menu_status != 2)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (bunny_get_mouse_position()->x >= 51
	  && bunny_get_mouse_position()->x < 93)
      && (bunny_get_mouse_position()->y >= 51
	  && bunny_get_mouse_position()->y < 93))
    delete_fig(data, data->menu.fig_focus);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (bunny_get_mouse_position()->x >= 458
	  && bunny_get_mouse_position()->x < 500)
      && (bunny_get_mouse_position()->y >= 51
	  && bunny_get_mouse_position()->y < 93))
    data->add = 1;
}

void	create_empty_end(t_fig *tmp, t_data *data, t_fig *new)
{
  while (tmp && tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  if (!data->menu.fig_focus)
    data->menu.fig_focus = new;
  data->fig_nb += 1;
  data->menu.fig_focus = new;
}

void	create_empty_elem(t_data *data)
{
  t_fig	*new;
  t_fig	*tmp;

  if (!(new = bunny_malloc(sizeof(t_fig))))
    return ;
  mset(new, sizeof(t_fig));
  *(new->rgb.argb + 3) = 0xFF;
  new->type = data->add_select + SPHERE;
  if (!(new->name = sdup("def_name")))
    return ;
  tmp = new->type == LIGHT ? data->lights : data->fig;
  if (!tmp)
    {
      if (new->type == LIGHT)
	data->lights = new;
      else
	data->fig = new;
      if (!data->menu.fig_focus)
	data->menu.fig_focus = new;
      data->fig_nb += 1;
      return ;
    }
  create_empty_end(tmp, data, new);
}

void	menu_no_select(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if (data->menu.focus != 1 || data->menu.menu_status != 2)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (bunny_get_mouse_position()->x >= 458
	  && bunny_get_mouse_position()->x < 500)
      && (bunny_get_mouse_position()->y >= 51
	  && bunny_get_mouse_position()->y < 93))
    data->add = 1;
}

void	menu_add_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 551, 651) == OK))
    data->add_select = LIGHT - SPHERE;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 651, 751) == OK))
    data->add_select = CUBE - SPHERE;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(90, 195, 800, 840) == OK))
    {
      create_empty_elem(data);
      data->add = 0;
      data->add_select = 0;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(350, 395, 800, 840) == OK))
    {
      data->add = 0;
      data->add_select = 0;
    }
}
