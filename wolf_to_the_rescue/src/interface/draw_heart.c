/*
** draw_heart.c for draw_heart in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:47:07 2016 Maud MAREL
** Last update Mon Jan 25 14:05:00 2016 maud marel
*/

#include "wolf.h"

int			draw_heart(t_interface *inter)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			heart;

  nb = 0;
  heart = inter->life.nb_heart + 1;
  if ((inter->life.heart = bunny_load_pixelarray("pictures/heart.png")) == NULL)
    return (-1);
  inter->life.color = (t_color*)inter->life.heart->pixels;
  while (--heart > 0)
    {
      draw_heart2(inter, pos, end, nb);
      nb++;
    }
  if (inter->life.nb_heart < 3)
    draw_heart_else(inter, heart, nb);
  return (0);
}

void	draw_heart2(t_interface *inter, t_bunny_position pos,
		    t_bunny_position end, int nb)
{
  int	i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (pos.y < inter->life.heart->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < inter->life.heart->clipable.clip_width)
	{
	  end.x = (WIDTH / 75) + pos.x
	    + (nb * inter->life.heart->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - inter->life.heart->clipable.clip_height - 3;
	  tekpixel2(inter->pix, &end, &inter->life.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_heart_else(t_interface *inter, int heart, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  heart = 3 - inter->life.nb_heart;
  color = (t_color*)inter->pix->pixels;
  while (heart > 0)
    {
      pos.y = -1;
      while (++pos.y < inter->life.heart->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < inter->life.heart->clipable.clip_width)
	    {
	      end.x = (WIDTH / 75) + pos.x
		+ (nb * inter->life.heart->clipable.clip_width);
	      end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
		- inter->life.heart->clipable.clip_height - 3;
	      tekpixel2(inter->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb++;
      heart--;
    }
}
