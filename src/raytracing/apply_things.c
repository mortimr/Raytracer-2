/*
** apply_things.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 14:27:01 2016 Alif Matthias
** Last update Sun May 22 17:40:50 2016 Alif Matthias
*/

#include "rt.h"

static void	blin_cone(t_vec *new, const t_vec *ray, t_eko *ret)
{
  (void)new;
  (void)ray;
  (void)ret;
}

static void	(* const g_blin[])(t_vec *, const t_vec *, t_eko *) =
{
  blin_sphere,
  blin_plan,
  blin_cone,
  blin_cyl,
  blin_cyl,
  blin_cube
};

static void	(* const g_hamon[])(t_vec *, const t_vec *, t_eko *) =
{
  hamon_sphere,
  hamon_plan,
  hamon_cone,
  hamon_cyl,
  hamon_cyl,
  hamon_cube
};

unsigned int	mid(t_color *col, t_color *add, double coef)
{
  t_color	tmp;

  tmp = *col;
  col->argb[0] = ((double)tmp.argb[0] * coef
		  + (double)add->argb[0] * (1 - coef));
  col->argb[1] = ((double)tmp.argb[1] * coef
		  + (double)add->argb[1] * (1 - coef));
  col->argb[2] = ((double)tmp.argb[2] * coef
		  + (double)add->argb[2] * (1 - coef));
  col->argb[3] = ((double)tmp.argb[3] * coef
		  + (double)add->argb[3] * (1 - coef));
  return (col->full);
}

void		apply_remix(t_eko *pix, t_thd *data, const t_vec *ray)
{
  t_vec		refl;
  t_eye		new;
  t_color	col;

  new.pos = pix->pos;
  g_blin[pix->fig->type - SPHERE](&refl, ray, pix);
  ++data->refl;
  col.full = send_ray(&refl, data, &new, pix->fig);
  pix->col.full = mid(&col, &pix->col, pix->fig->refl / 100.0);
}

void		apply_alpha(t_eko *pix, t_thd *data, const t_vec *ray)
{
  t_vec		refl;
  t_eye		new;
  t_color	col;

  new.pos = pix->pos;
  g_hamon[pix->fig->type - SPHERE](&refl, ray, pix);
  ++data->alpha;
  col.full = send_ray(&refl, data, &new, pix->fig);
  pix->col.full = mid(&col, &pix->col, pix->fig->alpha / 100.0);
}
