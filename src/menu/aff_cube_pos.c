/*
** aff_cube_pos.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:05:58 2016
** Last update Sat May 21 23:01:09 2016 
*/

#include "rt.h"

void	aff_cube_pos(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cube_rgb(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cube_refl(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 300;
  text->police_size = 21;
  my_blitstr("refl:", *data->pix, data->font, text);
  text->pos.y = 305;
  text->police_size = 14;
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->refl ? nbr(data->edit.buffer)
	     : fig->refl, *data->pix, data->font, text);
}

void	aff_cube_alpha(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cube_shine(t_data *data, t_text *text, t_fig *fig)
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
