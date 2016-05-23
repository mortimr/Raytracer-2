/*
** menu_render.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:51:17 2016
** Last update Sat May 21 22:53:41 2016 
*/

#include "rt.h"

void			menu_render(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  (*pos).x = 132;
  (*pos).y = 490;
  (*(pos + 1)).x = 230;
  (*(pos + 1)).y = 62;
  text->police_size = 42;
  if (data->render_state != 0)
    make_square(*data->pix, pos, pos + 1, data->menu.render_butt.full);
  text->pos.x = 142;
  text->pos.y = 500;
  my_blitstr("RENDER", *data->pix, data->font, text);
}

void	menu_saver(t_data *data, t_text *text)
{
  text->police_size = 42;
  text->pos.x = 178;
  text->pos.y = 400;
  my_blitstr("SAVE", *data->pix, data->font, text);
}

void	menu_saver_img(t_data *data, t_text *text, t_bunny_position *pos)
{
  (*pos).x = 40;
  (*pos).y = 250;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  if (data->menu.save.mode == 1)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
  text->pos.x = 60;
  text->pos.y = 260;
  my_blitstr("IMG", *data->pix, data->font, text);
  (*pos).x = 350;
  (*pos).y = 250;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  if (data->menu.save.mode == 0)
    make_square(*data->pix, pos, pos + 1, 0xFF21600A);
}

void	menu_saver_ini(t_data *data, t_text *text, t_bunny_position *pos)
{
  text->pos.x = 370;
  text->pos.y = 260;
  my_blitstr("INI", *data->pix, data->font, text);
  (*pos).x = 40;
  (*pos).y = 800;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  make_square(*data->pix, pos, pos + 1, GREEN);
  (*pos).x = 350;
  (*pos).y = 800;
  (*(pos + 1)).x = 105;
  (*(pos + 1)).y = 40;
  make_square(*data->pix, pos, pos + 1, RED);
}

void			menu_saver_on(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  text->police_size = 28;
  text->pos.x = 60;
  text->pos.y = 100;
  my_blitstr("name:", *data->pix, data->font, text);
  text->police_size = 21;
  text->pos.x = 200;
  text->pos.y = 105;
  my_blitstr(data->edit.edit == &data->menu.save.name
	     ? data->edit.buffer
	     : data->menu.save.name, *data->pix, data->font, text);
  menu_saver_img(data, text, pos);
  menu_saver_ini(data, text, pos);
}
