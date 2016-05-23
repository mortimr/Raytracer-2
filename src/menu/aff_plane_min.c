/*
** aff_plane_min.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:22:06 2016
** Last update Sat May 21 22:22:59 2016 
*/

#include "rt.h"

void	aff_plane_min(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 450;
  text->police_size = 21;
  text->fg = *fig->lim == 0 && *(fig->lim + 1) == 0
    && *(fig->lim + 2) == 0 ? BLACK : GREEN;
  my_blitstr("min:", *data->pix, data->font, text);
  text->fg = BLACK;
  text->pos.y = 455;
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

void	aff_plane_max(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 500;
  text->police_size = 21;
  text->fg = *(fig->lim + 3) == 0 && *(fig->lim + 4) == 0
    && *(fig->lim + 5) == 0 ? BLACK : GREEN;
  my_blitstr("max:", *data->pix, data->font, text);
  text->fg = BLACK;
  text->pos.y = 505;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->max.x ? nbr(data->edit.buffer)
	     : fig->max.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->max.y ? nbr(data->edit.buffer)
	     : fig->max.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->max.z ? nbr(data->edit.buffer)
	     : fig->max.z, *data->pix, data->font, text);
}

void	aff_plane_rot(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 550;
  text->police_size = 21;
  text->fg = BLACK;
  my_blitstr("rot:", *data->pix, data->font, text);
  text->pos.y = 555;
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

void	aff_plane_dvec(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 600;
  text->police_size = 21;
  my_blitstr("dvec:", *data->pix, data->font, text);
  text->pos.y = 605;
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

void	aff_plane_nvec(t_data *data, t_text *text, t_fig *fig)
{
  text->pos.x = 60;
  text->pos.y = 650;
  text->police_size = 21;
  my_blitstr("nvec:", *data->pix, data->font, text);
  text->pos.y = 655;
  text->police_size = 14;
  text->pos.x = 150;
  my_blitnbr(data->edit.edit == &fig->nvec.x ? nbr(data->edit.buffer)
	     : fig->nvec.x, *data->pix, data->font, text);
  text->pos.x = 265;
  my_blitnbr(data->edit.edit == &fig->nvec.y ? nbr(data->edit.buffer)
	     : fig->nvec.y, *data->pix, data->font, text);
  text->pos.x = 380;
  my_blitnbr(data->edit.edit == &fig->nvec.z ? nbr(data->edit.buffer)
	     : fig->nvec.z, *data->pix, data->font, text);
}
