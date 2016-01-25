/*
** menu_draw.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:51:11 2016 Mathieu Sauvau
** Last update Mon Jan 25 15:44:37 2016 Mathieu Sauvau
*/

#include "wolf.h"

void                    draw_square(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect)
{
  int			x;
  int			y;

  x = rect->pos.x;
  y = rect->pos.y;
  while (rect->pos.x < rect->size.x + x)
    {
      while (rect->pos.y < rect->size.y + y)
        {
	  if (rect->selected &&
	      (rect->pos.x <= x + rect->contour - 1
	       || rect->pos.x >= rect->size.x + x - rect->contour ||
	       rect->pos.y <= y + rect->contour - 1
	       || rect->pos.y >= rect->size.y + y - rect->contour))
	    tekpixel3(pix_ar, &rect->pos, rect->color[1]);
	  else
	    tekpixel3(pix_ar, &rect->pos, rect->color[0]);
          rect->pos.y++;
        }
      rect->pos.x++;
      rect->pos.y = y;
    }
}

t_mrect			check_box(t_data *data, bool activated,
				  t_bunny_position label)
{
  t_mrect		rect;

  rect.size = pos_(50, 50);
  rect.pos = pos_(label.x + 10, label.y);
  rect.selected = activated;
  if (!activated)
    {
      rect.color[0] = WHITE;
      rect.color[1] = RED;
    }
  else
    {
      rect.color[0] = RED;
      rect.color[1] = WHITE;
    }
  rect.contour = 5;
  draw_square(data->pix_ar, &rect);
  return (rect);
}

t_mrect			label(t_data *data, bool selected,
			      t_bunny_position size, t_bunny_position pos)
{
  t_mrect		rect;

  rect.size = size;
  rect.pos = pos;
  rect.selected = selected;
  rect.color[0] = WHITE;
  rect.color[1] = RED;
  rect.contour = 3;
  draw_square(data->pix_ar, &rect);
  return (rect);
}

void                    draw_slider_2(t_bunny_pixelarray *pix_ar,
				      t_mrect *rect, t_bunny_position pos,
				      int rapport)
{

  if (rect->pos.x <= pos.x + rect->contour - 1
      || rect->pos.x >= rect->size.x + pos.x - rect->contour ||
      rect->pos.y <= pos.y + rect->contour - 1
      || rect->pos.y >= rect->size.y + pos.y - rect->contour)
    {
      if (rect->selected)
	tekpixel3(pix_ar, &rect->pos, rect->color[1]);
      else
	tekpixel3(pix_ar, &rect->pos, WHITE);
    }
  else
    {
      if (rect->pos.x < rapport)
	tekpixel3(pix_ar, &rect->pos, rect->color[0]);
      else
	tekpixel3(pix_ar, &rect->pos, WHITE);
    }
}

void                    draw_slider(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect, int pos_slider)
{
  int			rapport;
  t_bunny_position	pos;

  pos.x = rect->pos.x;
  pos.y = rect->pos.y;
  rapport = pos.x + (rect->size.x * pos_slider) / 100;
  while (rect->pos.x < rect->size.x + pos.x)
    {
      while (rect->pos.y < rect->size.y + pos.y)
        {
	  draw_slider_2(pix_ar, rect, pos, rapport);
          rect->pos.y++;
        }
      rect->pos.x++;
      rect->pos.y = pos.y;
    }
}
