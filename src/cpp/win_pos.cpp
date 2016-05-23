//
// win_pos.cpp for raytra in /home/rotaru_i/Coding/LibLap/tests
//
// Made by Iulian Rotaru
// Login   <rotaru_i@epitech.net>
//
// Started on  Tue Apr 26 15:31:15 2016 Iulian Rotaru
// Last update Sun May 22 22:00:35 2016 
//

#include <lapin_private.h>
#include <lapin.h>
#include "Vector2.hpp"

extern "C" void			my_set_win_position(const t_bunny_window *_win,
						    const t_bunny_position *_pos)
{
  const struct bunny_window	*win;

  win = (const struct bunny_window *)_win;
  win->window->setPosition(sf::Vector2i(_pos->x, _pos->y));
}
