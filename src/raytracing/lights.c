/*
** lights.c for raytracer in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sat May 21 18:25:35 2016 Alif Matthias
** Last update Sun May 22 17:23:16 2016 Alif Matthias
*/

#include "rt.h"

void		benard_sphere(t_vec **rays, t_fig *light,
			      t_color *color, const t_fig *actu)
{
  double	angle;
  t_color	light_col;
  t_vec		norm;

  if (light->ambiant != 0)
    {
      light_col.full = light->rgb.full;
      light_col.argb[3] = 0xEE * 0.1;
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  light_col.full = light->rgb.full;
  norm.x = (*(rays + 2))->x - actu->pos.x;
  norm.y = (*(rays + 2))->y - actu->pos.y;
  norm.z = (*(rays + 2))->z - actu->pos.z;
  angle = angle_vec(&norm, *rays);
  if (angle <= 90.0)
    {
      *(light_col.argb + 3) = (sqrt(90) - sqrt(angle)) * 0xEE / sqrt(90);
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  *(light_col.argb + 3) = 0x00;
  color->full = color_mixer(color->full, light_col.full);
}

void		benard_cone(t_vec **rays, t_fig *light,
			    t_color *color, const t_fig *actu)
{
  double	angle;
  t_color	light_col;
  t_vec		norm;

  if (light->ambiant != 0)
    {
      light_col.full = light->rgb.full;
      light_col.argb[3] = 0xEE * 0.1;
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  light_col.full = light->rgb.full;
  norm.x = (*(rays + 2))->x - actu->pos.x;
  norm.y = (*(rays + 2))->y - actu->pos.y;
  norm.z = (*(rays + 2))->z - actu->pos.z;
  angle = angle_vec(&norm, *rays);
  if (angle <= 90.0)
    {
      *(light_col.argb + 3) = (sqrt(90) - sqrt(angle)) * 0xEE / sqrt(90);
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  *(light_col.argb + 3) = 0x00;
  color->full = color_mixer(color->full, light_col.full);
}

void		benard_plan(t_vec **rays, t_fig *light,
			    t_color *color, const t_fig *actu)
{
  double	angle;
  t_color	light_col;
  t_vec		norm;

  if (light->ambiant != 0)
    {
      light_col.full = light->rgb.full;
      light_col.argb[3] = 0xEE * 0.1;
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  light_col.full = light->rgb.full;
  norm = actu->nvec;
  angle = angle_vec(&norm, *rays);
  *(light_col.argb + 3) = (angle <= 90.0
			   ? (sqrt(90) - sqrt(angle)) * 0xEE / sqrt(90)
			   : angle > 90.0 && angle <= 180.0
			   ? (sqrt(90) - sqrt(180 - angle)) * 0xFF / sqrt(90)
			   : 0x00);
  color->full = color_mixer(color->full, light_col.full);
}

void		benard_cyl(t_vec **rays, t_fig *light,
			   t_color *color, const t_fig *actu)
{
  double	angle;
  t_color	light_col;
  t_vec		norm;

  if (light->ambiant == 1)
    {
      light_col.full = light->rgb.full;
      light_col.argb[3] = 0xEE * 0.1;
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  light_col.full = light->rgb.full;
  norm.x = (*(rays + 2))->x - actu->pos.x;
  norm.y = (*(rays + 2))->y - actu->pos.y;
  norm.z = (*(rays + 2))->z - actu->pos.z;
  angle = angle_vec(&norm, *rays);
  if (angle <= 180.0)
    {
      *(light_col.argb + 3) = (sqrt(180) - sqrt(angle)) * 0xEE / sqrt(180);
      color->full = color_mixer(color->full, light_col.full);
      return ;
    }
  *(light_col.argb + 3) = 0x00;
  color->full = color_mixer(color->full, light_col.full);
}

void		benard_cube(t_vec **rays, t_fig *light,
			    t_color *color, const t_fig *actu)
{
  t_color	light_col;

  (void)rays;
  (void)actu;
  light_col.full = light->rgb.full;
  if (light->ambiant == 1)
    {
      light_col.argb[3] = 0xEE * 0.1;
      color->full = color_mixer(color->full, light_col.full);
    }
}
