/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Sat Jan 23 23:13:09 2016 marc brout
*/

#include "main.h"


void		put_in_k(t_main *doom, t_seg *tmp, t_lvl *lvl, int *i)
{
  double	k;

  k = (sqrt(pow((doom->calc.nx - lvl->plx), 2) +
	    pow((doom->calc.ny - lvl->ply), 2)));
  lvl->tabseg[0][*i] = k;
  lvl->tabseg[1][*i] = tmp->z;
  *i += 1;
 }

int		inter(t_main *doom, t_seg *tmp, t_lvl *lvl, int *i)
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
    put_in_k(doom, tmp, lvl, i);
  return (0);
}

void	disp_wall(t_main *doom, t_lvl *lvl, int x)
{
  int		i;
  int		j;
  double	wall;
  t_color	*pixels;

  i = -1;
  while (++i < lvl->nbseg && lvl->tabseg[0][i] > 0)
    {
      wall = HEIGHT / (3 * lvl->tabseg[0][i]);
      pixels = (t_color *)doom->pix->pixels;
      j = (HEIGHT / 2) - wall - /* ((lvl->tabseg[1][i] - 1) * 64) - */1;
      if (j < 0)
	j = -1;
      while (++j <  ((HEIGHT / 2) + wall) && j < HEIGHT)
	{
	  pixels[x + j * WIDTH].full = WHITE;
	  if ((pixels[x + j * WIDTH].argb[0] - (int)(lvl->tabseg[0][i])) > 0)
	    pixels[x + j * WIDTH].argb[0] -= (int)(lvl->tabseg[0][i]);
	  else
	    pixels[x + j * WIDTH].argb[0] = 0;
	  if ((pixels[x + j * WIDTH].argb[1] - (int)(lvl->tabseg[0][i])) > 0)
	    pixels[x + j * WIDTH].argb[1] -= (int)(lvl->tabseg[0][i]);
	  else
	    pixels[x + j * WIDTH].argb[1] = 0;
	  if ((pixels[x + j * WIDTH].argb[2] - (int)(lvl->tabseg[0][i])) > 0)
	    pixels[x + j * WIDTH].argb[2] -= (int)(lvl->tabseg[0][i]);
	  else
	    pixels[x + j * WIDTH].argb[2] = 0;
	}
    }
}

void		tri_tabk(t_main *doom, t_lvl *lvl, int x)
{
  int		i;
  int		j;
  double	max;
  int		l;
  double	tmp;
  double	size;
  int z = -1;
 
  i = -1;
  tmp = 0;
  while (++i < lvl->nbseg && lvl->tabseg[0][i] > 0)
    {
      l = i;
      j = i;
      max = lvl->tabseg[0][i];
      while (++j < lvl->nbseg)
	if (max < lvl->tabseg[0][j] && (l = j))
	  max = lvl->tabseg[0][j];
      tmp = lvl->tabseg[0][l];
      size = lvl->tabseg[1][l];
      lvl->tabseg[0][l] = lvl->tabseg[0][i];
      lvl->tabseg[1][l] = lvl->tabseg[1][i];
      lvl->tabseg[0][i] = tmp;
      lvl->tabseg[1][i] = size;
    }
  while (++z < lvl->nbseg && lvl->tabseg[0][z] > 0)
    printf("k = lvl->tabseg[0][%d] = %f\nvz = lvl->tabseg[1][%d] = %f\n",
  	   z, lvl->tabseg[0][z], z, lvl->tabseg[1][z]);
  disp_wall(doom, lvl, x);
}

void	res_tab(t_lvl *lvl)
{
  int	i;

  i = -1;
  while (++i < lvl->nbseg)
    {
      lvl->tabseg[0][i] = -1;
      lvl->tabseg[1][i] = -1;
    }
}

int	calc(t_main *doom, t_lvl *lvl)
{
  double ang;
  int	x;
  t_seg *tmp2;
  int	i;

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
      i = 0;
      while (tmp2)
	{
	  if ((tmp2->bx - tmp2->ax))
	    {
	      doom->calc.na = (tmp2->by - tmp2->ay) / (tmp2->bx - tmp2->ax);
	      doom->calc.nb = tmp2->ay - (doom->calc.na * tmp2->ax);
	      inter(doom, tmp2, lvl, &i);
	    }
	  tmp2 = tmp2->next;
	}
      tri_tabk(doom, lvl, x);
      res_tab(lvl);
      ang = (ang - (doom->calc.fov / WIDTH));
      if (ang > 359)
	ang -= 359;
      if (ang < 0)
	ang += 359;
    }
  return (0);
}
