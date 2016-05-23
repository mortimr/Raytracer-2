/*
** clear.c for RT2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:24:42 2016
** Last update Sun May 22 21:44:20 2016 
*/

#include "rt.h"

void	clear(t_bunny_pixelarray *pix, unsigned int color)
{
  int	i;

  if (!pix)
    return ;
  i = -1;
  while (++i < pix->clipable.clip_width * pix->clipable.clip_height)
    ((unsigned int *)pix->pixels)[i] = color;
}

void	smart_cast(t_bunny_event_state state,
		   t_bunny_keysym sym,
		   t_data *data)
{
  if ((data->edit.on != 0)
      && (state == GO_DOWN && sym == BKS_RETURN))
    {
      if (data->edit.input_mode == 0)
	*((double *)data->edit.edit) = nbr(data->edit.buffer) / 100.0;
      else if (data->edit.input_mode == 1)
	*((char **)data->edit.edit) = sdup(data->edit.buffer);
      else if (data->edit.input_mode == 2)
	*((int *)data->edit.edit) = nbr(data->edit.buffer);
      else if (data->edit.input_mode == 3)
	*((char *)data->edit.edit) = nbr(data->edit.buffer);
      else if (data->edit.input_mode == 4)
	*((double *)data->edit.edit) = nbr(data->edit.buffer);
      mset(&data->edit, sizeof(t_edit));
    }
}

t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    t_data *data)
{
  if (data->render_state == 2)
    return (GO_ON);
  smart_cast(state, sym, data);
  if ((data->edit.on != 0)
      && (state == GO_DOWN && sym == BKS_BACKSPACE)
      && data->edit.idx > 0)
    {
      --data->edit.idx;
      *(data->edit.buffer + data->edit.idx) = 0;
    }
  if (state == GO_DOWN && sym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void	rot_eye(t_eye *eye)
{
  t_vec	rot;

  rot.x = 0;
  rot.y = -1.00;
  rot.z = 0;
  eye->rightvec = cross_product(&eye->dir, &rot);
  eye->upvec = cross_product(&eye->dir, &eye->rightvec);
}

void	calc_dists(t_data *data)
{
  int	i;

  i = -1;
  while (++i < Y_MAX * X_MAX)
    {
      data->dists[i] -= data->blur_dist;
      if (data->dists[i] < 0 && data->dists[i] != -1)
	data->dists[i] = - data->dists[i];
    }
  i = -1;
  data->blur_extremum[1] = data->dists[i + 1];
  while (++i < Y_MAX * X_MAX)
    if (data->dists[i] > data->blur_extremum[1])
      data->blur_extremum[1] = data->dists[i];
  i = -1;
  while (++i < Y_MAX * X_MAX)
    if (data->dists[i] == -1)
      data->dists[i] = data->blur_extremum[1];
  i = -1;
  data->blur_extremum[0] = data->dists[i + 1];
  while (++i < Y_MAX * X_MAX)
    if (data->dists[i] < data->blur_extremum[0])
      data->blur_extremum[0] = data->dists[i];
}
