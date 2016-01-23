/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Sat Jan 23 18:56:04 2016 marc brout
*/

#include "main.h"


void		disp_wall(t_main *doom, int x, UNUSED t_seg *tmp)
{
  int		i;
  double	k;
  double	wall;
  unsigned int	*pixels;

  k = (sqrt(pow((doom->calc.nx - PLX), 2) +
	    pow((doom->calc.ny - PLY), 2)));
  /* printf("x = %d, k = %f\n\n", x, 2 * k); */
  wall = HEIGHT / (2 * k);
  pixels = (unsigned int *)doom->pix->pixels;
  i = (HEIGHT / 2) - wall - /* ((tmp->z - 1) * 64) */ - 1;
  if (i < 0)
    i = -1;
  while (++i <  ((HEIGHT / 2) + wall) && i < HEIGHT)
    pixels[x + i * WIDTH] = WHITE;
}

int		inter(t_main *doom, int x, t_seg *tmp)
{
  double	chk1;
  double	chk2;

  if (doom->calc.a - doom->calc.na)
    doom->calc.nx =
      (doom->calc.nb - doom->calc.b) / (doom->calc.a - doom->calc.na);
  else
    return (0);
  doom->calc.ny = doom->calc.na * doom->calc.nx + doom->calc.nb;
  chk1 = doom->calc.nx - PLX;
  chk2 = doom->calc.ny - PLY;
  /* printf("cos = %f  chk1 = %f\n sin = %f chk2 = %f\nAX = %f \nAY = %f\nBX = %f\nBY = %f\n\n", doom->calc.cos, chk1, doom->calc.sin, chk2, AX, AY, BX, BY); */
  if (((doom->calc.cos >= 0 && chk1 > 0) && (doom->calc.sin > 0 && chk2 > 0)) ||
      ((doom->calc.cos <= 0 && chk1 < 0) && (doom->calc.sin > 0 && chk2 > 0)) ||
      ((doom->calc.cos >= 0 && chk1 > 0) && (doom->calc.sin < 0 && chk2 < 0)) ||
      ((doom->calc.cos <= 0 && chk1 < 0) && (doom->calc.sin < 0 && chk2 < 0)))
    disp_wall(doom, x, tmp);
  return (0);
}

int	calc(t_main *doom)
{
  double ang;
  int	x;
  int	test;
  t_seg *tmp2;

  x = -1;
  ang = (ANG + (doom->calc.fov / 2));
  if (ang > 359)
    ang -= 359;
  if (ang < 0)
    ang += 359;
  /* printf("%f\n", (double)doom->calc.fov / WIDTH); */
  /* printf("ang = %f\n", ANG); */
  while (++x < WIDTH)
    {
      /* printf("x = %d\n", x); */
	  tmp2 = doom->pars->maps->next->lvls->segs;
	  /* printf("ang * 10 = %f\n", ang * 10); */
	  doom->calc.a = doom->calc.ang.tang[(int)ang * 10];
	  doom->calc.b = PLY - (PLX * doom->calc.a);
	  doom->calc.cos = doom->calc.ang.cosi[(int)ang * 10];
	  doom->calc.sin = doom->calc.ang.sinu[(int)ang * 10];
	  test = 0;
	  while (tmp2)
	    {
	      /* printf("test =%d\n", test); */
	      /* printf("AX = %f \nAY = %f\nBX = %f\nBY = %f\n\n", tmp2->ax, tmp2->ay, tmp2->bx, tmp2->by); */
	      test += 1;
	      if ((tmp2->bx - tmp2->ax))
		{
		  doom->calc.na = (tmp2->by - tmp2->ay) / (tmp2->bx - tmp2->ax);
		  doom->calc.nb = tmp2->ay - (doom->calc.na * tmp2->ax);
		  inter(doom, x, tmp2);
		}
	      tmp2 = tmp2->next;
	    }
      ang = (ang - (doom->calc.fov / WIDTH));
      if (ang > 359)
	ang -= 359;
      if (ang < 0)
	ang += 359;
    }
  return (0);
}
