/*
** draw_reload.c for draw_reload in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 15:30:56 2016 maud marel
** Last update Tue Jan 26 15:58:41 2016 maud marel
*/

#include "wolf.h"

void	draw_reload(t_param *arg)
{
  if (arg->inter.gun.check_r > 9 &&arg->inter.gun.check_r <= 12)
    draw_reload1(arg);
  if (arg->inter.gun.check_r > 6 &&arg->inter.gun.check_r <= 9)
    draw_reload2(arg);
  if (arg->inter.gun.check_r > 3 &&arg->inter.gun.check_r <= 6)
    draw_reload3(arg);
  if (arg->inter.gun.check_r > 0 &&arg->inter.gun.check_r <= 3)
    {
      arg->inter.bullet.nb_bullet = 5;
      draw_gunshot1(arg);
    }
  if (arg->inter.gun.check_r > 0)
    arg->inter.gun.check_r--;
}

void                    draw_reload1(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.reload1->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.reload1->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.reload1->clipable.clip_width)
        {
          end.x = (arg->WIDTH - arg->inter.gun.reload1->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT - arg->inter.gun.reload1->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
}

void                    draw_reload2(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.reload2->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.reload2->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.reload2->clipable.clip_width)
        {
          end.x = (arg->WIDTH - arg->inter.gun.reload2->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT - arg->inter.gun.reload2->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
}

void                    draw_reload3(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.reload3->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.reload3->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.reload3->clipable.clip_width)
        {
          end.x = (arg->WIDTH - arg->inter.gun.reload3->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT - arg->inter.gun.reload3->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
}
