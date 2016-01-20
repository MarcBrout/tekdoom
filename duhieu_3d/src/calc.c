/*
** calc.c for calc in
** /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sun Jan 17 10:16:40 2016 benjamin duhieu
** Last update Sun Jan 17 14:00:19 2016 benjamin duhieu
*/

#include "engine.h"

/*
** Calc if the intersection is with the horizontal wall, case 1:
** If our teta is turn to the up, case 2: If our teta is turn to our back
*/

int	intersection_horzontal(t_main *doom)
{
  if (doom->calc.teta >= 0 && doom->calc.teta < 180)
    return (up(doom));
  else if (doom->calc.teta >= 180 && doom->calc.teta < 360)
    return (back(doom));
}

/*
** Calc if the intersection is with the vertical wall, case 1:
** If our teta is turn to the left, case 2: If our teta is turn to the right
*/

int	intersection_vertical(t_main *doom)
{
  if (doom->calc.teta >= 90 && doom->calc.teta < 240)
    return (left(doom));
  if ((doom->calc.teta >= 240 && doom->calc.teta < 360) &&
      (doom->calc.teta >= 0 && doom->calc.teta < 90))
    return (right(doom));
}

/*
** Calc the distance of the player with the wall, If the HorizontalWall is
** the closer, it becomes the distIncorrect, else VerticalWall becomes the
** Dist incorrect
*/

int	dist_to_wall(t_main *doom)
{
  int	dist;
  int	nhight;
  int	mh;
  int	mv;

  dist = doom->calc.dist = (WIDTH / 2) /
    (doom->calc.ang.tang[(doom->calc.fov / 2) * 10]);
  mh = ABS(doom->calc.px - doom->calc.ax) /
    doom->calc.ang.cosi[doom->calc.teta * teta];
  mv = ABS(doom->calc.px - doom->calc.bx) /
    doom->calc.ang.cosi[doom->calc.teta * teta];
  if (mh >= mv)
    nhight = correct_dist_mh(doom, mh, nhight);
  else
    nhight = correct_dist_mv(doom, mv, nhight);
  doom->calc.hight = (doom->calc.dim / nhight) * doom->calc.dist;
}

/*
** Disp the wall, One column at time.
*/

int		disp_wall(t_main *doom)
{
  int		i;
  unsigned	*pixels;

  pixels = (unsigned *)wolf->pix->pixels;
  i = (HEIGHT / 2) - (doom->calc.hight / 2) - 1;
  while (++i < ((HEIGHT / 2) + (doom->calc.hight / 2)) && i < HEIGHT)
    pixels[doom->calc.ax + i * WIDTH] == WHITE;
}

int	calc(t_main *doom)
{
  intersection_horizontal(doom);
  intersection_vertical(doom);
  dist_to_wall(doom);
  disp_wall(doom);
}
