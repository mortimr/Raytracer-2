/*
** aff_cone_angle.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:17:55 2016
** Last update Sun May 22 22:06:35 2016 
*/

#include "rt.h"

void	aff_cone_angle(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 450;
  text->police_size = 21;
  my_blitstr("angle:", *data->pix, data->font, text);
  text->pos.y = 455;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->angle ? nbr(data->edit.buffer)
	     : fig->angle, *data->pix, data->font, text);
}

void	aff_cone_rot(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 500;
  text->police_size = 21;
  my_blitstr("rot:", *data->pix, data->font, text);
  text->pos.y = 505;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->rot.x ? nbr(data->edit.buffer)
	     : fig->rot.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->rot.y ? nbr(data->edit.buffer)
	     : fig->rot.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->rot.z ? nbr(data->edit.buffer)
	     : fig->rot.z, *data->pix, data->font, text);
}

void	aff_cone_dvec(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 550;
  text->police_size = 21;
  my_blitstr("dvec:", *data->pix, data->font, text);
  text->pos.y = 555;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->dvec.x ? nbr(data->edit.buffer)
	     : fig->dvec.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->dvec.y ? nbr(data->edit.buffer)
	     : fig->dvec.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->dvec.z ? nbr(data->edit.buffer)
	     : fig->dvec.z, *data->pix, data->font, text);
}

void	aff_cone_height(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 600;
  text->police_size = 21;
  my_blitstr("height:", *data->pix, data->font, text);
  text->pos.y = 605;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->height ? nbr(data->edit.buffer)
	     : fig->height, *data->pix, data->font, text);
}

void	aff_cone(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 35;
  text->pos.x = 275 - (len(data->edit.edit == &fig->name ? data->edit.buffer
			   : fig->name) / 2) * 30;
  text->pos.y = 60;
  my_blitstr(data->edit.edit == &fig->name ? data->edit.buffer
	     : fig->name, *data->pix, data->font, text);
  aff_cone_pos(data, text, fig);
  aff_cone_rgb(data, text, fig);
  aff_cone_refl(data, text, fig);
  aff_cone_alpha(data, text, fig);
  aff_cone_angle(data, text, fig);
  aff_cone_rot(data, text, fig);
  aff_cone_dvec(data, text, fig);
  aff_cone_height(data, text, fig);
}
