/*
** save_plne.c for RTV2 in /home/rotaru_i/gfx_raytracer2/src
**
** Made by
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun May 22 19:37:05 2016
** Last update Sun May 22 19:39:45 2016 
*/

#include "rt.h"

void	save_plane(t_bunny_ini *ini, t_fig *fig, int idx)
{
  char	*indexer;

  if (!(indexer = stradd("plane_", inttostr(idx))))
    return ;
  bunny_ini_set_field(ini, indexer, "name", 0, indexer);
  bunny_ini_set_field(ini, indexer, "pos", 0, inttostr((int)fig->pos.x));
  bunny_ini_set_field(ini, indexer, "pos", 1, inttostr((int)fig->pos.y));
  bunny_ini_set_field(ini, indexer, "pos", 2, inttostr((int)fig->pos.z));
  bunny_ini_set_field(ini, indexer, "rgb", 0,
		      inttostr((unsigned char)fig->rgb.argb[0]));
  bunny_ini_set_field(ini, indexer, "rgb", 1,
		      inttostr((unsigned char)fig->rgb.argb[1]));
  bunny_ini_set_field(ini, indexer, "rgb", 2,
		      inttostr((unsigned char)fig->rgb.argb[2]));
  bunny_ini_set_field(ini, indexer, "alpha", 0, inttostr((int)fig->alpha));
  bunny_ini_set_field(ini, indexer, "refl", 0, inttostr((int)fig->refl));
  bunny_ini_set_field(ini, indexer, "shine", 0, inttostr((int)fig->shine));
  bunny_ini_set_field(ini, indexer, "rot", 0,
		      inttostr((int)(fig->rot.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "rot", 1,
		      inttostr((int)(fig->rot.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "rot", 2,
		      inttostr((int)(fig->rot.z * 100.0)));
  save_plane_end(ini, fig, indexer);
}

void	save_cylindre_end(t_bunny_ini *ini, t_fig *fig, char *indexer)
{
  bunny_ini_set_field(ini, indexer, "dvec", 0,
		      inttostr((int)(fig->dvec.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 1,
		      inttostr((int)(fig->dvec.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 2,
		      inttostr((int)(fig->dvec.z * 100.0)));
}

void	save_cylindre(t_bunny_ini *ini, t_fig *fig, int idx)
{
  char	*indexer;

  if (!(indexer = stradd("cylindre_", inttostr(idx))))
    return ;
  bunny_ini_set_field(ini, indexer, "name", 0, indexer);
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
  bunny_ini_set_field(ini, indexer, "rot", 0,
		      inttostr((int)(fig->rot.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "rot", 1,
		      inttostr((int)(fig->rot.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "rot", 2,
		      inttostr((int)(fig->rot.z * 100.0)));
  save_cylindre_end(ini, fig, indexer);
}

void	save_cone_end(t_bunny_ini *ini, t_fig *fig, char *indexer)
{
  bunny_ini_set_field(ini, indexer, "rot", 2,
		      inttostr((int)(fig->rot.z * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 0,
		      inttostr((int)(fig->dvec.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 1,
		      inttostr((int)(fig->dvec.y * 100.0)));
  bunny_ini_set_field(ini, indexer, "dvec", 2,
		      inttostr((int)(fig->dvec.z * 100.0)));
}

void	save_cone(t_bunny_ini *ini, t_fig *fig, int idx)
{
  char	*indexer;

  if (!(indexer = stradd("cone_", inttostr(idx))))
    return ;
  bunny_ini_set_field(ini, indexer, "name", 0, indexer);
  bunny_ini_set_field(ini, indexer, "pos", 0, inttostr((int)fig->pos.x));
  bunny_ini_set_field(ini, indexer, "pos", 1, inttostr((int)fig->pos.y));
  bunny_ini_set_field(ini, indexer, "pos", 2, inttostr((int)fig->pos.z));
  bunny_ini_set_field(ini, indexer, "rgb", 0,
		      inttostr((unsigned char)fig->rgb.argb[0]));
  bunny_ini_set_field(ini, indexer, "rgb", 1,
		      inttostr((unsigned char)fig->rgb.argb[1]));
  bunny_ini_set_field(ini, indexer, "rgb", 2,
		      inttostr((unsigned char)fig->rgb.argb[2]));
  bunny_ini_set_field(ini, indexer, "angle", 0, inttostr((int)fig->angle));
  bunny_ini_set_field(ini, indexer, "height", 0, inttostr((int)fig->height));
  bunny_ini_set_field(ini, indexer, "alpha", 0, inttostr((int)fig->alpha));
  bunny_ini_set_field(ini, indexer, "refl", 0, inttostr((int)fig->refl));
  bunny_ini_set_field(ini, indexer, "shine", 0, inttostr((int)fig->shine));
  bunny_ini_set_field(ini, indexer, "rot", 0,
		      inttostr((int)(fig->rot.x * 100.0)));
  bunny_ini_set_field(ini, indexer, "rot", 1,
		      inttostr((int)(fig->rot.y * 100.0)));
  save_cone_end(ini, fig, indexer);
}
