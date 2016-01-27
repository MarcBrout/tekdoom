/*
** itoa.c for itoa in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:03:20 2016 Mathieu Sauvau
** Last update Fri Jan 22 16:42:35 2016 Mathieu Sauvau
*/

#include "menu.h"

char	*finish(char *str, bool neg, int i)
{
  if (neg)
    str[i++] = '-';
  str[i] = 0;
  my_revstr(str);
  return (str);
}

char	*itoa(int nb, char* str, int base)
{
  int	i;
  bool	neg;
  int	r;

  neg = false;
  i = 0;
  if (nb == 0)
    {
      str[i++] = '0';
      str[i] = '\0';
      return (str);
    }
  if (nb < 0 && base == 10)
    {
      neg = true;
      nb = -nb;
    }
  while (nb != 0)
    {
      r = nb % base;
      str[i++] = (r > 9)? (r - 10) + 'a' : r + '0';
      nb = nb / base;
    }
  return (finish(str, neg, i));
}
