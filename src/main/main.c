/*
** main.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue Apr 26 20:59:46 2016 Iulian Rotaru
** Last update Sun May 22 21:46:45 2016 
*/

#include "rt.h"

void		end_process(t_data *data)
{
  int		i;
  void		**ret;
  t_text	warning;

  i = -1;
  ret = NULL;
  while ((++i < data->thread_nb) && data->threads
	 && ((data->threads + i) != NULL))
    {
      warning.pos.x = 388;
      warning.pos.y = 460;
      warning.x = 5;
      warning.y = 7;
      warning.fg = rand() | BLACK;
      warning.police_size = 56;
      my_blitstr("PLEASE WAIT !", *(data->pix + 1), data->font, &warning);
      bunny_blit(&(*(data->win + 1))->buffer, &(*(data->pix + 1))->clipable, NULL);
      bunny_display(*(data->win + 1));
      pthread_join(data->threads[i].thread, ret);
    }
}

int		main(int argc, char **argv)
{
  t_data	data;

  bunny_set_memory_check(true);
  bunny_set_maximum_ram(100000000);
  if (start_checks(&data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (((*(data.pix + 1))->clipable.buffer.width != 1400)
      || ((*(data.pix + 1))->clipable.buffer.height != 976)
      || ((*(data.pix))->clipable.buffer.width != 500)
      || ((*(data.pix))->clipable.buffer.height != 976))
    return (putst_err(2, "Please, don't touch my resources...\n",
		      EXIT_FAILURE));
  if (!(data.dists = bunny_malloc(sizeof(int) * (Y_MAX * X_MAX))))
    return (EXIT_FAILURE);
  dists_init(&data);
  main_settup(&data, argv);
  if (functions_setup(&data, argc) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  end_process(&data);
  bunny_delete_clipable(&(*(data.pix))->clipable);
  bunny_delete_clipable(&(*(data.pix + 1))->clipable);
  bunny_stop(*(data.win));
  bunny_stop(*(data.win + 1));
  return (0);
}
