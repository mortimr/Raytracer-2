/*
** save_lights.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:34:25 2016
** Last update Sun May 22 19:35:27 2016 
*/

#include "rt.h"

void	save_lights(t_bunny_ini *ini, t_fig *lights)
{
  t_fig	*tmp;
  int	idx;
  char	*indexer;

  tmp = lights;
  idx = 0;
  while (tmp)
    {
      if (!(indexer = stradd("light_", inttostr(idx))))
	return ;
      bunny_ini_set_field(ini, indexer, "name", 0, indexer);
      bunny_ini_set_field(ini, indexer, "pos", 0, inttostr((int)tmp->pos.x));
      bunny_ini_set_field(ini, indexer, "pos", 1, inttostr((int)tmp->pos.y));
      bunny_ini_set_field(ini, indexer, "pos", 2, inttostr((int)tmp->pos.z));
      bunny_ini_set_field(ini, indexer, "ambiant", 0,
			  inttostr((int)(tmp->ambiant != 0 ? 1 : 0)));
      bunny_ini_set_field(ini, indexer, "rgb", 0,
			  inttostr((int)tmp->rgb.argb[0]));
      bunny_ini_set_field(ini, indexer, "rgb", 1,
			  inttostr((int)tmp->rgb.argb[1]));
      bunny_ini_set_field(ini, indexer, "rgb", 2,
			  inttostr((int)tmp->rgb.argb[2]));
      tmp = tmp->next;
      idx++;
    }
}

void	save_eye(t_bunny_ini *ini, t_eye *eye)
{
  bunny_ini_set_field(ini, "eye", "pos", 0, inttostr((int)eye->pos.x));
  bunny_ini_set_field(ini, "eye", "pos", 1, inttostr((int)eye->pos.y));
  bunny_ini_set_field(ini, "eye", "pos", 2, inttostr((int)eye->pos.z));
  bunny_ini_set_field(ini, "eye", "dir", 0, inttostr((int)eye->dir.x));
  bunny_ini_set_field(ini, "eye", "dir", 1, inttostr((int)eye->dir.y));
  bunny_ini_set_field(ini, "eye", "dir", 2, inttostr((int)eye->dir.z));
}

void	save_sphere(t_bunny_ini *ini, t_fig *fig, int idx)
{
  char	*indexer;

  if (!(indexer = stradd("sphere_", inttostr(idx))))
    return ;
  bunny_ini_set_field(ini, indexer, "name", 0, indexer);
  bunny_ini_set_field(ini, indexer, "limit", 0, inttostr((int)*fig->lim));
  bunny_ini_set_field(ini, indexer, "pos", 0, inttostr((int)fig->pos.x));
  bunny_ini_set_field(ini, indexer, "pos", 1, inttostr((int)fig->pos.y));
  bunny_ini_set_field(ini, indexer, "pos", 2, inttostr((int)fig->pos.z));
  bunny_ini_set_field(ini, indexer, "rgb", 0,
		      inttostr((unsigned char)fig->rgb.argb[0]));
  bunny_ini_set_field(ini, indexer, "rgb", 1,
		      inttostr((unsigned char)fig->rgb.argb[1]));
  bunny_ini_set_field(ini, indexer, "rgb", 2,
		      inttostr((unsigned char)fig->rgb.argb[2]));
  bunny_ini_set_field(ini, indexer, "radius", 0, inttostr((int)fig->radius));
  bunny_ini_set_field(ini, indexer, "alpha", 0, inttostr((int)fig->alpha));
  bunny_ini_set_field(ini, indexer, "refl", 0, inttostr((int)fig->refl));
  bunny_ini_set_field(ini, indexer, "shine", 0, inttostr((int)fig->shine));
}

void	save_cube(t_bunny_ini *ini, t_fig *fig, int idx)
{
  char	*indexer;

  if (!(indexer = stradd("cube_", inttostr(idx))))
    return ;
  bunny_ini_set_field(ini, indexer, "name", 0, indexer);
  bunny_ini_set_field(ini, indexer, "pos", 0, inttostr((int)fig->pos.x));
  bunny_ini_set_field(ini, indexer, "pos", 1, inttostr((int)fig->pos.y));
  bunny_ini_set_field(ini, indexer, "pos", 2, inttostr((int)fig->pos.z));
  bunny_ini_set_field(ini, indexer, "size", 0, inttostr((int)fig->size.x));
  bunny_ini_set_field(ini, indexer, "size", 1, inttostr((int)fig->size.y));
  bunny_ini_set_field(ini, indexer, "size", 2, inttostr((int)fig->size.z));
  bunny_ini_set_field(ini, indexer, "rgb", 0,
		      inttostr((unsigned char)fig->rgb.argb[0]));
  bunny_ini_set_field(ini, indexer, "rgb", 1,
		      inttostr((unsigned char)fig->rgb.argb[1]));
  bunny_ini_set_field(ini, indexer, "rgb", 2,
		      inttostr((unsigned char)fig->rgb.argb[2]));
  bunny_ini_set_field(ini, indexer, "alpha", 0, inttostr((int)fig->alpha));
  bunny_ini_set_field(ini, indexer, "refl", 0, inttostr((int)fig->refl));
  bunny_ini_set_field(ini, indexer, "shine", 0, inttostr((int)fig->shine));
}

void	save_plane_end(t_bunny_ini *ini, t_fig *fig, char *indexer)
{
  bunny_ini_set_field(ini, indexer, "dvec", 0,
		      inttostr((int)(fig->dvec.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 1,
		      inttostr((int)(fig->dvec.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 2,
		      inttostr((int)(fig->dvec.z * 100.0)));
  bunny_ini_set_field(ini, indexer, "nvec", 0,
		      inttostr((int)(fig->nvec.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "nvec", 1,
		      inttostr((int)(fig->nvec.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "nvec", 2,
		      inttostr((int)(fig->nvec.z * 100.0)));
  bunny_ini_set_field(ini, indexer, "min", 0, *fig->lim == 0 ? "none"
		      : inttostr((int)fig->min.x));
  bunny_ini_set_field(ini, indexer, "min", 1, *(fig->lim + 1) == 0 ? "none"
		      : inttostr((int)fig->min.y));
  bunny_ini_set_field(ini, indexer, "min", 2, *(fig->lim + 2) == 0 ? "none"
		      : inttostr((int)fig->min.z));
  bunny_ini_set_field(ini, indexer, "max", 0, *(fig->lim + 3) == 0 ? "none"
		      : inttostr((int)fig->max.x));
  bunny_ini_set_field(ini, indexer, "max", 1, *(fig->lim + 4) == 0 ? "none"
		      : inttostr((int)fig->max.y));
  bunny_ini_set_field(ini, indexer, "max", 2, *(fig->lim + 5) == 0 ? "none"
		      : inttostr((int)fig->max.z));
}
