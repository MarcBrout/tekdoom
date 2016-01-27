/*
** mouse.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/wolf_to_the_rescue/src
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Jan 27 05:40:24 2016 Mathieu Sauvau
** Last update Wed Jan 27 08:50:12 2016 marc brout
*/

#include "tekdoom.h"

void				mouse2(t_param *arg, const t_bunny_position *abs)
{
  if ((abs->x <= 200 || abs->x >= (arg->WIDTH - 200)) ||
      (abs->y <= 200 || abs->y >= (arg->HEIGHT - 200)))
    {
      bunny_set_mouse_position_window(arg->win, arg->WIDTH / 2,
				      arg->HEIGHT / 2);
      arg->mov = 1;
    }
}

t_bunny_response		my_mouse(const t_bunny_position *pos,
					 void *data)
{
  const t_bunny_position	*abs;
  t_param			*arg;

  arg = data;
  abs = bunny_get_mouse_position();
  if (!arg->mov)
    {
      arg->lvl[arg->curlvl].yangle += 0;
      arg->lvl[arg->curlvl].plangle += pos->x / 3;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle += 359;
      if (arg->lvl[arg->curlvl].plangle >= 359)
	arg->lvl[arg->curlvl].plangle -= 359;
    }
  else
    arg->mov = 0;
  mouse2(arg, abs);
  return (GO_ON);
}
