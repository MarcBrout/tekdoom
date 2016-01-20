/*
** background.c<2> for back in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:34:07 2016 benjamin duhieu
** Last update Fri Jan 15 12:34:25 2016 benjamin duhieu
*/

#include "engine.h"

void		fill_screen(t_bunny_pixelarray *pix)
{
  int		i;
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  i = -2;
  while (++i < WIDTH * HEIGHT)
    {
      if (i < (WIDTH * HEIGHT) / 2)
	while (++i < (WIDTH * HEIGHT) / 2)
	  pixels[i] = RED;
      pixels[i] = BLACK;
    }
}
