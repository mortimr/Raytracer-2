/*
** menu_check.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:32:54 2016
** Last update Sun May 22 21:48:41 2016 
*/

#include "rt.h"

void	menu_check(t_bunny_event_state state,
		   t_bunny_mouse_button butt,
		   t_data *data)
{
  if (data->render_state != 0)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 0)
      && (cl_btw(4, 156, 14, 42) == OK))
    {
      fill(*(data->pix), 0xFFEEEEEE);
      data->menu.menu_status = 0;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 1)
      && (cl_btw(158, 307, 14, 42) == OK))
    {
      fill(*(data->pix), 0xFFEEEEEE);
      data->menu.menu_status = 1;
    }
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(305, 450, 14, 42) == OK))
    {
      fill(*(data->pix), 0xFFEEEEEE);
      data->menu.menu_status = 2;
    }
}

void	menu_menu_check_end(t_bunny_event_state state,
			    t_bunny_mouse_button butt,
			    t_data *data)
{
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(140, 260, 80, 120) == OK))
    data->aalias = (data->aalias + 1) % 2;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(270, 375, 80, 120) == OK))
    data->refl = (data->refl + 1) % 2;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(385, 490, 80, 120) == OK))
    data->alpha = (data->alpha + 1) % 2;
}

void	menu_menu_check(t_bunny_event_state state,
			t_bunny_mouse_button butt,
			t_data *data)
{
  if (data->menu.menu_status != 0
      || data->render_state != 0 || data->menu.save.on == 1)
    return ;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(10, 130, 80, 120) == OK))
    data->light = (data->light + 1) % 2;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(10, 130, 140, 180) == OK))
    data->baw = (data->baw + 1) % 2;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(140, 260, 140, 180) == OK)
      && data->edit.edit != &data->blur_dist)
    data->blur = (data->blur + 1) % 2;
  if ((state == GO_DOWN && butt == BMB_LEFT && data->menu.menu_status != 2)
      && (cl_btw(280, 500, 150, 170) == OK)
      && data->blur == 1)
    start_edit(data, 2, &data->blur_dist);
  menu_menu_check_end(state, butt, data);
}

char	*stradd(char *one, char *two)
{
  char	*tmp;
  int	i[2];

  if (!(tmp = bunny_malloc(sizeof(char) * (len(one) + len(two) + 1))))
    return (NULL);
  mset(tmp, sizeof(char) * (len(one) + len(two) + 1));
  *i = -1;
  while (*(one + ++*i))
    *(tmp + *i) = *(one + *i);
  *(i + 1) = -1;
  while (*(two + ++*(i + 1)))
    {
      *(tmp + *i) = *(two + *(i + 1));
      ++*i;
    }
  *(tmp + *i) = 0;
  return (tmp);
}

char		*inttostr(int nb)
{
  static char	buff[1024];
  int		i;
  int		len;
  int		tmp;

  i = 0;
  if (nb < 0)
    {
      nb = -nb;
      *buff = '-';
      i = 1;
    }
  tmp = nb;
  len = 1;
  while ((tmp /= 10) > 0)
    ++len;
  *(buff + i + len) = 0;
  while (len > 0)
    {
      *(buff + len + i - 1) = (nb % 10) + '0';
      nb /= 10;
      --len;
    }
  return (buff);
}
