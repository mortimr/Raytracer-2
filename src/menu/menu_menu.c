/*
** menu_menu.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 21:52:56 2016
** Last update Sat May 21 22:54:20 2016 
*/

#include "rt.h"

void		menu_menu(t_data *data)
{
  t_text	text;

  text.police_size = 21;
  text.pos.x = 0;
  text.pos.y = 200;
  text.x = LETTER_X;
  text.y = LETTER_Y;
  text.fg = BLACK;
  if (data->menu.save.on == 0)
    {
      menu_light(data, &text);
      menu_shine(data, &text);
      menu_refl(data, &text);
      menu_alpha(data, &text);
      menu_baw(data, &text);
      menu_blur(data, &text);
      menu_render(data, &text);
      menu_saver(data, &text);
    }
  else
    menu_saver_on(data, &text);
}

void			min_butt(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  text->police_size = 49;
  (*pos).x = 100;
  (*pos).y = 285;
  (*(pos + 1)).x = 65;
  (*(pos + 1)).y = 79;
  make_square(*data->pix, pos, pos + 1, 0xFFBBBBBB);
  text->pos.x = 115;
  text->pos.y = 300;
  my_blitstr("-", *data->pix, data->font, text);
}

void			plus_butt(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  text->police_size = 49;
  (*pos).x = 300;
  (*pos).y = 285;
  (*(pos + 1)).x = 65;
  (*(pos + 1)).y = 79;
  make_square(*data->pix, pos, pos + 1, 0xFFBBBBBB);
  text->pos.x = 315;
  text->pos.y = 300;
  my_blitstr("+", *data->pix, data->font, text);
}

void	menu_threads_butts(t_data *data, t_text *text, t_bunny_position *pos)
{
  make_square(*data->pix, pos, pos + 1, data->thread_changed
	      ? 0xFFFFBBBB
	      : 0xFFBBBBBB);
  data->thread_changed = data->thread_changed > 0
    ? (data->thread_changed - 1)
    : (data->thread_changed);
  my_blitnbr(data->thread_nb, *data->pix, data->font, text);
  plus_butt(data, text);
  min_butt(data, text);
}

void			menu_threads_nb(t_data *data, t_text *text)
{
  t_bunny_position	pos[2];

  text->police_size = 35;
  text->pos.x = 40;
  text->pos.y = 110;
  my_blitstr("Threads number", *data->pix, data->font, text);
  (*pos).x = 200;
  (*pos).y = 285;
  (*(pos + 1)).x = 65;
  (*(pos + 1)).y = 79;
  text->police_size = 49;
  text->pos.x = 215;
  text->pos.y = 300;
  if (data->thread_nb > 10)
    {
      text->pos.x -= 21;
      (*pos).x -= 21;
      (*(pos + 1)).x += 42;
    }
  menu_threads_butts(data, text, pos);
}
