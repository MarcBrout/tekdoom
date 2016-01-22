/*
** draw_init_bullet.c for draw_init_bullet in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:08:42 2016 Maud MAREL
** Last update Fri Jan 22 13:40:22 2016 Maud MAREL
*/

#include "lifebar.h"

int			draw_bullet(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  t_color               *color;
  int                   i;
  int			nb;
  int			bullet;

  nb = 5;
  bullet = data->bullet.nb_bullet + 1;
  while (--bullet > 0)
    {
      pos.x = 0;
      pos.y = 0;
      if ((data->life.bullet = bunny_load_pixelarray("bullet.png")) == NULL)
	return (-1);
      color = (t_color*)data->life.bullet->pixels;
      i = 0;
      while (pos.y < data->life.bullet->clipable.clip_height)
	{
	  pos.x = 0;
	  while (pos.x < data->life.bullet->clipable.clip_width)
	    {
	      end.x = pos.x + (WIDTH / 10)
		+ (WIDTH / 5) - (nb * data->life.bullet->clipable.clip_width);
	      end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
		- data->life.bullet->clipable.clip_height - 3;
	      tekpixel2(data->pix, &end, &color[i]);
	      pos.x++;
	      i++;
	    }
	  pos.y++;
	}
      nb--;
    }
  if (data->bullet.nb_bullet < 5)
    draw_bullet_else(data, bullet, nb);
  return (0);
}

void			draw_bullet_else(t_data *data, int bullet, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  bullet = 5 - data->bullet.nb_bullet;
  color = (t_color*)data->pix->pixels;
  while (bullet > 0)
    {
      pos.y = -1;
      while (++pos.y < data->life.bullet->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < data->life.bullet->clipable.clip_width)
	    {
	      end.x = pos.x + (WIDTH / 10)
		+ (WIDTH / 5) - (nb * data->life.bullet->clipable.clip_width);
	      end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
		- data->life.bullet->clipable.clip_height - 3;
	      tekpixel2(data->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb--;
      bullet--;
    }
}
