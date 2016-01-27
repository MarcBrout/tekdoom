/*
** draw_reload.c for draw_reload in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 15:30:56 2016 maud marel
** Last update Wed Jan 27 02:32:41 2016 maud marel
*/

#include "tekdoom.h"

void	draw_reload(t_param *arg)
{
  if (arg->inter.gun.check_r > 12 && arg->inter.gun.check_r <= 15)
    draw_shoot(arg, arg->inter.gun.reload1);
  if (arg->inter.gun.check_r > 9 && arg->inter.gun.check_r <= 12)
    draw_shoot(arg, arg->inter.gun.reload2);
  if (arg->inter.gun.check_r > 6 && arg->inter.gun.check_r <= 9)
    draw_shoot(arg, arg->inter.gun.reload3);
  if (arg->inter.gun.check_r > 3 && arg->inter.gun.check_r <= 6)
    draw_shoot(arg, arg->inter.gun.reload2);
  if (arg->inter.gun.check_r > 0 && arg->inter.gun.check_r <= 3)
    {
      arg->inter.bullet.nb_bullet = 5;
      draw_shoot(arg, arg->inter.gun.reload1);
    }
  if (arg->inter.gun.check_r > 0)
    arg->inter.gun.check_r--;
  if (arg->inter.gun.check_r == 1)
    arg->inter.gun.check_s = 0;
}
