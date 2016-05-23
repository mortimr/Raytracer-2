/*
** aff_eye_dir.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:02:37 2016
** Last update Sat May 21 23:00:05 2016 
*/

#include "rt.h"

void	aff_eye_dir(t_data *data, t_text *text)
{
  text->pos.x = 60;
  text->pos.y = 250;
  text->police_size = 21;
  my_blitstr("dir:", *data->pix, data->font, text);
  text->pos.y = 255;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &data->eye.dir.x ? nbr(data->edit.buffer)
	     : data->eye.dir.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &data->eye.dir.y ? nbr(data->edit.buffer)
	     : data->eye.dir.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &data->eye.dir.z ? nbr(data->edit.buffer)
	     : data->eye.dir.z, *data->pix, data->font, text);
}

void	aff_eye_obj(t_data *data, t_text *text)
{
  text->police_size = 35;
  text->pos.x = 275 - (3 * 20);
  text->pos.y = 100;
  my_blitstr("Eye", *data->pix, data->font, text);
  text->police_size = 21;
  text->pos.x = 60;
  text->pos.y = 200;
  my_blitstr("pos:", *data->pix, data->font, text);
  text->pos.y = 205;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &data->eye.pos.x ? nbr(data->edit.buffer)
	     : data->eye.pos.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &data->eye.pos.y ? nbr(data->edit.buffer)
	     : data->eye.pos.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &data->eye.pos.z ? nbr(data->edit.buffer)
	     : data->eye.pos.z, *data->pix, data->font, text);
  aff_eye_dir(data, text);
}

void	aff_sphere_pos(t_data *data, t_text *text, t_fig *fig)
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

void	aff_sphere_rgb(t_data *data, t_text *text, t_fig *fig)
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

void	aff_sphere_refl(t_data *data, t_text *text, t_fig *fig)
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
