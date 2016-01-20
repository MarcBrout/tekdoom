/*
** direction.c for dir
** in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 11:30:54 2016 benjamin duhieu
** Last update Wed Jan 20 18:50:36 2016 benjamin duhieu
*/

#include "main.h"

int	up(t_main *doom)
{
  doom->calc.ay = (int)((doom->pars.maps->next->lvls->next->ply * 10000) /
			doom->calc.dim) * (doom->calc.dim) - 1;
  doom->calc.ax = doom->pars.maps->next->lvls->next->plx * 10000 +
    ((doom->pars.maps->next->lvls->next->ply * 10000 - doom->calc.ay) /
     (doom->calc.ang.tang
      [(int)doom->pars.maps->next->lvls->next->pla * 10]));
  doom->calc.ya = doom->calc.dim * (-1);
  doom->calc.xa = doom->calc.dim /
    doom->calc.ang.tang[(int)doom->pars.maps->next->lvls->next->pla * 10];
  if (doom->pars.maps->next->lvls->next->size
      [doom->calc.ay / 10000][doom->calc.ax / 10000])
    return (0);
  else
    while (!doom->pars.maps->next->lvls->next->size
	   [doom->calc.ay / 10000][doom->calc.ax / 10000])
      {
	doom->calc.ay += doom->calc.ya;
	doom->calc.ax += doom->calc.xa;
      }
  return (0);
}

int	back(t_main *doom)
{
  doom->calc.ay = (int)((doom->pars.maps->next->lvls->next->ply * 10000) /
			doom->calc.dim) * doom->calc.dim + doom->calc.dim;
  doom->calc.ax = doom->pars.maps->next->lvls->next->plx * 10000 +
    ((doom->pars.maps->next->lvls->next->ply * 10000 - doom->calc.ay) /
     (doom->calc.ang.tang
      [(int)doom->pars.maps->next->lvls->next->pla * 10]));
  doom->calc.ya = doom->calc.dim;
  doom->calc.xa = doom->calc.dim /
    doom->calc.ang.tang[(int)doom->pars.maps->next->lvls->next->pla * 10];
  if (doom->pars.maps->next->lvls->next->size
      [doom->calc.ay / 10000][doom->calc.ax / 10000])
    return (0);
  else
    while (!doom->pars.maps->next->lvls->next->size
	   [doom->calc.ay / 10000][doom->calc.ax / 10000])
      {
	doom->calc.ay += doom->calc.ya;
	doom->calc.ax += doom->calc.xa;
      }
  return (0);
}

int	left(t_main *doom)
{
  doom->calc.bx = (int)((doom->pars.maps->next->lvls->next->plx * 10000) /
			doom->calc.dim) * doom->calc.dim + doom->calc.dim;
  doom->calc.by = doom->pars.maps->next->lvls->next->ply * 10000 +
    ((doom->pars.maps->next->lvls->next->plx * 10000 - doom->calc.bx) /
     (doom->calc.ang.tang
      [(int)doom->pars.maps->next->lvls->next->pla * 10]));
  doom->calc.xa = doom->calc.dim * (-1);
  doom->calc.ya = doom->calc.dim *
    doom->calc.ang.tang[(int)doom->pars.maps->next->lvls->next->pla * 10];
  printf("bx = %d, by = %d\n", doom->calc.bx / 10000, doom->calc.by / 10000);
  if (doom->pars.maps->next->lvls->next->size
      [doom->calc.by / 10000][doom->calc.bx / 10000])
    return (0);
  else
    while (!doom->pars.maps->next->lvls->next->size
	   [doom->calc.by / 10000][doom->calc.bx / 10000])
      {
	doom->calc.bx += doom->calc.xa;
	doom->calc.by += doom->calc.ya;
      }
  return (0);
}

int	right(t_main *doom)
{
  doom->calc.bx = (int)((doom->pars.maps->next->lvls->next->plx * 10000) /
			 doom->calc.dim) * (doom->calc.dim) - 1;
  doom->calc.by = doom->pars.maps->next->lvls->next->ply * 10000 +
    ((doom->pars.maps->next->lvls->next->plx * 10000 - doom->calc.bx) /
     (doom->calc.ang.tang
      [(int)doom->pars.maps->next->lvls->next->pla * 10]));
  doom->calc.xa = doom->calc.dim;
  doom->calc.ya = doom->calc.dim *
    doom->calc.ang.tang[(int)doom->pars.maps->next->lvls->next->pla * 10];
  if (doom->pars.maps->next->lvls->next->size
      [doom->calc.by / 10000][doom->calc.bx / 10000])
    return (0);
  else
    while (!doom->pars.maps->next->lvls->next->size
	   [doom->calc.by][doom->calc.bx])
      {
	doom->calc.bx += doom->calc.xa;
	doom->calc.by += doom->calc.ya;
      }
  return (0);
}
