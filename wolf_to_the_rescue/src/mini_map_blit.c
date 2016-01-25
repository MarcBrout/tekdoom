/*
** mini_map_blit.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Dec 22 01:06:18 2015 marc brout
** Last update Mon Jan 25 08:48:06 2016 benjamin duhieu
*/

#include "wolf.h"

void		set_bump(t_param * arg, t_lvl *lvl)
{
  int		x;
  int		y;
  int		xmax;
  int		ymax;
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  y = arg->calc.mini * 5 - 1;
  ymax = y + 1 + arg->calc.mini * lvl->height;
  xmax = arg->calc.mini * (lvl->width + 5);
  while (++y < ymax)
    {
      x = arg->calc.mini * 5 - 1;
      while (++x < xmax)
	{
	  if (lvl->map[lvl->height - 1 -
		       ((y - 5 * arg->calc.mini) / arg->calc.mini)]
	      [(x - 5 * arg->calc.mini) / arg->calc.mini])
	    pixels[x + y * lvl->mini->clipable.clip_width].full = WALLA;
	  else
	    pixels[x + y * lvl->mini->clipable.clip_width].full = FLOOR;
	}
    }
}

void			mini_map(t_param *arg, t_lvl *lvl)
{
  int			x;
  int			y;
  int			radius;
  /* int		xmini; */
  /* int		xmax; */
  /* int		ymini; */
  /* int		ymax; */
  unsigned int	*pixmap;
  unsigned int	*minmap;

  radius = 4 * arg->calc.mini;
  y = -radius - 1;
  /* ymini = lvl->minipos / lvl->mini->clipable.clip_width - 4 * */
  /*   arg->calc.mini - 1; */
  /* ymax = lvl->minipos / lvl->mini->clipable.clip_width + 4 * arg->calc.mini; */
  /* xmax = lvl->minipos % lvl->mini->clipable.clip_width + 4 * arg->calc.mini; */
  pixmap = arg->pix->pixels;
  minmap = lvl->mini->pixels;
  while (++y < radius)
    {
      x = -radius - 1;
      /* xmini = lvl->minipos % lvl->mini->clipable.clip_width - 4 * */
      /* 	arg->calc.mini - 1; */
      while (++x < radius)
	if (((x * x) + (y * y)) <= (radius * radius))
	  if (((5 * arg->calc.mini + x) < WIDTH &&
	       (5 * arg->calc.mini + x) > 0) &&
	      ((5 * arg->calc.mini + y) < HEIGHT &&
	       (5 * arg->calc.mini + y)) > 0)
	    pixmap[5 * arg->calc.mini + x + (5 * arg->calc.mini + y) * WIDTH] =
	      minmap[(int)((arg->lvl[arg->curlvl].playerx + x) +
			   (arg->lvl[arg->curlvl].playery + y) * lvl->mini->clipable.clip_width)];
    }
}

void		put_border(t_param *arg, int pix, unsigned int color)
{
  int		x;
  int		y;
  int		xmax;
  int		ymax;
  unsigned int	*pixels;

  y = HEIGHT - 9 * arg->calc.mini - pix - 1;
  ymax = HEIGHT - arg->calc.mini + pix;
  xmax = 9 * arg->calc.mini + pix;
  pixels = arg->pix->pixels;
  while (++y < ymax)
    {
      x = arg->calc.mini - pix - 1;
      while (++x < xmax)
	pixels[x + y * WIDTH] = color;
    }
}
