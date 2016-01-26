/*
** draw_gunshot.c for draw_gunshot in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 14:29:22 2016 maud marel
** Last update Tue Jan 26 22:10:59 2016 maud marel
*/

#include "tekdoom.h"

void	draw_gunshot(t_param *arg)
{
  if (arg->inter.gun.check == 3)
    draw_gunshot2(arg);
  if (arg->inter.gun.check == 2)
    {
      draw_gunshot3(arg);
    }
  if (arg->inter.gun.check == 1)
    {
      draw_gunshot1(arg);
      arg->inter.gun.shoot = 0;
    }
  if (arg->inter.gun.check > 1)
    arg->inter.gun.check--;
}

void			draw_gunshot1(t_param *arg)
{
  t_bunny_position	end;
  t_bunny_position	pos;
  int			i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.gun_shoot1->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.gun_shoot1->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.gun_shoot1->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.gun.gun_shoot1->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.gun.gun_shoot1->clipable.clip_height) + pos.y;
	  if (check_color3(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_gunshot2(t_param *arg)
{
  t_bunny_position	end;
  t_bunny_position	pos;
  int			i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.gun_shoot2->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.gun_shoot2->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.gun_shoot2->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.gun.gun_shoot2->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.gun.gun_shoot2->clipable.clip_height) + pos.y;
	  if (check_color3(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_gunshot3(t_param *arg)
{
  t_bunny_position	end;
  t_bunny_position	pos;
  int			i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.gun_shoot3->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.gun_shoot3->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.gun_shoot3->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.gun.gun_shoot3->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.gun.gun_shoot3->clipable.clip_height) + pos.y;
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
