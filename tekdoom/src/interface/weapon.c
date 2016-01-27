/*
** weapon.c for weapon in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 27 01:26:47 2016 maud marel
** Last update Wed Jan 27 06:54:33 2016 maud marel
*/

#include "tekdoom.h"

void	weapon(t_param *arg)
{
  if (arg->inter.gun.i == 0 || arg->inter.gun.i == 4)
    arg->inter.bullet.nb_bullet = 0;
  if (arg->inter.gun.i == 1 || arg->inter.gun.i == 2 || arg->inter.gun.i == 3)
    arg->inter.bullet.nb_bullet = 5;
}

void	action_weapon(t_param *arg)
{
  if (arg->inter.gun.i == 0)
    arg->inter.gun.check_p = 12;
  if (arg->inter.gun.i == 1 && arg->inter.bullet.nb_bullet > 0)
    {
      arg->inter.bullet.nb_bullet--;
      arg->inter.gun.check_r = 3;
    }
  if (arg->inter.gun.i == 2)
    arg->inter.gun.check_b = 24;
  if (arg->inter.gun.i == 3)
    arg->inter.gun.check_sul = 39;
  if (arg->inter.gun.i == 4)
    arg->inter.gun.check_k = 15;
}

void	action_reload(t_param *arg)
{
  if (arg->inter.gun.i == 1 && arg->inter.bullet.nb_bullet != 5)
    {
      arg->inter.gun.check_s = 1;
      arg->inter.gun.check_r = 15;
      arg->inter.bullet.nb_bullet = 5;
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
      if (arg->inter.gun.check_s == 1)
	draw_reload(arg);
      else
	{
	  if (arg->inter.gun.check_r != 0)
	    draw_gunshot(arg);
	  else
	    draw_shoot(arg, arg->inter.gun.gun_shoot1);
	}
    }
  draw_action2(arg);
}

void	draw_action2(t_param *arg)
{
  if (arg->inter.gun.i == 2)
    {
      if (arg->inter.gun.check_b != 0)
	draw_biggun(arg);
      else
	draw_shoot(arg, arg->inter.gun.biggun1);
    }
  if (arg->inter.gun.i == 3)
    {
      if (arg->inter.gun.check_sul != 0)
	draw_sulf(arg);
      else
	draw_shoot(arg, arg->inter.gun.sulf0);
    }
  if (arg->inter.gun.i == 4)
    {
      if (arg->inter.gun.check_k != 0)
	draw_knife(arg);
      else
	draw_shoot(arg, arg->inter.gun.knife1);
    }
}
