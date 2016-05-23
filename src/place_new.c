/*
** place_new.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue May  3 15:32:06 2016 Iulian Rotaru
** Last update Sun May 22 21:58:42 2016 
*/

#include "rt.h"

void	place_new(t_data *data, t_fig *new)
{
  t_fig	*tmp;
  int	idx;

  tmp = data->fig;
  if (!tmp)
    {
      data->fig = new;
      data->fig->idx = 0;
      data->fig_nb += 1;
      return ;
    }
  idx = tmp->idx;
  while (tmp->next)
    {
      idx = tmp->idx;
      tmp = tmp->next;
    }
  tmp->next = new;
  tmp->next->idx = idx + 1;
  data->fig_nb += 1;
}

void	place_new_light(t_data *data, t_fig *new)
{
  t_fig	*tmp;
  int	idx;

  tmp = data->lights;
  if (!tmp)
    {
      data->lights = new;
      data->lights->idx = 0;
      data->fig_nb += 1;
      return ;
    }
  idx = tmp->idx;
  while (tmp->next)
    {
      idx = tmp->idx;
      tmp = tmp->next;
    }
  tmp->next = new;
  tmp->next->idx = idx + 1;
  data->fig_nb += 1;
}
