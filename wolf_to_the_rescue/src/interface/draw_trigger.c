/*
** draw_game_over.c for draw_game_over in /home/marel_m/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jan 23 18:35:13 2016 maud marel
** Last update Mon Jan 25 14:35:21 2016 maud marel
*/

#include "wolf.h"

int			draw_game_over(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.game_over->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.trigger.game_over->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.trigger.game_over->clipable.clip_width)
	{
	  end.x = (WIDTH - arg->inter.trigger.game_over->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - arg->inter.trigger.game_over->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(arg->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_last_chance(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.lastchance->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.trigger.lastchance->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.trigger.lastchance->clipable.clip_width)
	{
	  end.x = (WIDTH - arg->inter.trigger.lastchance->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - arg->inter.trigger.lastchance->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(arg->inter.pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_try_again(t_param *arg)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)arg->inter.trigger.try_again->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.trigger.try_again->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.trigger.try_again->clipable.clip_width)
	{
	  end.x = (WIDTH - arg->inter.trigger.try_again->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - arg->inter.trigger.try_again->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(arg->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}
