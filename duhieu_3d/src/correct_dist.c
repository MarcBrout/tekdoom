/*
** correct_dist.c for cor in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 12:38:35 2016 benjamin duhieu
** Last update Sun Jan 17 14:01:06 2016 benjamin duhieu
*/

#include "engine.h"

int	correct_dist_mh(t_main *doom, int mh, int nhight)
{
  if (doom->calc.teta >= 90 && doom->calc.teta < 240)
    nhight = mh * doom->calc.ang.cosi[(doom->calc.fov / 2) * 10];
  else if ((doom->calc.teta >= 240 && doom->calc.teta < 360) &&
	   (doom->calc.teta >= 0 && doom->calc.teta < 90))
    nhight = mh *
      doom->calc.ang.cosi[((doom->calc.teta + 30) % 360) * 10];
  return (nhight);
}

int	correct_dist_mv(t_main *doom, int mv, int nhight)
{
  if (doom->calc.teta >= 90 && doom->calc.teta < 240)
    nhight = mv * doom->calc.ang.cosi[(doom->calc.fov / 2) * 10];
  else if ((doom->calc.teta >= 240 && doom->calc.teta < 360) &&
	   (doom->calc.teta >= 0 && doom->calc.teta < 90))
    nhight = mv *
      doom->calc.ang.cosi[((doom->calc.teta - 30) % 360) * 10];
  doom->calc.ax = doom->calc.bx;
  return (nhight);
}
