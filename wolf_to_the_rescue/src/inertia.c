/*
** inertia.c for inertia
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Jan 26 09:51:56 2016 benjamin duhieu
** Last update Tue Jan 26 21:19:19 2016 marc brout
*/

#include "wolf.h"

void	inertie(t_param *arg)
{
  if (arg->speedy > 0)
    {
      move(arg, 0, 0.05);
      arg->speedy -= 2;
    }
  else
    arg->speedy = 0;
}
