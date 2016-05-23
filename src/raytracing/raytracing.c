/*
** raytracing.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed May  4 17:09:30 2016 Iulian Rotaru
** Last update Sun May 22 22:20:40 2016 Alif Matthias
*/

#include "rt.h"

static void		pls_draw(t_thd *data, t_vec *up_pos)
{
  t_bunny_position	blit;
  unsigned int		line[1400];

  blit.y = data->limits[0] - 1;
  while (data && data->data
	 && data->data->pix && ++blit.y <= data->limits[1])
    {
      blit.x = -1;
      while (data && data->data && data->data->pix
	     && ++blit.x < data->data->pix[1]->clipable.buffer.width)
	line[blit.x] = alif(&blit, data, up_pos);
      blit.x = -1;
      while (data && data->data && data->data->pix
	     && ++blit.x < data->data->pix[1]->clipable.buffer.width)
	((unsigned int *)(*(data->data->pix + 1))->pixels)
	  [blit.y * data->data->pix[1]->clipable.buffer.width + blit.x]
	  = line[blit.x];
      pthread_mutex_lock(&data->data->lock);
      data->line = 1;
      pthread_mutex_unlock(&data->data->lock);
    }
}

void	*rt_start(void *send)
{
  t_thd	*data;
  t_vec	up_pos;

  up_pos.x = 0;
  up_pos.y = 0;
  up_pos.z = 0;
  data = (t_thd *)send;
  deter_corner(data, &up_pos);
  pls_draw(data, &up_pos);
  pthread_mutex_lock(&data->data->lock);
  data->thread_state = 1;
  pthread_mutex_unlock(&data->data->lock);
  return (NULL);
}
