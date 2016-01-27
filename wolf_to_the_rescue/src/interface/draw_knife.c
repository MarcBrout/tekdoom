/*
** draw_knife.c for draw_knife in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 27 05:31:43 2016 maud marel
** Last update Wed Jan 27 06:52:53 2016 maud marel
*/

#include "tekdoom.h"

void	draw_knife(t_param *arg)
{
  if (arg->inter.gun.check_k > 12 && arg->inter.gun.check_k <= 15)
    draw_shoot(arg, arg->inter.gun.knife1);
  if (arg->inter.gun.check_k > 9 && arg->inter.gun.check_k <= 12)
    draw_shoot(arg, arg->inter.gun.knife2);
  if (arg->inter.gun.check_k > 6 && arg->inter.gun.check_k <= 9)
    draw_shoot(arg, arg->inter.gun.knife3);
  if (arg->inter.gun.check_k > 3 && arg->inter.gun.check_k <= 6)
    draw_shoot(arg, arg->inter.gun.knife2);
  if (arg->inter.gun.check_k > 0 && arg->inter.gun.check_k <= 3)
    {
      draw_shoot(arg, arg->inter.gun.knife1);
      arg->inter.gun.check_k = 0;
    }
  if (arg->inter.gun.check_k > 0)
    arg->inter.gun.check_k--;
}
