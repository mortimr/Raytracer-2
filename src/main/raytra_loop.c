/*
** raytra_loop.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:28:21 2016
** Last update Sun May 22 21:52:21 2016 
*/

#include "rt.h"

void	raytra_passive_mode(t_data *data)
{
  if (data->render_state == 0)
    {
      bunny_blit(&(*(data->win + 1))->buffer, &(*(data->pix + 1))->clipable, NULL);
      bunny_display(*(data->win + 1));
    }
}

void	setup_t_thd(t_data *data, int i)
{
  (*(data->threads + i)).idx = i;
  (*(data->threads + i)).line = 0;
  (*(data->threads + i)).thread_state = 0;
  (*(data->threads + i)).data = data;
  *((*(data->threads + i)).limits)
    = ((*(data->pix + 1))->clipable.buffer.height
       / data->thread_nb) * i;
  *((*(data->threads + i)).limits + 1)
    = ((*(data->pix + 1))->clipable.buffer.height
       / data->thread_nb) * (i + 1) - 1;
}

int	raytra_setup_threads(t_data *data)
{
  int	i;

  if (data->render_state == 1)
    {
      rot_eye(&data->eye);
      clear(*(data->pix + 1), BLACK);
      if (!(data->threads = bunny_malloc(sizeof(t_thd) * data->thread_nb)))
	return (EXIT_FAILURE);
      i = -1;
      while (++i < data->thread_nb)
	{
	  setup_t_thd(data, i);
	  if (pthread_create(&(*(data->threads + i)).thread,
			     NULL, &rt_start, (data->threads + i)) < 0)
	    return (EXIT_FAILURE);
	}
      data->render_state = 2;
    }
  return (GO_ON);
}

void	check_line_blit(t_data *data)
{
  int	i;
  int	blit;

  blit = 0;
  i = -1;
  while (++i < data->thread_nb)
    {
      if ((*(data->threads + i)).line != 0)
	blit = 1;
      (*(data->threads + i)).line = 0;
    }
  if (blit != 0)
    {
      bunny_blit(&data->win[1]->buffer, &data->pix[1]->clipable, NULL);
      bunny_display(data->win[1]);
    }
}

void	raytra_render_on(t_data *data)
{
  int	i;

  if (data->render_state == 2)
    {
      check_line_blit(data);
      i = -1;
      while (++i < data->thread_nb)
	if ((*(data->threads + i)).thread_state != 1)
	  break ;
      if (i == data->thread_nb)
	{
	  data->render_state = 0;
	  if (data->baw == 1)
	    bentor_white(*(data->pix + 1));
	  bunny_blit(&data->win[1]->buffer, &data->pix[1]->clipable, NULL);
	  bunny_display(data->win[1]);
	  data->threads = NULL;
	  if (data->blur == 1)
	    {
	      calc_dists(data);
	      brunet(*(data->pix + 1), (unsigned int *)data->dists,
		     data->blur_extremum);
	    }
	}
    }
}
