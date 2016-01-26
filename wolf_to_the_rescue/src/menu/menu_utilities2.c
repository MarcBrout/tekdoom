/*
** menu_utilities2.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:57:06 2016 Mathieu Sauvau
** Last update Tue Jan 26 16:55:29 2016 Mathieu Sauvau
*/

#include "menu.h"

void			cpy_bg2(t_bunny_pixelarray *pix_ar,
				t_bunny_pixelarray *bg,
				t_bunny_position pos, int bg_x)
{
  int			new_pos;
  int			bg_pos;
  t_color               *col;
  t_color		*bg_col;

  col = pix_ar->pixels;
  bg_col = bg->pixels;
  new_pos = pix_ar->clipable.clip_width * pos.y  + pos.x;
  bg_pos = bg->clipable.clip_width * pos.y + bg_x;
  if (bg_x < bg->clipable.clip_width && pos.y < bg->clipable.clip_height)
    col[new_pos].full = bg_col[bg_pos].full;
  else
    col[new_pos].full = BLACK;
}

void                    cpy_bg(t_bunny_pixelarray *pix_ar,
			       t_bunny_pixelarray *bg)
{
  t_bunny_position       pos;
  int			bg_x;
  int			offset;

  pos.x = 0;
  bg_x = 0;
  offset = pix_ar->clipable.clip_width / 2 - bg->clipable.clip_width / 2;
  while (offset + pix_ar->clipable.clip_width / 2 > pix_ar->clipable.clip_width)
    offset--;
  while (pos.x < pix_ar->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pix_ar->clipable.clip_height)
        {
	  cpy_bg2(pix_ar, bg, pos, bg_x);
          pos.y++;
	}
      if (pos.x > offset)
	bg_x++;
      pos.x++;
    }
}

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
