/*
** menu_add.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:51:10 2016
** Last update Sun May 22 21:47:06 2016 
*/

#include "rt.h"

void	menu_add_edits(t_bunny_event_state state,
		       t_bunny_mouse_button butt,
		       t_data *data)
{
  if (data->menu.focus != 1 || data->add != 1)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 151, 251) == OK))
    data->add_select = SPHERE - SPHERE;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 251, 351) == OK))
    data->add_select = PLANE - SPHERE;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 351, 451) == OK))
    data->add_select = CONE - SPHERE;
  if ((state == GO_DOWN && butt == BMB_LEFT)
      && (cl_btw(51, 500, 451, 551) == OK))
    data->add_select = CYLINDRE - SPHERE;
  menu_add_end(state, butt, data);
}

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mouse_button butt,
			      t_data *data)
{
  menu_check(state, butt, data);
  menu_menu_check(state, butt, data);
  menu_menu_check_render(state, butt, data);
  menu_render_butt(state, butt, data);
  menu_obj_focus(state, butt, data);
  menu_eye_edits(state, butt, data);
  menu_sph_edits(state, butt, data);
  menu_cub_edits(state, butt, data);
  menu_cyl_edits(state, butt, data);
  menu_con_edits(state, butt, data);
  menu_plan_edits(state, butt, data);
  menu_lit_edits(state, butt, data);
  menu_delete_edits(state, butt, data);
  menu_add_edits(state, butt, data);
  menu_no_select(state, butt, data);
  return (GO_ON);
}

void	text_end(uint32_t unicode,
		 t_data *data)
{
  if ((data->edit.input_mode == 1 || data->edit.input_mode == 2
       || data->edit.input_mode == 3 || data->edit.input_mode == 4)
      && data->edit.idx < 4096)
    {
      if (unicode >= ' ' && unicode <= '~')
	{
	  *(data->edit.buffer + data->edit.idx) = unicode;
	  ++data->edit.idx;
	}
    }
}

t_bunny_response	text(uint32_t unicode,
			     t_data *data)
{
  if (data->edit.on == 1)
    {
      if (data->edit.input_mode == 0 && data->edit.idx < 11)
	{
	  if (unicode >= '0' && unicode <= '9')
	    {
	      *(data->edit.buffer + data->edit.idx) = unicode;
	      ++data->edit.idx;
	    }
	  if (unicode == '-' && data->edit.idx == 0)
	    {
	      *(data->edit.buffer + data->edit.idx) = unicode;
	      ++data->edit.idx;
	    }
	}
      text_end(unicode, data);
    }
  return (GO_ON);
}

void	dists_init(t_data *data)
{
  int	i;

  i = -1;
  while (++i < Y_MAX * X_MAX)
    data->dists[i] = -1;
}
