/*
** draw_init_bullet.c for draw_init_bullet in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface/gameinterface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 20 15:08:42 2016 Maud MAREL
** Last update Mon Jan 25 14:05:19 2016 maud marel
*/

#include "wolf.h"

int			draw_bullet(t_interface *inter)
{
  t_bunny_position      pos;
  t_bunny_position      end;
  int			nb;
  int			bullet;

  nb = 5;
  bullet = inter->bullet.nb_bullet + 1;
  if ((inter->bullet.bullet
       = bunny_load_pixelarray("pictures/bullet.png")) == NULL)
    return (-1);
  inter->bullet.color = (t_color*)inter->bullet.bullet->pixels;
  while (--bullet > 0)
    {
      draw_bullet2(inter, pos, end, nb);
      nb--;
    }
  if (inter->bullet.nb_bullet < 5)
    draw_bullet_else(inter, bullet, nb);
  return (0);
}

void	draw_bullet2(t_interface *inter, t_bunny_position pos,
		     t_bunny_position end, int nb)
{
  int	i;

  pos.x = 0;
  pos.y = 0;
  i = 0;
  while (pos.y < inter->bullet.bullet->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < inter->bullet.bullet->clipable.clip_width)
	{
	  end.x = pos.x + (WIDTH / 10)
	    + (WIDTH / 5) - (nb * inter->bullet.bullet->clipable.clip_width);
	  end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
	    - inter->bullet.bullet->clipable.clip_height - 3;
	  tekpixel2(inter->pix, &end, &inter->bullet.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

void			draw_bullet_else(t_interface *inter, int bullet, int nb)
{
  t_color		*color;
  t_bunny_position	pos;
  t_bunny_position	end;

  bullet = 5 - inter->bullet.nb_bullet;
  color = (t_color*)inter->pix->pixels;
  while (bullet > 0)
    {
      pos.y = -1;
      while (++pos.y < inter->bullet.bullet->clipable.clip_height)
	{
	  pos.x = -1;
	  while (++pos.x < inter->bullet.bullet->clipable.clip_width)
	    {
	      end.x = pos.x + (WIDTH / 10)
		+ (WIDTH / 5) - (nb * inter->bullet.bullet->clipable.clip_width);
	      end.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) + pos.y
		- inter->bullet.bullet->clipable.clip_height - 3;
	      tekpixel2(inter->pix, &end, &color[end.x + end.y]);
	    }
	}
      nb--;
      bullet--;
    }
}
