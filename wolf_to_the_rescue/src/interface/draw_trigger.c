/*
** draw_game_over.c for draw_game_over in /home/marel_m/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jan 23 18:35:13 2016 maud marel
** Last update Wed Jan 27 02:49:24 2016 maud marel
*/

#include "tekdoom.h"

void			draw_game_over(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.game_over->pixels;
  pos.y = -1;
  i = 0;
  while (++pos.y < arg->inter.trigger.game_over->clipable.clip_height)
    {
      pos.x = -1;
      while (++pos.x < arg->inter.trigger.game_over->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.trigger.game_over->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.trigger.game_over->clipable.clip_height)
	    / 2 + pos.y;
	  if (check_color(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &color[i]);
	  i++;
	}
    }
}

void			draw_last_chance(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.lastchance->pixels;
  pos.y = -1;
  i = 0;
  while (++pos.y < arg->inter.trigger.lastchance->clipable.clip_height)
    {
      pos.x = -1;
      while (++pos.x < arg->inter.trigger.lastchance->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.trigger.lastchance->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.trigger.lastchance->clipable.clip_height)
	    / 2 + pos.y;
	  if (check_color(arg, i) == 0)
	    tekpixel2(arg->inter.pix, &end, &color[i]);
	  i++;
	}
    }
}

void			draw_try_again(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.try_again->pixels;
  pos.y = -1;
  i = 0;
  while (++pos.y < arg->inter.trigger.try_again->clipable.clip_height)
    {
      pos.x = -1;
      while (++pos.x < arg->inter.trigger.try_again->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - arg->inter.trigger.try_again->clipable.clip_width)
	    / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - arg->inter.trigger.try_again->clipable.clip_height)
	    / 2 + pos.y;
	  if (check_color(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &color[i]);
	  i++;
	}
    }
}
