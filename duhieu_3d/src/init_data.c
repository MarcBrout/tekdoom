/*
** init_data.c for init in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:54:30 2016 benjamin duhieu
** Last update Fri Jan 22 19:46:06 2016 benjamin duhieu
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
