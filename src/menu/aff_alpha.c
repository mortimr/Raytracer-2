/*
** aff_sphere_alpha.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:04:23 2016
** Last update Sat May 21 22:05:09 2016 
*/

#include "rt.h"

void	aff_sphere_alpha(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 350;
  text->police_size = 21;
  my_blitstr("alpha:", *data->pix, data->font, text);
  text->pos.y = 355;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->alpha ? nbr(data->edit.buffer)
	     : fig->alpha, *data->pix, data->font, text);
}

void	aff_sphere_shine(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 400;
  text->police_size = 21;
  my_blitstr("shine:", *data->pix, data->font, text);
  text->pos.y = 405;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->shine ? nbr(data->edit.buffer)
	     : fig->shine, *data->pix, data->font, text);
}

void	aff_sphere_radius(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 450;
  text->police_size = 21;
  my_blitstr("radius:", *data->pix, data->font, text);
  text->pos.y = 455;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->radius ? nbr(data->edit.buffer)
	     : fig->radius, *data->pix, data->font, text);
}

void	aff_sphere_limit(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 500;
  text->police_size = 21;
  my_blitstr("limit:", *data->pix, data->font, text);
  text->pos.y = 505;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == fig->lim ? nbr(data->edit.buffer)
	     : *fig->lim, *data->pix, data->font, text);
}

void	aff_sphere(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 35;
  text->pos.x = 275 - (len(data->edit.edit == &fig->name
			   ? data->edit.buffer : fig->name) / 2) * 30;
  text->pos.y = 60;
  my_blitstr(data->edit.edit == &fig->name ? data->edit.buffer
	     : fig->name, *data->pix, data->font, text);
  aff_sphere_pos(data, text, fig);
  aff_sphere_rgb(data, text, fig);
  aff_sphere_refl(data, text, fig);
  aff_sphere_alpha(data, text, fig);
  aff_sphere_shine(data, text, fig);
  aff_sphere_radius(data, text, fig);
  aff_sphere_limit(data, text, fig);
}
