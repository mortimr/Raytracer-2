/*
** new_my_getnbr.c for my_getnbr in /home/rotaru_i/workspace/my_getnbr
**
** Made by iulian rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Oct  4 15:28:03 2015 iulian rotaru
** Last update Sun May 22 18:46:59 2016 Alif Matthias
*/

#include "rt.h"

static int	start_end(const char *str,
			  int *start,
			  int *end,
			  int *neg)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (str && *(str + ++i) != '\0')
    {
      if ((*(str + i) < 48 || *(str + i) > 57)
	  && (*(str + i) != 45) && (*(str + i) != 43))
	return (1);
      if (*(str + i) == 45)
	*neg = *neg + 1;
      if (*(str + i) > 47 && *(str + i) < 58 && j == 0)
	{
	  *start = i;
	  j = 1;
	}
      if ((*(str + i) > 47 && *(str + i) < 58)
	  && (*(str + i + 1) < 48 || *(str + i + 1) > 57))
	{
	  *end = i;
	  break ;
	}
    }
  return (0);
}

static int	multi_maker(int *start,
			    int *end,
			    long long *multiplier)
{
  long long	i;

  i = 0;
  if (*end - *start > 9)
    return (0);
  if (*end - *start == 9)
    *multiplier = 1000000000;
  if (*end - *start < 9)
    {
      *multiplier = 1;
      while (i != (*end - *start))
	{
	  *multiplier = *multiplier * 10;
	  i = i + 1;
	}
      i = 0;
    }
  return (1);
}

static long long	nb_maker(const char *str,
				 int *start,
				 int *end,
				 long long multiplier)
{
  long long		ll_nb;
  int			s;

  s = *start;
  ll_nb = 0;
  while (s < *end + 1)
    {
      ll_nb = ll_nb + ((*(str + s) - 48) * multiplier);
      multiplier = multiplier / 10;
      s = s + 1;
    }
  return (ll_nb);
}

static int	neg_maker(int *neg)
{
  *neg = *neg % 2;
  return (0);
}

int		nbr(const char *str)
{
  int		start[2];
  long long	multiplier;
  long long	nb_before_test;
  int		perso_neg;

  if (*str == 0 || (*str == '-' && *(str + 1) == 0))
    return (0);
  nbr_setter(&perso_neg, &multiplier, start);
  if (start_end(str, start, start + 1, &perso_neg) == 1)
    return (0);
  neg_maker(&perso_neg);
  if (multi_maker(start, start + 1, &multiplier) == 0)
    return (0);
  if (perso_neg == 1)
    {
      nb_before_test = nb_maker(str, start, start + 1, multiplier) * -1;
      if (nb_before_test >= -2147483648)
	return (nb_maker(str, start, start + 1, multiplier) * -1);
      return (0);
    }
  nb_before_test = nb_maker(str, start, start + 1, multiplier);
  if (nb_before_test <= 2147483647)
    return (nb_maker(str, start, start + 1, multiplier));
  return (0);
}
