/*
** draw_init_bullet.c for draw_init_bullet in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:08:42 2016 Maud MAREL
** Last update Mon Jan 25 15:08:15 2016 Mathieu Sauvau
*/

#include "wolf.h"

int			draw_bullet(t_param *arg)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			bullet;

  nb = 5;
  bullet = arg->inter.bullet.nb_bullet + 1;
  if ((arg->inter.bullet.bullet
       = bunny_load_pixelarray("pictures/bullet.png")) == NULL)
    return (-1);
  arg->inter.bullet.color = (t_color*)arg->inter.bullet.bullet->pixels;
  while (--bullet > 0)
    {
      draw_bullet2(arg, pos, end, nb);
      nb--;
    }
  if (arg->inter.bullet.nb_bullet < 5)
    draw_bullet_else(arg, bullet, nb);
  return (0);
}

void	draw_bullet2(t_param *arg, t_bunny_position pos,
		     t_bunny_position end, int nb)
{
  int	i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (pos.y < arg->inter.bullet.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < arg->inter.bullet.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (arg->WIDTH / 10)
	    + (arg->WIDTH / 5) - (nb * arg->inter.bullet.bullet->clipable.clip_width);
	  end.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) + pos.y
	    - arg->inter.bullet.bullet->clipable.clip_height - 3;
	  tekpixel2(arg->pix, &end, &arg->inter.bullet.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_bullet_else(t_param *arg, int bullet, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  bullet = 5 - arg->inter.bullet.nb_bullet;
  color = (t_color*)arg->inter.pix->pixels;
  while (bullet > 0)
    {
      pos.y = -1;
      while (++pos.y < arg->inter.bullet.bullet->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < arg->inter.bullet.bullet->clipable.clip_width)
	    {
	      end.x = pos.x + (arg->WIDTH / 10)
		+ (arg->WIDTH / 5) - (nb * arg->inter.bullet.bullet->clipable.clip_width);
	      end.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) + pos.y
		- arg->inter.bullet.bullet->clipable.clip_height - 3;
	      tekpixel2(arg->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb--;
      bullet--;
    }
}
