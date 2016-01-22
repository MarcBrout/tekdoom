/*
** correct_dist.c for cor in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 12:38:35 2016 benjamin duhieu
** Last update Wed Jan 20 14:41:46 2016 benjamin duhieu
*/

#include "main.h"

double	correct_dist_mh(t_main *doom, int mh, double nhight)
{
  if (doom->pars.maps->next->lvls->next->pla >= 90 &&
      doom->pars.maps->next->lvls->next->pla < 240)
    nhight = mh * doom->calc.ang.cosi[(doom->calc.fov / 2) * 10];
  else if ((doom->pars.maps->next->lvls->next->pla >= 240 &&
	    doom->pars.maps->next->lvls->next->pla < 360) ||
	   (doom->pars.maps->next->lvls->next->pla >= 0 &&
	    doom->pars.maps->next->lvls->next->pla < 90))
    nhight = mh * doom->calc.ang.cosi
      [((int)(doom->pars.maps->next->lvls->next->pla + 30) % 360) * 10];
  return (nhight);
}

double	correct_dist_mv(t_main *doom, int mv, double nhight)
{
  if (doom->pars.maps->next->lvls->next->pla >= 90 &&
      doom->pars.maps->next->lvls->next->pla < 240)
    nhight = mv * doom->calc.ang.cosi[(doom->calc.fov / 2) * 10];
  else if ((doom->pars.maps->next->lvls->next->pla >= 240 &&
	    doom->pars.maps->next->lvls->next->pla < 360) ||
	   (doom->pars.maps->next->lvls->next->pla >= 0 &&
	    doom->pars.maps->next->lvls->next->pla < 90))
    nhight = mv * doom->calc.ang.cosi
      [((int)(doom->pars.maps->next->lvls->next->pla - 30) % 360 * 10)];
  doom->calc.ax = doom->calc.bx;
  return (nhight);
}

void	check_ang(t_main *doom)
{
  if (doom->pars.maps->next->lvls->next->pla == 0)
    doom->pars.maps->next->lvls->next->pla = 0.01;
  else if (doom->pars.maps->next->lvls->next->pla == 90)
    doom->pars.maps->next->lvls->next->pla = 90.01;
  else if (doom->pars.maps->next->lvls->next->pla == 180)
    doom->pars.maps->next->lvls->next->pla = 180.01;
  else if (doom->pars.maps->next->lvls->next->pla == 240)
    doom->pars.maps->next->lvls->next->pla = 240.01;
}
