/*
** draw_init_bullet.c for draw_init_bullet in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:08:42 2016 Maud MAREL
** Last update Wed Jan 20 16:10:03 2016 Maud MAREL
*/

#include "lifebar.h"

int                     draw_bullet_start(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  t_color               *color;
  int                   i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
    return (-1);
  color = (t_color*)data->life.bullet->pixels;
  while (pos.y < data->life.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10) + (WIDTH / 5) - data->life.bullet->clipable.clip_width;
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.bullet->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  pos.x = 0;
  pos.y = 0;
  i = 0;
  if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
    return (-1);
  color = (t_color*)data->life.bullet->pixels;
  while (pos.y < data->life.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10) + (WIDTH / 5) - (2 * data->life.bullet->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.bullet->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  pos.x = 0;
  pos.y = 0;
  i = 0;
  if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
    return (-1);
  color = (t_color*)data->life.bullet->pixels;
  while (pos.y < data->life.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10) + (WIDTH / 5) - (3 * data->life.bullet->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.bullet->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  pos.x = 0;
  pos.y = 0;
  i = 0;
  if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
    return (-1);
  color = (t_color*)data->life.bullet->pixels;
  while (pos.y < data->life.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10) + (WIDTH / 5) - (4 * data->life.bullet->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.bullet->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  pos.x = 0;
  pos.y = 0;
  i = 0;
  if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
    return (-1);
  color = (t_color*)data->life.bullet->pixels;
  while (pos.y < data->life.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10) + (WIDTH / 5) - (5 * data->life.bullet->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.bullet->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
  return (0);
}
