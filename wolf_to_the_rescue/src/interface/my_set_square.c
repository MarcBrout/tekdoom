/*
** my_set_square.c for my_set_square in /gfx_fdf1
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Nov 19 13:36:53 2015 maud marel
** Last update Tue Jan 26 22:12:33 2016 maud marel
*/

#include "tekdoom.h"

void		my_set_square(t_bunny_pixelarray *pix,
			      unsigned int colori)
{
  t_color	*color;
  int		i;

  i = 0;
  color = malloc(sizeof(t_color*));
  while (i <= (pix->clipable.clip_width * pix->clipable.clip_height))
    {
      color = (t_color*)pix->pixels + i;
      color->full = colori;
      i++;
    }
}
