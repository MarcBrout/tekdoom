/*
** draw_game_over.c for draw_game_over in /home/marel_m/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jan 23 18:35:13 2016 maud marel
** Last update Sun Jan 24 23:07:54 2016 maud marel
*/

#include "interface.h"

int			draw_game_over(t_data *data)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)data->trigger.game_over->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < data->trigger.game_over->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->trigger.game_over->clipable.clip_width)
	{
	  end.x = (WIDTH - data->trigger.game_over->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - data->trigger.game_over->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_last_chance(t_data *data)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)data->trigger.lastchance->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < data->trigger.lastchance->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->trigger.lastchance->clipable.clip_width)
	{
	  end.x = (WIDTH - data->trigger.lastchance->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - data->trigger.lastchance->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}

int			draw_try_again(t_data *data)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;
  int			i;

  color = (t_color*)data->trigger.try_again->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < data->trigger.try_again->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->trigger.try_again->clipable.clip_width)
	{
	  end.x = (WIDTH - data->trigger.try_again->clipable.clip_width) / 2 + pos.x;
	  end.y = (HEIGHT - data->trigger.try_again->clipable.clip_height) / 2 + pos.y;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}
