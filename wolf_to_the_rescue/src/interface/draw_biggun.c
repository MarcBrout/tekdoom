/*
** draw_biggun.c for draw_biggun in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jan 27 00:43:56 2016 maud marel
** Last update Wed Jan 27 02:46:54 2016 maud marel
*/

#include "tekdoom.h"

void	draw_biggun(t_param *arg)
{
  if (arg->inter.gun.check_b > 30 && arg->inter.gun.check_b <= 33)
    draw_shoot1(arg, arg->inter.gun.biggun1);
  if (arg->inter.gun.check_b > 27 && arg->inter.gun.check_b <= 30)
    draw_shoot1(arg, arg->inter.gun.biggun2);
  if (arg->inter.gun.check_b > 24 && arg->inter.gun.check_b <= 27)
    draw_shoot1(arg, arg->inter.gun.biggun3);
  if (arg->inter.gun.check_b > 21 && arg->inter.gun.check_b <= 24)
    draw_shoot1(arg, arg->inter.gun.biggun4);
  if (arg->inter.gun.check_b > 18 && arg->inter.gun.check_b <= 21)
    draw_shoot1(arg, arg->inter.gun.biggun5);
  if (arg->inter.gun.check_b > 15 && arg->inter.gun.check_b <= 18)
    draw_shoot1(arg, arg->inter.gun.biggun6);
  if (arg->inter.gun.check_b > 12 && arg->inter.gun.check_b <= 15)
    draw_shoot1(arg, arg->inter.gun.biggun5);
  draw_biggun2(arg);
}

void	draw_biggun2(t_param *arg)
{
  if (arg->inter.gun.check_b > 9 && arg->inter.gun.check_b <= 12)
    draw_shoot1(arg, arg->inter.gun.biggun4);
  if (arg->inter.gun.check_b > 6 && arg->inter.gun.check_b <= 9)
    draw_shoot1(arg, arg->inter.gun.biggun3);
  if (arg->inter.gun.check_b > 3 && arg->inter.gun.check_b <= 6)
    draw_shoot1(arg, arg->inter.gun.biggun2);
  if (arg->inter.gun.check_b > 0 && arg->inter.gun.check_b <= 3)
    {
      draw_shoot1(arg, arg->inter.gun.biggun1);
      arg->inter.gun.check_b = 0;
    }
  if (arg->inter.gun.check_b > 0)
    arg->inter.gun.check_b--;
}

void	draw_shoot1(t_param *arg, t_bunny_pixelarray *shoot)
{
  t_bunny_position	end;
  t_bunny_position	pos;
  int			i;

  arg->inter.gun.color = (t_color*)shoot->pixels;
  pos.y = 0;
  i = 0;
  while (pos.y < shoot->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < shoot->clipable.clip_width)
	{
	  end.x = (arg->WIDTH
		   - shoot->clipable.clip_width) / 2 + pos.x;
	  end.y = (arg->HEIGHT
		   - shoot->clipable.clip_height) + pos.y;
	  if (check_color5(arg, i) == 0)
	    tekpixel2(arg->pix, &end, &arg->inter.gun.color[i]);
	  pos.x++;
	  i++;
	}
      pos.y++;
    }
}

int	check_color5(t_param *arg, int i)
{
  int   r;
  int   b;
  int   g;

  r = arg->inter.gun.color[i].full & 0xFF;
  g = (arg->inter.gun.color[i].full >> 8) & 0xFF;
  b = (arg->inter.gun.color[i].full >> 16) & 0xFF;
  if (r == 0 && g == 0 && b == 0)
    return (1);
  return (0);
}
