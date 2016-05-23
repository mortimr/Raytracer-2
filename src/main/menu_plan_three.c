/*
** menu_plan_three.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:30:18 2016
** Last update Sun May 22 20:31:30 2016 
*/

#include "rt.h"

void	menu_plan_three(t_bunny_event_state state,
			t_bunny_mouse_button butt,
			t_data *data)
{
  int	i;

  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 455, 496) == OK))
    {
      *(data->menu.fig_focus->lim + 2) = 1;
      start_edit(data, 0, &data->menu.fig_focus->min.z);
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(60, 120, 500, 525) == OK))
    {
      i = -1;
      while (++i < 3)
	*(data->menu.fig_focus->lim + i + 3) = 0;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 505, 546) == OK))
    {
      *(data->menu.fig_focus->lim + 3) = 1;
      start_edit(data, 0, &data->menu.fig_focus->max.x);
    }
}

void	menu_plan_four(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 505, 546) == OK))
    {
      *(data->menu.fig_focus->lim + 4) = 1;
      start_edit(data, 0, &data->menu.fig_focus->max.y);
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 505, 546) == OK))
    {
      *(data->menu.fig_focus->lim + 5) = 1;
      start_edit(data, 0, &data->menu.fig_focus->max.z);
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.x);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.z);
}

void	menu_plan_five(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 205, 246) == OK))
    start_edit(data, 4, &data->menu.fig_focus->pos.z);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 605, 646) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.x);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 605, 646) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 605, 646) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.z);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 655, 696) == OK))
    start_edit(data, 0, &data->menu.fig_focus->nvec.x);
}

void	menu_plan_six(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 655, 696) == OK))
    start_edit(data, 0, &data->menu.fig_focus->nvec.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 655, 696) == OK))
    start_edit(data, 0, &data->menu.fig_focus->nvec.z);
}

void	menu_plan_edits(t_bunny_event_state state,
			t_bunny_mouse_button butt,
			t_data *data)
{
  if (data->menu.focus != 1 || !data->menu.fig_focus
      || data->menu.fig_focus->type != PLANE
      || data->menu.menu_status != 2 || data->add == 1)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.fig_focus)
      && (cl_btw(275 - (len(data->menu.fig_focus->name) / 2) * 30,
		 275 + (len(data->menu.fig_focus->name) / 2) * 30,
		 60, 95) == OK))
    start_edit(data, 1, &data->menu.fig_focus->name);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 205, 246) == OK))
    start_edit(data, 4, &data->menu.fig_focus->pos.x);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 205, 246) == OK))
    start_edit(data, 4, &data->menu.fig_focus->pos.y);
  menu_plan_one(state, butt, data);
  menu_plan_two(state, butt, data);
  menu_plan_three(state, butt, data);
  menu_plan_four(state, butt, data);
  menu_plan_five(state, butt, data);
  menu_plan_six(state, butt, data);
}
