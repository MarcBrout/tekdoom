/*
** draw_gunshot.c for draw_gunshot in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 14:29:22 2016 maud marel
** Last update Wed Jan 27 06:52:38 2016 maud marel
*/

#include "tekdoom.h"

void	draw_gunshot(t_param *arg)
{
  if (arg->inter.gun.check_r == 3)
    draw_shoot(arg, arg->inter.gun.gun_shoot2);
  if (arg->inter.gun.check_r == 2)
    draw_shoot(arg, arg->inter.gun.gun_shoot3);
  if (arg->inter.gun.check_r == 1)
    {
      draw_shoot(arg, arg->inter.gun.gun_shoot1);
      arg->inter.gun.check_r = 0;
    }
  if (arg->inter.gun.check_r > 1)
    arg->inter.gun.check_r--;
}

int	check_color3(t_param *arg, int i)
{
  int   r;
  int   b;
  int   g;

  r = arg->inter.gun.color[i].full & 0xFF;
  g = (arg->inter.gun.color[i].full >> 8) & 0xFF;
  b = (arg->inter.gun.color[i].full >> 16) & 0xFF;
  if ((r >= 100 && r <= 150) && (b >= 100 && b <= 150) && g == 0)
    return (1);
  return (0);
}
