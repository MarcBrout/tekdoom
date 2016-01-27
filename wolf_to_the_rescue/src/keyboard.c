/*
** keyboard_mouse.c for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Dec 22 19:34:41 2015 marc brout
** Last update Tue Jan 26 21:25:50 2016 marc brout
*/

#include "wolf.h"

void		simple_tap(t_param *arg)
{
  const bool	*k;

  k = bunny_get_keyboard();
  if (k[arg->INPUT->key[0]])
    {
      if (arg->speedy < 9)
	arg->speedy += 3;
      move(arg, 0, 0.1);
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
      if (keysym == BKS_B && state == GO_DOWN)
	{
	  if (arg->inter.life.life > 25)
	    {
	      arg->inter.life.life -= 25;
	      arg->inter.life.pos_limit.x = (arg->inter.life.life * 3 * arg->WIDTH) / 1000;
	    }
	  else
	    {
	      arg->inter.life.pos_limit.x = (arg->WIDTH / 75) - 1;
	      arg->inter.life.end = 1;
	      arg->inter.life.life = 0;
	    }
	}
      if (keysym == BKS_N && state == GO_DOWN && arg->inter.life.nb_heart > 1)
	{
	  arg->inter.life.life = 100;
	  arg->inter.life.nb_heart--;
	  arg->inter.life.end = 0;
	  arg->inter.life.pos_life.x = (3 * arg->WIDTH) / 10 - 1;
	}
      if (keysym == BKS_T && state == GO_DOWN && arg->inter.bullet.nb_bullet > 0)
	{
	  arg->inter.bullet.nb_bullet--;
	  arg->inter.gun.shoot = 1;
	  arg->inter.gun.check = 3;
	}
      if (keysym == BKS_R && state == GO_DOWN)
	{
	  arg->inter.gun.check_r = 12;
	}
      simple_tap(arg);
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
    arg->curlvl += 1;
  return (cas);
}

int		next_casey(t_param *arg, double val)
{
  int		cas;

  if ((cas = arg->lvl[arg->curlvl].map
       [(int)(arg->lvl[arg->curlvl].playery + val)]
       [(int)(arg->lvl[arg->curlvl].playerx)]) == 3 &&
      (arg->curlvl < (arg->nblvl - 1)))
    arg->curlvl += 1;
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
