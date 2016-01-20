/*
** init_data.c for init in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:54:30 2016 benjamin duhieu
** Last update Sun Jan 17 12:43:55 2016 benjamin duhieu
*/

#include "engine.h"

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
      ang->tang[i] = ang->sinu[i] / ang->cosi[i];
      a += 0.1;
    }
}

int	init_data(t_main *doom)
{
  doom->calc.ang = 0;
  doom->calc.fov = 60;
  doom->calc.dist = (WIDTH / 2) / (doom->calc.ang.tang[(doom->calc.fov / 2) * 10]);
  doom->calc.ma = (int)((double)(doom->calc.fov / WIDTH));
  doom->calc.dim = 10000;
  doom->calc.teta = 33;
  doom->calc.px = 15000;
  doom->calc.py = 15000;
  fill_cos_sin(doom->calc.ang);
}
