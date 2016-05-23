/*
** bentor.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 17:49:41 2016 Alif Matthias
** Last update Sun May 22 22:22:02 2016 Alif Matthias
*/

#include "rt.h"

t_eko	bentor(const t_vec *ray,
	       const t_eye *eye,
	       const t_fig *elem)
{
  t_eko	ret;

  (void)ray;
  (void)eye;
  (void)elem;
  mset(&ret, sizeof(t_eko));
  ret.t = -1;
  return (ret);
}

void	mehdi(t_vec **vec, t_fig *elem,
	      t_color *col, const t_fig *fig)
{
  (void)vec;
  (void)elem;
  (void)col;
  (void)fig;
}
