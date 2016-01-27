/*
** draw_sulf.c for draw_sulf in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 27 04:24:24 2016 maud marel
** Last update Wed Jan 27 04:41:07 2016 maud marel
*/

#include "tekdoom.h"

void	draw_sulf(t_param *arg)
{
  if (arg->inter.gun.check_sul > 36 && arg->inter.gun.check_sul <= 39)
    draw_shoot1(arg, arg->inter.gun.sulf0);
  if (arg->inter.gun.check_sul > 30 && arg->inter.gun.check_sul <= 36)
    draw_shoot1(arg, arg->inter.gun.sulf1);
  if (arg->inter.gun.check_sul > 27 && arg->inter.gun.check_sul <= 30)
    draw_shoot1(arg, arg->inter.gun.sulf0);
  if (arg->inter.gun.check_sul > 24 && arg->inter.gun.check_sul <= 27)
    draw_shoot1(arg, arg->inter.gun.sulf1);
  if (arg->inter.gun.check_sul > 21 && arg->inter.gun.check_sul <= 24)
    draw_shoot1(arg, arg->inter.gun.sulf2);
  if (arg->inter.gun.check_sul > 18 && arg->inter.gun.check_sul <= 21)
    draw_shoot1(arg, arg->inter.gun.sulf3);
  if (arg->inter.gun.check_sul > 15 && arg->inter.gun.check_sul <= 18)
    draw_shoot1(arg, arg->inter.gun.sulf2);
  if (arg->inter.gun.check_sul > 12 && arg->inter.gun.check_sul <= 15)
    draw_shoot1(arg, arg->inter.gun.sulf3);
  if (arg->inter.gun.check_sul > 9 && arg->inter.gun.check_sul <= 12)
    draw_shoot1(arg, arg->inter.gun.sulf0);
  if (arg->inter.gun.check_sul > 6 && arg->inter.gun.check_sul <= 9)
    draw_shoot1(arg, arg->inter.gun.sulf1);
  if (arg->inter.gun.check_sul > 3 && arg->inter.gun.check_sul <= 6)
    draw_shoot1(arg, arg->inter.gun.sulf0);
  if (arg->inter.gun.check_sul > 0 && arg->inter.gun.check_sul <= 3)
    {
      draw_shoot1(arg, arg->inter.gun.sulf1);
      arg->inter.gun.check_sul = 0;
    }
  if (arg->inter.gun.check_sul > 0)
    arg->inter.gun.check_sul--;
}
