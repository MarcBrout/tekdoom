/*
** draw_scope.c for draw_scope in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 22:47:14 2016 maud marel
** Last update Tue Jan 26 23:12:57 2016 maud marel
*/

#include "tekdoom.h"

void			draw_scope(t_param *arg)
{
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  arg->inter.gun.color = (t_color*)arg->inter.gun.scope->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.gun.scope->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.gun.scope->clipable.clip_width)
	  {
	    end .x = (arg->WIDTH
		      - arg->inter.gun.scope->clipable.clip_width)
	    / 2 + pos.x;
	    end.y = (arg->HEIGHT
		     - arg->inter.gun.scope->clipable.clip_height)
	    / 2 + pos.y;
	    if (check_color4(arg, i) == 0)
	      tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
	    pos.x++;
	    i++;
	  }
      pos.y++;
    }
}

int	check_color4(t_param *arg, int i)
{
  int	r;
  int   b;
  int   g;

  r = arg->inter.gun.color[i].full & 0xFF;
  g = (arg->inter.gun.color[i].full >> 8) & 0xFF;
  b = (arg->inter.gun.color[i].full >> 16) & 0xFF;
  if (r == 255 && b == 255 && g == 255)
    return (1);
  return (0);
}
