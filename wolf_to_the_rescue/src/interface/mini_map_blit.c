/*
** mini_map_blit.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Dec 22 01:06:18 2015 marc brout
<<<<<<< HEAD:wolf_to_the_rescue/src/mini_map_blit.c
** Last update Tue Jan 26 09:32:57 2016 benjamin duhieu
=======
** Last update Mon Jan 25 21:00:59 2016 maud marel
>>>>>>> fda0fc9443f38a2e14577def988b2bd61aa63076:wolf_to_the_rescue/src/interface/mini_map_blit.c
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

void			mini_map(t_param *arg, t_lvl *lvl, t_data *data)
{
  int		x;
  int		y;
  int		xmini;
  int		xmax;
  int		ymini;
  int		ymax;
  unsigned int	*pixmap;
  unsigned int	*minmap;

  y = arg->calc.mini - 1;
  ymini = lvl->minipos / lvl->mini->clipable.clip_width - 4 *
    arg->calc.mini - 1;
  ymax = lvl->minipos / lvl->mini->clipable.clip_width + 4 * arg->calc.mini;
  xmax = lvl->minipos % lvl->mini->clipable.clip_width + 4 * arg->calc.mini;
  pixmap = arg->pix->pixels;
  minmap = lvl->mini->pixels;
  while (++ymini < ymax && ++y > 0)
    {
      x = arg->calc.mini - 1;
      xmini = lvl->minipos % lvl->mini->clipable.clip_width - 4 *
	arg->calc.mini - 1;
      while (++xmini < xmax && ++x > 0)
	pixmap[x + y * WIDTH] =
	  minmap[xmini + ymini * lvl->mini->clipable.clip_width];
    }
}

void		put_border(t_param *arg, int pix, unsigned int color)
{
  int		x;
  int		y;
  int		xmax;
  int		ymax;
  unsigned int	*pixels;

  y = arg->calc.mini - pix - 1;
  ymax = 9 * arg->calc.mini + pix;
  xmax = 9 * arg->calc.mini + pix;
  pixels = arg->pix->pixels;
  while (++y < ymax)
    {
      x = arg->calc.mini - pix - 1;
      while (++x < xmax)
	pixels[x + y * arg->WIDTH] = color;
    }
}
