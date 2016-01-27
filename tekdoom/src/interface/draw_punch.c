/*
** draw_punch.c for draw_punch in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 19:00:26 2016 maud marel
** Last update Wed Jan 27 06:53:54 2016 maud marel
*/

#include "tekdoom.h"

void	draw_punch(t_param *arg)
{
  if (arg->inter.gun.check_p > 12 && arg->inter.gun.check_p <= 15)
    draw_shoot(arg, arg->inter.gun.punch1);
  if (arg->inter.gun.check_p > 9 && arg->inter.gun.check_p <= 12)
    draw_shoot(arg, arg->inter.gun.punch2);
  if (arg->inter.gun.check_p > 6 && arg->inter.gun.check_p <= 9)
    draw_shoot(arg, arg->inter.gun.punch3);
  if (arg->inter.gun.check_p > 3 && arg->inter.gun.check_p <= 6)
    draw_shoot(arg, arg->inter.gun.punch2);
  if (arg->inter.gun.check_p > 0 && arg->inter.gun.check_p <= 3)
    {
      draw_shoot(arg, arg->inter.gun.punch1);
      arg->inter.gun.check_p = 0;
    }
  if (arg->inter.gun.check_p > 0)
    arg->inter.gun.check_p--;
}
