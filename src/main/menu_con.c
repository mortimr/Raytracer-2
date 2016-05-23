/*
** menu_con.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:21:59 2016
** Last update Sun May 22 20:23:37 2016 
*/

#include "rt.h"

void	menu_con_mid_end(t_bunny_event_state state,
			 t_bunny_mouse_button butt,
			 t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 405, 446) == OK))
    start_edit(data, 3, &data->menu.fig_focus->shine);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 455, 496) == OK))
    start_edit(data, 2, &data->menu.fig_focus->angle);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 505, 546) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.x);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 505, 546) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 505, 546) == OK))
    start_edit(data, 0, &data->menu.fig_focus->rot.z);
}

void	menu_con_end(t_bunny_event_state state,
		     t_bunny_mouse_button butt,
		     t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.x);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.y);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 555, 596) == OK))
    start_edit(data, 0, &data->menu.fig_focus->dvec.z);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 605, 646) == OK))
    start_edit(data, 2, &data->menu.fig_focus->height);
}

void	menu_con_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if (data->menu.focus != 1 || !data->menu.fig_focus
      || data->menu.fig_focus->type != CONE
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
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 205, 246) == OK))
    start_edit(data, 4, &data->menu.fig_focus->pos.z);
  menu_con_mid(state, butt, data);
  menu_con_mid_end(state, butt, data);
  menu_con_end(state, butt, data);
}

void	menu_plan_one(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 255, 296) == OK))
    start_edit(data, 3, &data->menu.fig_focus->rgb.argb[0]);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 255, 296) == OK))
    start_edit(data, 3, &data->menu.fig_focus->rgb.argb[1]);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(380, 500, 255, 296) == OK))
    start_edit(data, 3, &data->menu.fig_focus->rgb.argb[2]);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 305, 346) == OK))
    start_edit(data, 3, &data->menu.fig_focus->refl);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 355, 396) == OK))
    start_edit(data, 3, &data->menu.fig_focus->alpha);
}

void	menu_plan_two(t_bunny_event_state state,
		      t_bunny_mouse_button butt,
		      t_data *data)
{
  int	i;

  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 405, 446) == OK))
    start_edit(data, 3, &data->menu.fig_focus->shine);
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(60, 120, 450, 475) == OK))
    {
      i = -1;
      while (++i < 3)
	*(data->menu.fig_focus->lim + i) = 0;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(150, 265, 455, 496) == OK))
    {
      *data->menu.fig_focus->lim = 1;
      start_edit(data, 0, &data->menu.fig_focus->min.x);
    }
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(265, 380, 455, 496) == OK))
    {
      *(data->menu.fig_focus->lim + 1) = 1;
      start_edit(data, 0, &data->menu.fig_focus->min.y);
    }
}
