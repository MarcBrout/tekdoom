/*
** keyboard_mouse.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Dec 22 19:34:41 2015 marc brout
** Last update Wed Jan 27 06:57:30 2016 benjamin duhieu
*/

#include "tekdoom.h"

void		simple_tap(t_param *arg)
{
  const bool	*k;

  k = bunny_get_keyboard();
  if (k[arg->INPUT->key[0]])
    {
      if (arg->speedy < 9)
	arg->speedy += 3;
      move(arg, 0, 0.07);
    }
  if (k[arg->INPUT->key[1]])
    {
      arg->speedy = 0;
      move(arg, 0, -0.05);
    }
  if (k[arg->INPUT->key[2]])
    move(arg, 90, 0.05);
  if (k[arg->INPUT->key[3]])
    move(arg, 90, -0.05);
  if (k[arg->INPUT->key[4]])
    arg->jump = 101;
}

t_bunny_response	my_keys(t_bunny_event_state state,
				t_bunny_keysym keysym,
				void *data)
{
  t_param		*arg;

  arg = data;
  if (state == GO_DOWN)
    {
      if (keysym == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (keysym == BKS_P)
	arg->curlvl = (arg->curlvl + 1 == arg->nblvl) ? 0 : arg->curlvl + 1;
      if (keysym == BKS_M)
	arg->curlvl = (arg->curlvl - 1 >= 0) ? arg->curlvl - 1 :
	  arg->nblvl - 1;
      simple_tap(arg);
      keyboard_interface(arg);
      keyboard_interface2(state, keysym, arg);
    }
  return (GO_ON);
}

int		next_casex(t_param *arg, double val)
{
  int		cas;

  if ((cas = arg->lvl[arg->curlvl].map
       [(int)(arg->lvl[arg->curlvl].playery)]
       [(int)(arg->lvl[arg->curlvl].playerx + val)]) == 3 &&
      (arg->curlvl < (arg->nblvl - 1)))
    {
      bunny_sound_play(arg->sound->door);
      bunny_sound_volume(arg->sound->door, arg->data->config->volume);
      arg->trans = true;
    }
  return (cas);
}

int		next_casey(t_param *arg, double val)
{
  int		cas;

  if ((cas = arg->lvl[arg->curlvl].map
       [(int)(arg->lvl[arg->curlvl].playery + val)]
       [(int)(arg->lvl[arg->curlvl].playerx)]) == 3 &&
      (arg->curlvl < (arg->nblvl - 1)))
    {
      bunny_sound_play(arg->sound->door);
      bunny_sound_volume(arg->sound->door, arg->data->config->volume);
      arg->trans = true;
    }
  return (cas);
}

void		move(t_param *arg, double ang, double speed)
{
  double	x;
  double	y;
  int		iang;

  iang = (int)(arg->lvl[arg->curlvl].plangle + ang) % 360;
  x = arg->wm.costab[iang] * speed;
  y = arg->wm.sintab[iang] * speed;
  if (!next_casex(arg, x))
    {
      if ((int)(arg->lvl[arg->curlvl].playerx + x) > 0 &&
	  (int)(arg->lvl[arg->curlvl].playerx + x) <
	  (arg->lvl[arg->curlvl].width - 1))
	arg->lvl[arg->curlvl].playerx += x;
    }
  if (!next_casey(arg, y))
    {
      if ((int)(arg->lvl[arg->curlvl].playery + y) > 0 &&
	  (int)(arg->lvl[arg->curlvl].playery + y) <
	  (arg->lvl[arg->curlvl].height - 1))
	arg->lvl[arg->curlvl].playery += y;
    }
}
