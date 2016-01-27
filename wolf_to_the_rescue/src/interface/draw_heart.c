/*
** draw_heart.c for draw_heart in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:47:07 2016 Maud MAREL
** Last update Tue Jan 26 22:11:08 2016 maud marel
*/

#include "tekdoom.h"

void			draw_heart(t_param *arg)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			heart;

  nb = 0;
  heart = arg->inter.life.nb_heart + 1;
  arg->inter.life.color = (t_color*)arg->inter.life.heart->pixels;
  while (--heart > 0)
    {
      draw_heart2(arg, pos, end, nb);
      nb++;
    }
}

void		draw_heart2(t_param *arg, t_bunny_position pos,
			    t_bunny_position end, int nb)
{
  int		i;

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
	  if (check_color(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &arg->inter.life.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

int	check_color(t_param *arg, int i)
{
  int	r;
  int	b;
  int	g;

  r = arg->inter.life.color[i].full & 0xFF;
  g = (arg->inter.life.color[i].full >> 8) & 0xFF;
  b = (arg->inter.life.color[i].full >> 16) & 0xFF;
  if (r == 0 && b == 0 && g == 255)
    return (1);
  return (0);
}
