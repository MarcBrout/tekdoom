/*
** free.c for free in /home/duhieu_b/infographie/rendu/gfx_tekdoom/wolf_to_the_rescue
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Jan 27 05:29:03 2016 benjamin duhieu
** Last update Wed Jan 27 07:53:54 2016 benjamin duhieu
*/

#include "tekdoom.h"

void	free_other(t_param *arg)
{
  bunny_free(arg->wm.ydep);
  bunny_free(arg->inter.gun.gun_shoot1);
  bunny_free(arg->inter.gun.gun_shoot2);
  bunny_free(arg->inter.gun.gun_shoot3);
  bunny_free(arg->inter.gun.reload1);
  bunny_free(arg->inter.gun.reload2);
  bunny_free(arg->inter.gun.reload3);
  bunny_free(arg->inter.gun.punch1);
  bunny_free(arg->inter.gun.punch2);
  bunny_free(arg->inter.gun.punch3);
  bunny_free(arg->inter.gun.scope);
  bunny_free(arg->inter.gun.biggun1);
  bunny_free(arg->inter.gun.biggun2);
  bunny_free(arg->inter.gun.biggun3);
  bunny_free(arg->inter.gun.biggun4);
  bunny_free(arg->inter.gun.biggun5);
  bunny_free(arg->inter.gun.biggun6);
  bunny_free(arg->inter.gun.knife1);
  bunny_free(arg->inter.gun.knife2);
  bunny_free(arg->inter.gun.knife3);
}
