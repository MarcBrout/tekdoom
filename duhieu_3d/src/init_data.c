/*
** init_data.c for init in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:54:30 2016 benjamin duhieu
<<<<<<< HEAD
** Last update Fri Jan 22 19:40:09 2016 benjamin duhieu
=======
** Last update Wed Jan 20 19:57:13 2016 marc brout
>>>>>>> 4f3bf963312008283e224b5ff26ede9980862c08
*/

#include "main.h"

void		fill_cos_sin(t_ang *ang)
{
  int		i;
  double	a;

  i = -1;
  a = 0.0;
  while (++i < 3600)
    {
      ang->cosi[i] = cos(RAD(a));
      ang->sinu[i] = sin(RAD(a));
      ang->tang[i] = tan(a);
      a += 0.1;
    }
}

void	init_data(t_main *doom)
{
  doom->speed = 1;
  doom->calc.fov = 60;
  parse(&(doom->pars));
  fill_cos_sin(&(doom->calc.ang));
}
