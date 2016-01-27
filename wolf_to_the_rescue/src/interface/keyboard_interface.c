/*
** keyboard_interface.c for keyboard_interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 21:38:59 2016 maud marel
** Last update Wed Jan 27 05:31:13 2016 maud marel
*/

#include "tekdoom.h"

void		keyboard_interface(t_param *arg)
{
  const bool	*k;

  k = bunny_get_keyboard();
  if (k[arg->INPUT->key[5]] && arg->inter.bullet.nb_bullet != 5
      && arg->inter.gun.i == 1)
    {
      action_reload(arg);
      bunny_sound_play(arg->sound->reload);
    }
}

void	keyboard_interface2(t_bunny_event_state state,
			    t_bunny_keysym keysym, t_param *arg)
{
  if (keysym == BKS_B && state == GO_DOWN)
    {
      if (arg->inter.life.life > 25)
  	{
  	  arg->inter.life.life -= 25;
  	  arg->inter.life.pos_limit.x =
	    (arg->inter.life.life * 3 * arg->WIDTH) / 1000;
  	}
      else
  	{
  	  arg->inter.life.pos_limit.x = (arg->WIDTH / 75) - 1;
  	  arg->inter.life.end = 1;
  	  arg->inter.life.life = 0;
  	}
    }
  keyboard_interface3(state, keysym, arg);
}

void	keyboard_interface3(t_bunny_event_state state,
			    t_bunny_keysym keysym, t_param *arg)
{
  if (keysym == BKS_F && state == GO_DOWN)
    {
      if (arg->inter.gun.i < 4)
	arg->inter.gun.i++;
      else
	arg->inter.gun.i = 0;
      weapon(arg);
    }
}
