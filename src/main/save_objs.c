/*
** save_objs.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:45:17 2016
** Last update Sun May 22 21:53:13 2016 
*/

#include "rt.h"

static void	(* const g_saver[])(t_bunny_ini *, t_fig *, int) = {
  save_sphere,
  save_plane,
  save_cone,
  save_cylindre,
  save_cylindre,
  save_cube
};

void	save_objs(t_bunny_ini *ini, t_fig *fig)
{
  t_fig	*tmp;
  int	idx;

  tmp = fig;
  idx = 0;
  while (tmp)
    {
      (*(g_saver + tmp->type - SPHERE))(ini, tmp, idx);
      ++idx;
      tmp = tmp->next;
    }
}

void		save_ini(t_data *data, char *file)
{
  t_bunny_ini	*ini;

  if (!(ini = bunny_new_ini()))
    return ;
  save_eye(ini, &data->eye);
  save_lights(ini, data->lights);
  save_objs(ini, data->fig);
  bunny_save_ini(ini, file);
}

void	save_png(t_data *data,
		 t_bunny_pixelarray *pix,
		 int i,
		 t_bunny_position *pos)
{
  if (!(pix =
	bunny_new_pixelarray((*(data->pix + 1))->clipable.buffer.width,
			     (*(data->pix + 1))->clipable.buffer.height)))
    return ;
  if (!(data->menu.save.name = stradd(data->menu.save.name, ".png")))
    return ;
  pos->x = pix->clipable.buffer.width - 156;
  pos->y = pix->clipable.buffer.height - 52;
  my_bunny_blit(*(data->pix + 1), data->signature, pos, 1);
  while (++i < pix->clipable.buffer.width * pix->clipable.buffer.height)
    {
      (*(((t_color *)pix->pixels) + i)).full
	= (*(((t_color *)(*(data->pix + 1))->pixels) + i)).full;
      *((*(((t_color *)pix->pixels) + i)).argb + 3) = 0xFF;
    }
  bunny_save_pixelarray(pix, data->menu.save.name);
  bunny_delete_clipable(&pix->clipable);
}

void			save_file(t_data *data)
{
  t_bunny_pixelarray	*pix;
  int			i;
  t_bunny_position	pos;

  pix = NULL;
  i = -1;
  if (data->menu.save.mode == 0)
    {
      if (!(data->menu.save.name = stradd(data->menu.save.name, ".ini")))
	return ;
      save_ini(data, data->menu.save.name);
    }
  if (data->menu.save.mode == 1)
    save_png(data, pix, i, &pos);
  data->menu.save.on = 0;
}

void	menu_menu_check_render_end(t_bunny_event_state state,
				   t_bunny_mouse_button butt,
				   t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (data->menu.save.on == 1)
      && (cl_btw(350, 455, 250, 290) == OK))
    data->menu.save.mode = 0;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (data->menu.save.on == 1)
      && (cl_btw(40, 145, 800, 840) == OK))
    save_file(data);
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (data->menu.save.on == 1)
      && (cl_btw(350, 455, 800, 840) == OK))
    data->menu.save.on = 0;
}
