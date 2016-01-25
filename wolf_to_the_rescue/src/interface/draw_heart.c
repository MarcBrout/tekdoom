/*
** draw_heart.c for draw_heart in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:47:07 2016 Maud MAREL
** Last update Mon Jan 25 15:09:04 2016 Mathieu Sauvau
*/

#include "wolf.h"

int			draw_heart(t_param *arg)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			heart;

  nb = 0;
  heart = arg->inter.life.nb_heart + 1;
  if ((arg->inter.life.heart = bunny_load_pixelarray("pictures/heart.png")) == NULL)
    return (-1);
  arg->inter.life.color = (t_color*)arg->inter.life.heart->pixels;
  while (--heart > 0)
    {
      draw_heart2(arg, pos, end, nb);
      nb++;
    }
  if (arg->inter.life.nb_heart < 3)
    draw_heart_else(arg, heart, nb);
  return (0);
}

void	draw_heart2(t_param *arg, t_bunny_position pos,
		    t_bunny_position end, int nb)
{
  int	i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.life.heart->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.life.heart->clipable.clip_width)
	{
	  end.x = (arg->WIDTH / 75) + pos.x
	    + (nb * arg->inter.life.heart->clipable.clip_width);
	  end.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) + pos.y
	    - arg->inter.life.heart->clipable.clip_height - 3;
	  tekpixel2(arg->pix, &end, &arg->inter.life.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_heart_else(t_param *arg, int heart, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  heart = 3 - arg->inter.life.nb_heart;
  color = (t_color*)arg->inter.pix->pixels;
  while (heart > 0)
    {
      pos.y = -1;
      while (++pos.y < arg->inter.life.heart->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < arg->inter.life.heart->clipable.clip_width)
	    {
	      end.x = (arg->WIDTH / 75) + pos.x
		+ (nb * arg->inter.life.heart->clipable.clip_width);
	      end.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) + pos.y
		- arg->inter.life.heart->clipable.clip_height - 3;
	      tekpixel2(arg->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb++;
      heart--;
    }
}
