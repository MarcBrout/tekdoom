/*
** draw_heart.c for draw_heart in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:47:07 2016 Maud MAREL
** Last update Fri Jan 22 15:14:17 2016 maud marel
*/

#include "interface.h"

int			draw_heart(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			heart;

  nb = 0;
  heart = data->life.nb_heart + 1;
  if ((data->life.heart = bunny_load_pixelarray("pictures/heart.png")) == NULL)
    return (-1);
  data->life.color = (t_color*)data->life.heart->pixels;
  while (--heart > 0)
    {
      draw_heart2(data, pos, end, nb);
      nb++;
    }
  if (data->life.nb_heart < 3)
    draw_heart_else(data, heart, nb);
  return (0);
}

void	draw_heart2(t_data *data, t_bunny_position pos,
		    t_bunny_position end, int nb)
{
  int	i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (pos.y < data->life.heart->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < data->life.heart->clipable.clip_width)
	{
	  end.x = (WIDTH / 75) + pos.x
	    + (nb * data->life.heart->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - data->life.heart->clipable.clip_height - 3;
	  tekpixel2(data->pix, &end, &data->life.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_heart_else(t_data *data, int heart, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  heart = 3 - data->life.nb_heart;
  color = (t_color*)data->pix->pixels;
  while (heart > 0)
    {
      pos.y = -1;
      while (++pos.y < data->life.heart->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < data->life.heart->clipable.clip_width)
	    {
	      end.x = (WIDTH / 75) + pos.x
		+ (nb * data->life.heart->clipable.clip_width);
	      end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
		- data->life.heart->clipable.clip_height - 3;
	      tekpixel2(data->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb++;
      heart--;
    }
}
