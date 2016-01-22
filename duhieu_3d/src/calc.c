/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Fri Jan 22 19:44:01 2016 benjamin duhieu
*/

#include "main.h"


void		disp_wall(t_main *doom, int x)
{
  int		i;
  int		k;
  int		wall;
  unsigned	*pixels;

  k = (int)(sqrt(pow((doom->calc.nx - PLX), 2) +
		 pow((doom->calc.ny - PLY), 2)));
  wall = HEIGHT / (2 * k);
  pixels = (unsigned *)doom->pix->pixels;
  i = (HEIGHT / 2) - wall - ((HIGH - 1) * 64) - 1;
  if (i < 0)
    i = -1;
  while (++i <  ((HEIGHT / 2) + wall) && i < HEIGHT)
    pixels[x + i * WIDTH] = WHITE;
}

int		inter(t_main *doom, int x)
{
  double	cos;
  double	sin;
  double	chk1;
  double	chk2;

  if (doom->calc.a - doom->calc.na)
    doom->calc.nx =
      (doom->calc.nb - doom->calc.b) / (doom->calc.a - doom->calc.na);
  else
    return (0);
  doom->calc.ny = doom->calc.na * doom->calc.nx + doom->calc.nb;
  cos = doom->calc.ang.cosi[(int)ANG * 10];
  sin = doom->calc.ang.sinu[(int)ANG * 10];
  chk1 = doom->calc.nx - PLX;
  chk2 = doom->calc.ny - PLY;
  if (((cos > 0 && chk1 > 0) && (sin > 0 && chk2 > 0)) ||
      ((cos < 0 && chk1 < 0) && (sin > 0 && chk2 > 0)) ||
      ((cos > 0 && chk1 > 0) && (sin < 0 && chk2 < 0)) ||
      ((cos < 0 && chk1 < 0) && (sin < 0 && chk2 < 0)))
    disp_wall(doom, x);
  return (0);
}

int	calc(t_main *doom)
{
  t_seg	*elem;
  int	x;

  if ((elem = malloc(sizeof(t_seg))) == NULL)
    return (1);
  ANG = (int)(ANG + (doom->calc.fov / 2)) % 360;
  x = -1;
  while (++x < WIDTH)
    {
      if (doom->calc.ang.cosi[(int)ANG * 10])
	{
	  doom->calc.a = doom->calc.ang.tang[(int)ANG * 10];
	  doom->calc.b = PLY - (PLX * doom->calc.a);
	  while (elem != NULL)
	    {
	      doom->calc.na = (BY - AY) / (BX - AX);
	      doom->calc.nb = AY - (doom->calc.na * AX);
	      inter(doom, x);
	    }
	}
      ANG = (int)(ANG - (doom->calc.fov / WIDTH)) % 360;
    }
  return (0);
}
