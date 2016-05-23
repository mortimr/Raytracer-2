/*
** getnbr_utils.c for rt in /home/alif_m/tek1/igraph/gfx_raytracer2
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun May 22 18:39:06 2016 Alif Matthias
** Last update Sun May 22 22:42:39 2016 Alif Matthias
*/

void	nbr_setter(int *perso_neg,
		   long long *multiplier,
		   int *start)
{
  *perso_neg = 0;
  *multiplier = 1;
  *(start + 1) = 0;
  *start = 0;
}
