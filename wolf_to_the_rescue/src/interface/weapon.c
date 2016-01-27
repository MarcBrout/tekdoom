/*
** weapon.c for weapon in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 27 01:26:47 2016 maud marel
** Last update Wed Jan 27 02:19:12 2016 maud marel
*/

#include "tekdoom.h"

void	weapon(t_param *arg)
{
  if (arg->inter.gun.i == 0)
    arg->inter.bullet.nb_bullet = 0;
  if (arg->inter.gun.i == 1)
    arg->inter.bullet.nb_bullet = 5;
  if (arg->inter.gun.i == 2)
    arg->inter.bullet.nb_bullet = 10;
}

void	action_weapon(t_param *arg)
{
  if (arg->inter.gun.i == 0)
    {
      arg->inter.gun.check_p = 12;
    }
  if (arg->inter.gun.i == 1 && arg->inter.bullet.nb_bullet > 0)
    {
      arg->inter.bullet.nb_bullet--;
      arg->inter.gun.check_r = 3;
    }
  if (arg->inter.gun.i == 2 && arg->inter.bullet.nb_bullet > 0)
    {
      arg->inter.bullet.nb_bullet--;
      arg->inter.gun.check_b = 33;
    }
}

void	action_reload(t_param *arg)
{
  if (arg->inter.gun.i == 1 && arg->inter.bullet.nb_bullet != 5)
    {
      arg->inter.gun.check_r = 15;
      arg->inter.bullet.nb_bullet = 5;
    }
  if (arg->inter.gun.i == 2 && arg->inter.bullet.nb_bullet != 10)
    {
      arg->inter.gun.check_b = 33;
      arg->inter.bullet.nb_bullet = 10;
    }
}

void	draw_action(t_param *arg)
{
  if (arg->inter.gun.i == 0)
    {
      if (arg->inter.gun.check_p != 0)
	draw_punch(arg);
      else
	draw_shoot(arg, arg->inter.gun.punch1);
    }
  if (arg->inter.gun.i == 1)
    {
      if (arg->inter.gun.check_r != 0)
	draw_gunshot(arg);
      else
	draw_shoot(arg, arg->inter.gun.gun_shoot1);
    }
  if (arg->inter.gun.i == 2)
    {
      if (arg->inter.gun.check_b != 0)
	draw_biggun(arg);
      else
	draw_shoot1(arg, arg->inter.gun.biggun1);
    }
}
