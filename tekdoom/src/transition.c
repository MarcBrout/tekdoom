/*
** transition.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/wolf_to_the_rescue
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Jan 27 02:47:34 2016 Mathieu Sauvau
** Last update Wed Jan 27 02:50:26 2016 Mathieu Sauvau
*/

#include "tekdoom.h"

void			transition(t_param *arg)
{
  int			i;
  int			n;
  t_color		*col;

  col = arg->pix->pixels;
  n = -1;
  while (++n < 100)
    {
      i = -1;
      while (++i < arg->WIDTH * arg->HEIGHT)
	{
	  if (col[i].argb[RED_CMP] > 0)
	    col[i].argb[RED_CMP]--;
	  if (col[i].argb[GREEN_CMP] > 0)
	    col[i].argb[GREEN_CMP]--;
	  if (col[i].argb[BLUE_CMP] > 0)
	    col[i].argb[BLUE_CMP]--;
	}
      bunny_blit(&arg->win->buffer, &arg->pix->clipable, &arg->data->pos);
      bunny_display(arg->win);
    }
  arg->trans = false;
  arg->curlvl++;
  arg->speedy = 0;
}
