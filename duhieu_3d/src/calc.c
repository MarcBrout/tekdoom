/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Sat Jan 23 21:31:43 2016 benjamin duhieu
*/

#include "main.h"


void		put_in_k(t_main *doom, int x, t_seg *tmp, t_lvl *lvl)
{
  double	k;
  int		i;

  i = -1;
  k = (sqrt(pow((doom->calc.nx - lvl->plx), 2) +
	    pow((doom->calc.ny - lvl->ply), 2)));
  while (lvl->tabseg[0][++i] != -1);
  lvl->tabseg[0][i] = k;
  lvl->tabseg[1][i] = tmp->z;
  printf("tabseg[0][%d] = %f, tabseg[1][%d] = %d\n", i, tabseg[i], i, tmp->z);
 }

int		inter(t_main *doom, int x, t_seg *tmp, t_lvl *lvl)
{
  double	chk1;
  double	chk2;

  if (doom->calc.a - doom->calc.na)
    doom->calc.nx =
      (doom->calc.nb - doom->calc.b) / (doom->calc.a - doom->calc.na);
  else
    return (0);
  doom->calc.ny = doom->calc.na * doom->calc.nx + doom->calc.nb;
  chk1 = doom->calc.nx - lvl->plx;
  chk2 = doom->calc.ny - lvl->ply;
  if (((doom->calc.cos >= 0 && chk1 > 0) && (doom->calc.sin > 0 && chk2 > 0)) ||
      ((doom->calc.cos <= 0 && chk1 < 0) && (doom->calc.sin > 0 && chk2 > 0)) ||
      ((doom->calc.cos >= 0 && chk1 > 0) && (doom->calc.sin < 0 && chk2 < 0)) ||
      ((doom->calc.cos <= 0 && chk1 < 0) && (doom->calc.sin < 0 && chk2 < 0)))
    put_in_k(doom, x, tmp, lvl);
  return (0);
}

void	disp_wall(t_main *doom, int x, t_lvl *lvl)
{
  int		i;
  int		j;
  double	wall;
  t_color	*pixels;

  i = -1;
  while (lvl->tabseg[0][++i] != -1)
    {
      wall = HEIGHT / (2 * lvl->tabseg[0][i]);
      pixels = (t_color *)doom->pix->pixels;
      j = (HEIGHT / 2) - wall /* - ((tmp->z - 1) * 64) */ - 1;
      if (j < 0)
	j = -1;
      while (++j <  ((HEIGHT / 2) + wall) && j < HEIGHT)
	{
	  pixels[x + j * WIDTH].full = WHITE
	    pixels[x + j * WIDTH].argb[0] -= (int)(k / 2);
	  pixels[x + j * WIDTH].argb[1] -= (int)(k / 2);
	  pixels[x + j * WIDTH].argb[2] -= (int)(k / 2);
	}
    }
}

void	tri_tabk(t_main *doom, t_lvl *lvl, int x)
{
  int	i;
  int	j;
  int	k;
  int	l;
  int	tmp;

  i = -1;
  l = 0;
  tmp = 0;
  while (lvl->tabseg[0][++i] != -1)
    {
      j = -1;
      k = lvl->tabseg[0][i];
      while (lvl->tabseg[0][++j] != -1)
	if (k >= lvl->tabseg[0][j] && l++)
	  k = lvl->tabseg[0][j];
      tmp = lvl->tabseg[0][l];
      lvl->tabseg[0][l] = lvl->tabseg[0][i];
      lvl->tabseg[0][i] = tmp;
    }
  disp_wall(doom, lvl, x);
}

int	calc(t_main *doom, t_lvl *lvl)
{
  double ang;
  int	x;
  t_seg *tmp2;

  x = -1;
  ang = (lvl->pla + (doom->calc.fov / 2));
  if (ang > 359)
    ang -= 359;
  if (ang < 0)
    ang += 359;
  while (++x < WIDTH)
    {
      tmp2 = lvl->segs;
      if (doom->calc.ang.tang[(int)(ang * 10)] == 0)
	ang = 359.99;
      doom->calc.a = doom->calc.ang.tang[(int)(ang * 10)];
      doom->calc.a = doom->calc.ang.tang[(int)(ang * 10)];
      doom->calc.b = lvl->ply - (lvl->plx * doom->calc.a);
      doom->calc.cos = doom->calc.ang.cosi[(int)(ang * 10)];
      doom->calc.sin = doom->calc.ang.sinu[(int)(ang * 10)];
      while (tmp2)
	{
	  if ((tmp2->bx - tmp2->ax))
	    {
	      doom->calc.na = (tmp2->by - tmp2->ay) / (tmp2->bx - tmp2->ax);
	      doom->calc.nb = tmp2->ay - (doom->calc.na * tmp2->ax);
	      inter(doom, x, tmp2, lvl);
	    }
	  tmp2 = tmp2->next;
	}
      tri_tabk(doom, lvl, x);
      ang = (ang - (doom->calc.fov / WIDTH));
      if (ang > 359)
	ang -= 359;
      if (ang < 0)
	ang += 359;
    }
  return (0);
}
