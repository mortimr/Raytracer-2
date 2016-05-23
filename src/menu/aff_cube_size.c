/*
** aff_cube_size.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:07:58 2016
** Last update Sat May 21 22:08:55 2016 
*/

#include "rt.h"

void	aff_cube_size(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 21;
  text->pos.x = 60;
  text->pos.y = 450;
  my_blitstr("size:", *data->pix, data->font, text);
  text->pos.y = 455;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->size.x ? nbr(data->edit.buffer)
	     : fig->size.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->size.y ? nbr(data->edit.buffer)
	     : fig->size.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->size.z ? nbr(data->edit.buffer)
	     : fig->size.z, *data->pix, data->font, text);
}

void	aff_cube(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 35;
  text->pos.x = 275 - (len(data->edit.edit == &fig->name
			   ? data->edit.buffer : fig->name) / 2) * 30;
  text->pos.y = 60;
  my_blitstr(data->edit.edit == &fig->name ? data->edit.buffer
	     : fig->name, *data->pix, data->font, text);
  aff_cube_pos(data, text, fig);
  aff_cube_rgb(data, text, fig);
  aff_cube_refl(data, text, fig);
  aff_cube_alpha(data, text, fig);
  aff_cube_shine(data, text, fig);
  aff_cube_size(data, text, fig);
}

void	aff_light_pos(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 21;
  text->pos.x = 60;
  text->pos.y = 200;
  my_blitstr("pos:", *data->pix, data->font, text);
  text->pos.y = 205;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->pos.x ? nbr(data->edit.buffer)
	     : fig->pos.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->pos.y ? nbr(data->edit.buffer)
	     : fig->pos.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->pos.z ? nbr(data->edit.buffer)
	     : fig->pos.z, *data->pix, data->font, text);
}

void	aff_light_rgb(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 250;
  text->police_size = 21;
  my_blitstr("rgb:", *data->pix, data->font, text);
  text->pos.y = 255;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->rgb.argb[0] ? nbr(data->edit.buffer)
	     : *fig->rgb.argb, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->rgb.argb[1] ? nbr(data->edit.buffer)
	     : *(fig->rgb.argb + 1), *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->rgb.argb[2] ? nbr(data->edit.buffer)
	     : *(fig->rgb.argb + 2), *data->pix, data->font, text);
}

void	aff_light_ambiant(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 300;
  text->police_size = 21;
  my_blitstr("ambiant:", *data->pix, data->font, text);
  text->pos.y = 305;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->ambiant ? nbr(data->edit.buffer)
	     : fig->ambiant, *data->pix, data->font, text);
}
