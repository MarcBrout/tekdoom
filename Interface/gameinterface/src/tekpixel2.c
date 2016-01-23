/*
** tekpixel.c for tekpixel in /src
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Nov 16 15:25:45 2015 maud marel
** Last update Fri Jan 22 15:14:54 2016 maud marel
*/

#include "interface.h"

void		tekpixel2(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color *color)
{
  t_color       *col;

  if (pos->x >= 0 && pos->x <= 1000 && pos->y >= 0 && pos->y <= 1000)
    {
      col = (t_color*)pix->pixels +
	(pos->x + pos->y * pix->clipable.clip_width);
      col->full = color->full;
    }
}