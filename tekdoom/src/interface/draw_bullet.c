/*
** draw_init_bullet.c for draw_init_bullet in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:08:42 2016 Maud MAREL
** Last update Wed Jan 27 05:22:55 2016 maud marel
*/

#include "tekdoom.h"

void			draw_bullet(t_param *arg)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			bullet;

  nb = 5;
  bullet = arg->inter.bullet.nb_bullet + 1;
  arg->inter.bullet.color = (t_color*)arg->inter.bullet.bullet->pixels;
  while (--bullet > 0)
    {
      draw_bullet2(arg, pos, end, nb);
      nb--;
    }
}

void	draw_bullet2(t_param *arg, t_bunny_position pos,
		     t_bunny_position end, int nb)
{
  int	i;

  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.bullet.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.bullet.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (arg->WIDTH / 10)
	    + (arg->WIDTH / 5)
	    - (nb * arg->inter.bullet.bullet->clipable.clip_width);
	  end.y = (arg->HEIGHT
		   - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) + pos.y
	    - arg->inter.bullet.bullet->clipable.clip_height - 3;
	  if (check_color2(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &arg->inter.bullet.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

int	check_color2(t_param *arg, int i)
{
  int   r;
  int   b;
  int   g;

  r = arg->inter.bullet.color[i].full & 0xFF;
  g = (arg->inter.bullet.color[i].full >> 8) & 0xFF;
  b = (arg->inter.bullet.color[i].full >> 16) & 0xFF;
  if (r == 0 && b == 0 && g == 255)
    return (1);
  return (0);
}
