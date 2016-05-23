/*
** delete_this_fig.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:43:51 2016
** Last update Sun May 22 20:44:42 2016 
*/

#include "rt.h"

void	delete_this_fig(t_fig *targ, t_fig *old, t_data *data)
{
  if (old == NULL)
    {
      data->lights = targ->next;
      if (data->lights)
	data->menu.fig_focus = data->lights;
      else
	data->menu.fig_focus = data->fig;
      data->fig_nb -= 1;
      return ;
    }
  old->next = targ->next;
  if (old->next == NULL)
    data->menu.fig_focus = data->fig;
  else
    data->menu.fig_focus = old->next;
  data->fig_nb -= 1;
}

void	delete_this_light(t_fig *targ, t_fig *old, t_data *data)
{
  if (old == NULL)
    {
      data->fig = targ->next;
      data->menu.fig_focus = data->fig;
      data->fig_nb -= 1;
      return ;
    }
  old->next = targ->next;
  if (old->next == NULL)
    data->menu.fig_focus = old;
  else
    data->menu.fig_focus = old->next;
  data->fig_nb -= 1;
}

void	delete_this(t_fig *targ, t_fig *old, t_data *data, int mode)
{
  if (mode == 0)
    delete_this_light(targ, old, data);
  else
    delete_this_fig(targ, old, data);
}

void	delete_fig_end(t_data *data, t_fig *fig, t_fig *old, t_fig *tmp)
{
  while (tmp)
    {
      if (fig == tmp)
	{
	  delete_this(fig, old, data, 0);
	  if (data->menu.scroll > 0)
	    --data->menu.scroll;
	  return ;
	}
      old = tmp;
      tmp = tmp->next;
    }
}

void	delete_fig(t_data *data, t_fig *fig)
{
  t_fig	*old;
  t_fig	*tmp;

  old = NULL;
  tmp = data->lights;
  while (tmp)
    {
      if (fig == tmp)
	{
	  delete_this(fig, old, data, 1);
	  if (data->menu.scroll > 0)
	    --data->menu.scroll;
	  return ;
	}
      old = tmp;
      tmp = tmp->next;
    }
  tmp = data->fig;
  old = NULL;
  delete_fig_end(data, fig, old, tmp);
}
