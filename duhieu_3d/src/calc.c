/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Wed Jan 20 14:51:39 2016 benjamin duhieu
*/

#include "main.h"

/*
** Calc if the intersection is with the horizontal wall, case 1:
** If our teta is turn to the up, case 2: If our teta is turn to our back
*/

int	intersection_horizontal(t_main *doom)
{
  if (doom->pars.maps->next->lvls->next->pla >= 0 &&
      doom->pars.maps->next->lvls->next->pla < 180)
    return (up(doom));
  else if (doom->pars.maps->next->lvls->next->pla >= 180 &&
	   doom->pars.maps->next->lvls->next->pla < 360)
    return (back(doom));
  return (0);
}

/*
** Calc if the intersection is with the vertical wall, case 1:
** If our teta is turn to the left, case 2: If our teta is turn to the right
*/

int	intersection_vertical(t_main *doom)
{
  if (doom->pars.maps->next->lvls->next->pla >= 90 &&
      doom->pars.maps->next->lvls->next->pla < 240)
    return (left(doom));
  else if ((doom->pars.maps->next->lvls->next->pla >= 240 &&
	    doom->pars.maps->next->lvls->next->pla < 360) ||
	   (doom->pars.maps->next->lvls->next->pla >= 0 &&
	    doom->pars.maps->next->lvls->next->pla < 90))
    return (right(doom));
  return (0);
}

/*
** Calc the distance of the player with the wall, If the HorizontalWall is
** the closer, it becomes the distIncorrect, else VerticalWall becomes the
** Dist incorrect
*/

void		dist_to_wall(t_main *doom)
{
  int		dist;
  int		mh;
  int		mv;
  double	nhight;

  nhight = 0;
  dist = (WIDTH / 2) / (doom->calc.ang.tang[(doom->calc.fov / 2) * 10]);
  mh = ABS(doom->pars.maps->next->lvls->next->plx * 10000 - doom->calc.ax) /
    doom->calc.ang.cosi[(int)doom->pars.maps->next->lvls->next->pla * 10];
  mv = ABS(doom->pars.maps->next->lvls->next->plx * 10000 - doom->calc.bx) /
    doom->calc.ang.cosi[(int)doom->pars.maps->next->lvls->next->pla * 10];
  if (mh >= mv)
    nhight = correct_dist_mh(doom, mh, nhight);
  else
    nhight = correct_dist_mv(doom, mv, nhight);
  printf("nhight = %f, dist = %d\n", nhight, dist);
  doom->calc.hight = ((doom->calc.dim / nhight) / 10000) * dist;
}

/*
** Disp the wall, One column at time.
*/

void		disp_wall(t_main *doom, int a)
{
  int		i;
  unsigned	*pixels;

  pixels = (unsigned *)doom->pix->pixels;
  i = (HEIGHT / 2) - (doom->calc.hight / 2) - 1;
  while (++i < ((HEIGHT / 2) + (doom->calc.hight / 2)) && i < HEIGHT)
    {
      pixels[a + i * WIDTH] = WHITE;
    }
}

void	calc(t_main *doom)
{
  int	a;

  --doom->pars.maps->next->lvls->next->pla;
  a = -1;
  while (++a < WIDTH)
    {
      doom->pars.maps->next->lvls->next->pla +=
	((double)doom->calc.fov / (double)WIDTH);
      check_ang(doom);
      /* printf("ang = %f, a = %d\n", doom->pars.maps->next->lvls->next->pla, a); */
      intersection_horizontal(doom);
      intersection_vertical(doom);
      dist_to_wall(doom);
      disp_wall(doom, a);
    }
}
