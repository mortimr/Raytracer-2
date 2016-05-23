/*
** add_menu_light_cube.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:28:01 2016
** Last update Sat May 21 23:01:54 2016 
*/

#include "rt.h"

void	add_menu_light_cube(t_data *data, t_text *text)
{
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == LIGHT ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 551;
  my_blitstr("LIGHT", *data->pix, data->font, text);
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == CUBE ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 651;
  my_blitstr("CUBE", *data->pix, data->font, text);
}

void			add_menu_end(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  text->police_size = 42;
  text->fg = GREEN;
  text->pos.x = 55;
  text->pos.y = 151 + data->add_select * 100;
  my_blitstr("->", *data->pix, data->font, text);
  (*pos).x = 90;
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

void	add_menu(t_data *data, t_text *text)
{
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == SPHERE ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 151;
  my_blitstr("SPHERE", *data->pix, data->font, text);
  text->police_size = 42;
  text->fg = data->add_select + SPHERE == PLANE ? GREEN : BLACK;
  text->pos.x = 150;
  text->pos.y = 251;
  my_blitstr("PLANE", *data->pix, data->font, text);
  add_menu_con_cyl(data, text);
  add_menu_light_cube(data, text);
  add_menu_end(data, text);
}

void			menu_obj(t_data *data)
{
  t_text		text;
  t_bunny_position	pos[2];

  text.police_size = 21;
  text.pos.x = 0;
  text.pos.y = 200;
  text.x = LETTER_X;
  text.y = LETTER_Y;
  text.fg = BLACK;
  (*pos).x = 0;
  (*pos).y = 0;
  (*(pos + 1)).x = 50;
  (*(pos + 1)).y = (*data->pix)->clipable.buffer.height;
  make_square(*data->pix, pos, pos + 1, 0xFF999999);
  aff_static_icons(data);
  aff_objs(data);
  if (data->add == 0)
    aff_focused(data, &text);
  else
    add_menu(data, &text);
}

void		fade_away(t_data *data)
{
  t_color	fader;
  int		i;

  fader.full = BLACK;
  bunny_blit(&((*(data->win + 1))->buffer),
	     &(*(data->pix + 1))->clipable, NULL);
  bunny_display(*(data->win + 1));
  i = -1;
  while (++i < 200)
    {
      fader.argb[3] = i / 10;
      fill(*(data->pix), fader.full);
      bunny_blit(&((*(data->win))->buffer), &(*(data->pix))->clipable, NULL);
      bunny_display(*(data->win));
    }
  data->first_call = 1;
}
