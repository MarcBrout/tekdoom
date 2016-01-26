/*
** keyboard_interface.c for keyboard_interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 21:38:59 2016 maud marel
** Last update Tue Jan 26 22:11:59 2016 maud marel
*/

#include "tekdoom.h"

void		keyboard_interface(t_param *arg)
{
  const bool	*k;

  k = bunny_get_keyboard();
  if (k[arg->INPUT->key[7]])
    {
      if (arg->inter.bullet.nb_bullet > 0 && arg->inter.gun.shoot == 0)
	{
	  bunny_sound_play(arg->inter.gun.music);
	  arg->inter.bullet.nb_bullet--;
	  arg->inter.gun.shoot = 1;
	  arg->inter.gun.check = 3;
	}
      else if (arg->inter.gun.punch == 1)
	arg->inter.gun.check_p = 12;
    }
    if (k[arg->INPUT->key[5]] && arg->inter.gun.shoot != 2
	&& arg->inter.bullet.nb_bullet != 5)
    {
      arg->inter.gun.check_r = 15;
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
  if (keysym == BKS_N && state == GO_DOWN && arg->inter.life.nb_heart > 1)
    {
      arg->inter.life.life = 100;
      arg->inter.life.nb_heart--;
      arg->inter.life.end = 0;
      arg->inter.life.pos_life.x = (3 * arg->WIDTH) / 10 - 1;
    }
  if (keysym == BKS_F && state == GO_DOWN)
    {
      if (arg->inter.gun.shoot == 0)
	{
	  arg->inter.gun.shoot = 2;
	  arg->inter.gun.punch = 1;
	}
      else
	{
	  arg->inter.gun.shoot = 0;
	  arg->inter.gun.punch = 0;
	}
    }
}
