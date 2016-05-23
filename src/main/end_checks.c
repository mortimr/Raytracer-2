/*
** end_checks.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 20:54:37 2016
** Last update Sun May 22 21:45:46 2016 
*/

#include "rt.h"

int	end_checks(t_data *data)
{
  if  ((!(*(data->menu.butts + 1)
	  = bunny_load_pixelarray("./res/butt/arrow_up.png")))
       || (!(*(data->menu.butts + 2)
	     = bunny_load_pixelarray("./res/butt/arrow_down.png")))
       || (!(*(data->menu.butts + 3)
	     = bunny_load_pixelarray("./res/butt/sphere.png")))
       || (!(*(data->menu.butts + 4)
	     = bunny_load_pixelarray("./res/butt/plane.png")))
       || (!(*(data->menu.butts + 5)
	     = bunny_load_pixelarray("./res/butt/cone.png")))
       || (!(*(data->menu.butts + 6)
	     = bunny_load_pixelarray("./res/butt/cylinder.png")))
       || (!(*(data->menu.butts + 7)
	     = bunny_load_pixelarray("./res/butt/light.png")))
       || (!(*(data->menu.butts + 8)
	     = bunny_load_pixelarray("./res/butt/cube.png")))
       || (!(data->font = bunny_load_pixelarray("./res/font.png"))))
    return (EXIT_FAILURE);
  return (GO_ON);
}

int	start_checks(t_data *data)
{
  if ((!XInitThreads())
      || (!(*(data->win) = bunny_start(500, 976, 0, "")))
      || (!(*(data->win + 1) = bunny_start_style(1400, 976, 0, "")))
      || (!(*(data->pix + 1) = bunny_load_pixelarray("./res/Render_start.png")))
      || (!(*data->pix = bunny_load_pixelarray("./res/Menu_title.png")))
      || (!(*(data->menu_tabs) = bunny_load_pixelarray("./res/bar1.png")))
      || (!(data->signature = bunny_load_pixelarray("./res/sRTV2.png")))
      || (!(*(data->menu_tabs + 1) = bunny_load_pixelarray("./res/bar2.png")))
      || (!(*(data->menu_tabs + 2) = bunny_load_pixelarray("./res/bar3.png")))
      || (!(*(data->menu_tabs + 2) = bunny_load_pixelarray("./res/bar3.png")))
      || (!(*(data->menu.butts) = bunny_load_pixelarray("./res/butt/eye.png"))))
    return (EXIT_FAILURE);
  return (end_checks(data));
}

void	main_settup_next(t_data *data)
{
  data->light = 0;
  data->refl = 0;
  data->fig_nb = 0;
  data->shine = 0;
  data->alpha = 0;
  data->menu.scroll = 0;
  data->menu.obj_idx = 0;
  data->first_call = 0;
  data->menu.fig_focus = NULL;
  data->menu.focus = 0;
  mset(&data->eye, sizeof(t_eye));
  mset(&data->menu.save, sizeof(t_save));
  data->eye.scr_dist = 18.0;
  data->eye.upvec.y = 1;
  data->aalias = 0;
  data->eye.rightvec.x = 1;
  data->eye.filled = 0;
  data->add = 0;
  data->baw = 0;
  data->add_select = 0;
  data->blur_extremum[0] = 0;
  data->blur_extremum[1] = 0;
  pthread_mutex_init(&data->lock, NULL);
}

void			main_settup(t_data *data, char **argv)
{
  t_bunny_position	pos;

  data->blur = 0;
  data->blur_dist = 0;
  pos.x = 0;
  pos.y = 25;
  my_set_win_position(*(data->win), &pos);
  pos.x = 500;
  pos.y = 25;
  my_set_win_position(*(data->win + 1), &pos);
  mset(&data->edit, sizeof(t_edit));
  data->file_name = *(argv + 1);
  data->render_state = 0;
  data->menu.menu_state = 0;
  data->menu.menu_status = 0;
  data->menu.render_butt.full = 0xFFEEEEEE;
  data->exit = 0;
  data->fig = NULL;
  data->lights = NULL;
  data->threads = NULL;
  data->thread_nb = 2;
  data->thread_changed = 0;
  data->thread_changed_speed = 0;
  main_settup_next(data);
}

int	functions_setup(t_data *data, int argc)
{
  if (!(data->menu.save.name = sdup("file_name")))
    return (EXIT_FAILURE);
  if (argc == 2 && load_scene(data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  threads_animation(NULL, 1);
  bunny_set_click_response((t_bunny_click)click);
  bunny_set_loop_main_function((t_bunny_loop)raytra_loop);
  bunny_set_key_response((t_bunny_key)key);
  bunny_set_text_response((t_bunny_type)text);
  bunny_loop(*data->win, 60, data);
  return (GO_ON);
}
