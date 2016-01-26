/*
** draw_punch.c for draw_punch in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 19:00:26 2016 maud marel
** Last update Tue Jan 26 22:11:26 2016 maud marel
*/

#include "tekdoom.h"

void	draw_punch(t_param *arg)
{
  if (arg->inter.gun.check_p > 12 && arg->inter.gun.check_p <= 15)
    draw_punch1(arg);
  if (arg->inter.gun.check_p > 9 && arg->inter.gun.check_p <= 12)
    draw_punch2(arg);
  if (arg->inter.gun.check_p > 6 && arg->inter.gun.check_p <= 9)
      draw_punch3(arg);
  if (arg->inter.gun.check_p > 3 && arg->inter.gun.check_p <= 6)
      draw_punch2(arg);
  if (arg->inter.gun.check_p > 0 && arg->inter.gun.check_p <= 3)
    {
      draw_punch1(arg);
      arg->inter.gun.check_p = 0;
    }
  if (arg->inter.gun.check_p > 0)
    arg->inter.gun.check_p--;
 }

void                    draw_punch1(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.punch1->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.punch1->clipable.clip_height)
    {
      pos.x = -1;
      while (++pos.x < arg->inter.gun.punch1->clipable.clip_width)
        {
          end.x = (arg->WIDTH
		   - arg->inter.gun.punch1->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT
		   - arg->inter.gun.punch1->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          i++;
        }
      pos.y++;
    }
}

void			draw_punch2(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.punch2->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.punch2->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.punch2->clipable.clip_width)
        {
          end.x = (arg->WIDTH
		   - arg->inter.gun.punch2->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT
		   - arg->inter.gun.punch2->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
}

void			draw_punch3(t_param *arg)
{
  t_bunny_position      end;
  t_bunny_position      pos;
  int                   i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.punch3->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.punch3->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.punch3->clipable.clip_width)
        {
          end.x = (arg->WIDTH
		   - arg->inter.gun.punch3->clipable.clip_width) / 2 + pos.x;
          end.y = (arg->HEIGHT
		   - arg->inter.gun.punch3->clipable.clip_height) + pos.y;
          if (check_color3(arg, i) == 0)
            tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
          pos.x++;
          i++;
        }
      pos.y++;
    }
}
