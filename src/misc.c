/*
** misc.c for RTV2 in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Tue May  3 15:33:33 2016 Iulian Rotaru
** Last update Wed May 11 15:52:21 2016 Alif Matthias
*/

#include "rt.h"

void	mset(void *data, size_t size)
{
  int	i;

  i = -1;
  while (++i < (int)size)
    *(((char *)data) + i) = 0;
}

char	*sdup(const char *str)
{
  int	i;
  char	*out;

  if (!(out = bunny_malloc(sizeof(char) * (len(str) + 1))))
    return (NULL);
  i = -1;
  while (*(str + ++i))
    *(out + i) = *(str + i);
  *(out + i) = 0;
  return (out);
}

void	*callo_c(size_t size)
{
  void	*out;

  if (!(out = bunny_malloc(size)))
    return (NULL);
  mset(out, size);
  return (out);
}

int	cmp(const char *one, const char *two)
{
  int	i;

  if (len(one) != len(two))
    return (KO);
  i = -1;
  while (*(one + ++i) && *(two + i) && *(one + i) == *(two + i));
  if (*(one + i) == *(two + i))
    return (OK);
  return (KO);
}

int	isnum(const char *str)
{
  int	i;

  i = -1;
  if (!str || !*str)
    return (KO);
  if (*str == '-')
    i = 0;
  while (*(str + ++i))
    if (*(str + i) < '0' || *(str + i) > '9')
      return (KO);
  return (OK);
}
