/*
** draw_gunshot.c for draw_gunshot in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 14:29:22 2016 maud marel
** Last update Wed Jan 27 02:47:12 2016 maud marel
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

void	draw_shoot(t_param *arg, t_bunny_pixelarray *shoot)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)shoot->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < shoot->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < shoot->clipable.clip_width)
        {
          end.x = (arg->WIDTH
                   - shoot->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT
                   - shoot->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
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
