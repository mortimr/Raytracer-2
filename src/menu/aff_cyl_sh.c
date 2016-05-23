/*
** aff_cylindre_shine.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:13:58 2016
** Last update Sat May 21 22:14:50 2016 
*/

#include "rt.h"

void	aff_cylindre_shine(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cylindre_radius(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cylindre_rot(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cylindre_dvec(t_data *data, t_text *text, t_fig *fig)
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

void	aff_cylindre_lim(t_data *data, t_text *text, t_fig *fig)
{
  text->police_size = 21;
  text->pos.x = 60;
  text->pos.y = 600;
  my_blitstr("lim:", *data->pix, data->font, text);
  text->pos.y = 605;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->min.x ? nbr(data->edit.buffer)
	     : fig->min.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->min.y ? nbr(data->edit.buffer)
	     : fig->min.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->min.z ? nbr(data->edit.buffer)
	     : fig->min.z, *data->pix, data->font, text);
}
