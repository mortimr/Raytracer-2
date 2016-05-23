/*
** aff_plane.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:24:09 2016
** Last update Sat May 21 22:59:35 2016 
*/

#include "rt.h"

static void	(* const g_aff_it[])(t_data *, t_text *, t_fig *) = {
  aff_sphere,
  aff_plane,
  aff_cone,
  aff_cylindre,
  aff_light,
  aff_cube
};

void	aff_plane(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 35;
  text->pos.x = 275 - (len(data->edit.edit == &fig->name ? data->edit.buffer
			   : fig->name) / 2) * 30;
  text->pos.y = 60;
  my_blitstr(data->edit.edit == &fig->name ? data->edit.buffer
	     : fig->name, *data->pix, data->font, text);
  aff_plane_pos(data, text, fig);
  aff_plane_rgb(data, text, fig);
  aff_plane_refl(data, text, fig);
  aff_plane_alpha(data, text, fig);
  aff_plane_shine(data, text, fig);
  aff_plane_min(data, text, fig);
  aff_plane_max(data, text, fig);
  aff_plane_rot(data, text, fig);
  aff_plane_dvec(data, text, fig);
  aff_plane_nvec(data, text, fig);
}

void			aff_add(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 458;
  (*pos).y = 51;
  (*(pos + 1)).x = 42;
  (*(pos + 1)).y = 42;
  make_square(*data->pix, pos, pos + 1, GREEN);
  text->police_size = 42;
  text->fg = BLACK;
  text->pos.x = 463;
  text->pos.y = 51;
  my_blitstr("+", *data->pix, data->font, text);
}

void			aff_delete(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 51;
  (*pos).y = 51;
  (*(pos + 1)).x = 42;
  (*(pos + 1)).y = 42;
  make_square(*data->pix, pos, pos + 1, RED);
  text->police_size = 42;
  text->fg = BLACK;
  text->pos.x = 56;
  text->pos.y = 51;
  my_blitstr("X", *data->pix, data->font, text);
}

void	aff_focused(t_data *data, t_text *text)
{
  if (data->menu.focus == 0)
    aff_eye_obj(data, text);
  if (data->menu.focus == 1 && data->menu.fig_focus)
    {
      g_aff_it[data->menu.fig_focus->type - 42]
	(data, text, data->menu.fig_focus);
      aff_delete(data, text);
    }
  if (data->menu.focus == 1)
    aff_add(data, text);
}

void	add_menu_con_cyl(t_data *data, t_text *text)
{
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == CONE ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 351;
  my_blitstr("CONE", *data->pix, data->font, text);
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == CYLINDRE ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 451;
  my_blitstr("CYLINDRE", *data->pix, data->font, text);
}
