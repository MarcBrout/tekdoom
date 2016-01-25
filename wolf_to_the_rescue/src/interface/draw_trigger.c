/*
** draw_game_over.c for draw_game_over in /home/marel_m/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jan 23 18:35:13 2016 maud marel
** Last update Mon Jan 25 13:55:00 2016 maud marel
*/

#include "wolf.h"

int			draw_game_over(t_interface *inter)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)inter->trigger.game_over->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < inter->trigger.game_over->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < inter->trigger.game_over->clipable.clip_width)
	{
	  end.x = (WIDTH - inter->trigger.game_over->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - inter->trigger.game_over->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(inter->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_last_chance(t_interface *inter)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)inter->trigger.lastchance->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < inter->trigger.lastchance->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < inter->trigger.lastchance->clipable.clip_width)
	{
	  end.x = (WIDTH - inter->trigger.lastchance->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - inter->trigger.lastchance->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(inter->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_try_again(t_interface *inter)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)inter->trigger.try_again->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < inter->trigger.try_again->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < inter->trigger.try_again->clipable.clip_width)
	{
	  end.x = (WIDTH - inter->trigger.try_again->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - inter->trigger.try_again->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(inter->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}
