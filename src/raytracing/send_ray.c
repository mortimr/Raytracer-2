/*
** send_ray.c for rtv2 in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 19:32:21 2016 Alif Matthias
** Last update Sun May 22 19:36:05 2016 Alif Matthias
*/

#include "rt.h"

static t_eko	(* const g_fct[])(const t_vec *ray,
				  const t_eye *eye,
				  const t_fig *elem) =
{
  dcircle,
  plane,
  cone,
  cylinder,
  bentor,
  cube
};

static void	(* const g_benard[])(t_vec **, t_fig *,
				     t_color *, const t_fig *) = {
  benard_sphere,
  benard_plan,
  benard_cone,
  benard_cyl,
  mehdi,
  benard_cube
};

static t_eko	check_obj(t_fig *tmp, t_vec *ray, t_eye *eye)
{
  t_vec		rot;
  t_eye		new_eye;
  t_fig		center;

  if (tmp->rot.x != 0 || tmp->rot.y != 0 || tmp->rot.z != 0)
    {
      rot = *ray;
      new_eye = *eye;
      center = *tmp;
      rotaru(&rot, &center);
      return (g_fct[tmp->type - SPHERE](&rot, &new_eye, &center));
    }
  return (g_fct[tmp->type - SPHERE](ray, eye, tmp));
}

static void	shadow(t_vec *light_ray, t_eko *all,
		       t_fig *tmp[2], t_color *end)
{
  t_vec		*send[3];

  *send = light_ray;
  *(send + 1) = NULL;
  *(send + 2) = &all->pos;
  if (!*(tmp + 1) || (*tmp)->ambiant != 0)
    (*(g_benard + all->fig->type - SPHERE))(send, *tmp, end, all->fig);
}

unsigned int	apply_light(t_eko *all, t_thd *data)
{
  t_vec		light_ray;
  t_fig		*tmp[2];
  t_eye		new;
  t_eko		ret;
  t_color	end;

  *tmp = data->data->lights;
  end.full = all->fig->rgb.full;
  while (*tmp)
    {
      light_ray = diff(&((*tmp)->pos), &all->pos);
      new.pos = all->pos;
      *(tmp + 1) = data->data->fig;
      while (*(tmp + 1))
	{
	  if (*(tmp + 1) != all->fig
	      && ((ret = check_obj(*(tmp + 1), &light_ray, &new)).t > 0.0
		  && ret.t <= 1.0))
	    break ;
	  *(tmp + 1) = (*(tmp + 1))->next;
	}
      shadow(&light_ray, all, tmp, &end);
      *tmp = (*tmp)->next;
    }
  return (end.full);
}

t_eko	send_rotaray(const t_vec *ray, t_fig *tmp, t_eye *eye)
{
  t_vec		rot;
  t_eye		new_eye;
  t_fig		center;

  rot = *ray;
  new_eye = *eye;
  center = *tmp;
  rotaru(&rot, &center);
  return (g_fct[center.type - SPHERE](&rot, &new_eye, &center));
}

unsigned int	send_ray(const t_vec *ray, t_thd *data,
			 t_eye *eye, const t_fig *actu)
{
  t_eg		all;

  mset(&all, sizeof(t_eg));
  all.tmp = data->data->fig;
  while (all.tmp)
    {
      if (all.tmp->rot.x != 0 || all.tmp->rot.y != 0 || all.tmp->rot.z != 0)
	{
	  all.rot = *ray;
	  all.new_eye = *eye;
	  all.center = *all.tmp;
	  rotaru(&all.rot, &all.center);
	  if (((all.cmp = g_fct[all.tmp->type - SPHERE]
		(&all.rot, &all.new_eye, &all.center)).t < all.ret.t
	       || all.ret.t == 0.0) && all.cmp.t > 0.0)
	    all.ret = all.cmp;
	}
      else if (((all.cmp = g_fct[all.tmp->type - SPHERE](ray, eye, all.tmp)).t
		< all.ret.t || all.ret.t == 0.0)
	       && all.cmp.t > 1.0 && all.tmp != actu)
	all.ret = all.cmp;
      all.tmp = all.tmp->next;
    }
  return (end_ray(&all.ret, data, ray));
}
