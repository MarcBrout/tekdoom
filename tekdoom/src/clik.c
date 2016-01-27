/*
** cliK.c for clik in
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Jan 27 00:48:48 2016 benjamin duhieu
** Last update Wed Jan 27 06:51:12 2016 benjamin duhieu
*/

#include "tekdoom.h"

void	no_cac(t_param *arg)
{
  if (arg->inter.gun.i == 1 && arg->inter.bullet.nb_bullet > 0)
    {
      bunny_sound_play(arg->sound->shotgun);
      bunny_sound_volume(arg->sound->shotgun, arg->data->config->volume);
    }
  if (arg->inter.gun.i == 4)
    {
      bunny_sound_play(arg->sound->knife);
      bunny_sound_volume(arg->sound->knife, arg->data->config->volume);
    }
  if (arg->inter.gun.i == 2)
    {
      bunny_sound_play(arg->sound->bazook);
      bunny_sound_volume(arg->sound->bazook, arg->data->config->volume);
    }
  if (arg->inter.gun.i == 3)
    {
      bunny_sound_play(arg->sound->sulf);
      bunny_sound_volume(arg->sound->sulf, arg->data->config->volume);
    }
}

void	cac(t_param *arg, int cac)
{
  if (arg->inter.gun.i == 0)
    {
      cac = rand() % 2;
      if (!cac)
	{
	  bunny_sound_play(arg->sound->cac);
	  bunny_sound_volume(arg->sound->cac, arg->data->config->volume);
	}
      else
	{
	  bunny_sound_play(arg->sound->cac2);
	  bunny_sound_volume(arg->sound->cac2,
			     arg->data->config->volume);
	}
    }
}

t_bunny_response		main_click(UNUSED t_bunny_event_state state,
					   UNUSED t_bunny_mousebutton button,
					   void	*data)
{
  const bool			*mouse;
  t_param			*arg;
  int				cc;

  arg = data;
  cc = 0;
  mouse = bunny_get_mouse_button();
  if (mouse[BMB_LEFT])
    {
      no_cac(arg);
      cac(arg, cc);
      action_weapon(arg);
    }
  return (GO_ON);
}
