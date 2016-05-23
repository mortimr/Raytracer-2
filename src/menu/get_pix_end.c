/*
** get_pix_end.c for RTV2 in /home/rotaru_i/gfx_raytracer2
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat May 21 22:00:46 2016
** Last update Sun May 22 22:49:27 2016 Alif Matthias
*/

#include "rt.h"

t_bunny_pixelarray	*get_pix_end(t_data *data, t_fig *fig)
{
  if (fig->type == 45)
    return (*(data->menu.butts + 6));
  if (fig->type == 46)
    return (*(data->menu.butts + 7));
  if (fig->type == 47)
    return (*(data->menu.butts + 8));
  return (NULL);
}

t_bunny_pixelarray	*get_pix_obj(t_data *data, t_fig *fig)
{
  if (!data || !fig)
    return (NULL);
  if (fig->type == 42)
    return (*(data->menu.butts + 3));
  if (fig->type == 43)
    return (*(data->menu.butts + 4));
  if (fig->type == 44)
    return (*(data->menu.butts + 5));
  return (get_pix_end(data, fig));
}

void			aff_one_obj(t_data *data,
				    t_bunny_position *targ,
				    t_fig *fig)
{
  t_bunny_position	pos[2];
  unsigned int		colors[2];

  (*pos).x = targ->x;
  (*pos).y = targ->y;
  (*(pos + 1)).x = 50;
  (*(pos + 1)).y = 50;
  *colors = BLACK;
  *(colors + 1) = data->menu.focus == 1
    ? (data->menu.fig_focus == fig ? 0xFFEEEEEE : 0xFF999999) : 0xFF999999;
  empty_square(*data->pix, pos, colors, data->menu.focus == 1
	       ? (data->menu.fig_focus == fig ? 1 : 0) : 0);
  my_bunny_blit(*data->pix, get_pix_obj(data, fig), pos, 1);
}

void	aff_figs(t_data *data, t_bunny_position *pos, int i, t_fig *tmp)
{
  tmp = data->fig;
  while (tmp && pos->y < (*data->pix)->clipable.buffer.height - 100)
    {
      if (i >= data->menu.scroll)
	{
	  aff_one_obj(data, pos, tmp);
	  pos->y += 50;
	}
      tmp = tmp->next;
      ++i;
    }
}

void			aff_objs(t_data *data)
{
  t_bunny_position	pos;
  int			i;
  t_fig			*tmp;

  pos.x = 0;
  pos.y = 180;
  i = 0;
  tmp = data->lights;
  while (tmp && pos.y < (*data->pix)->clipable.buffer.height - 100)
    {
      if (i >= data->menu.scroll)
	{
	  aff_one_obj(data, &pos, tmp);
	  pos.y += 50;
	}
      tmp = tmp->next;
      ++i;
    }
  aff_figs(data, &pos, i, tmp);
}
