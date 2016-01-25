/*
** menu_utilities2.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:57:06 2016 Mathieu Sauvau
** Last update Fri Jan 22 17:28:16 2016 Mathieu Sauvau
*/

#include "menu.h"

void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color)
{
  int                   x;
  int                   y;
  t_color               *col;
  int                   new_pos;

  x = 0;
  y = 0;
  col = pix_ar->pixels;
  while (x < pix_ar->clipable.clip_width)
    {
      while (y < pix_ar->clipable.clip_height)
        {
          new_pos = pix_ar->clipable.clip_width * y  + x;
          col[new_pos].full = color;
          y++;
        }
      x++;
      y = 0;
    }
}

t_mrect			slider(t_data *data, bool selected, int pos_slider,
			       t_bunny_position pos)
{
  t_mrect		rect;

  rect.size = pos_(data->config->width / 2, 30);
  rect.pos = pos;
  rect.selected = selected;
  rect.color[0] = BLUE;
  rect.color[1] = RED;
  rect.contour = 3;
  draw_slider(data->pix_ar, &rect, pos_slider);
  return (rect);
}
