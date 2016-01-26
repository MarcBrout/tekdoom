/*
** draw_life.c for draw_life in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Sun Jan 17 10:45:26 2016 Maud MAREL
** Last update Tue Jan 26 17:40:30 2016 maud marel
*/

#include "wolf.h"

int			draw_move_life(t_param *arg)
{
  t_bunny_position      pos;

  if (arg->inter.life.end == 0)
    pos.x = (arg->inter.life.life * 3 * arg->WIDTH) / 1000;
  else
    pos.x = (arg->WIDTH / 75) - 1;
  while (++pos.x < arg->inter.life.pos_life.x)
    {
      pos.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) - 1;
      while (++pos.y < (arg->HEIGHT - (arg->HEIGHT / 75)))
	{
	  tekpixel3(arg->pix, &pos, 0x008CFF);
	}
    }
  if (draw_move_life2(arg, pos) == 0)
    return (0);
  arg->inter.life.pos_life.x = arg->inter.life.pos_limit.x - 1;
  return (0);
}

int	draw_move_life2(t_param *arg, t_bunny_position pos)
{
  if (arg->inter.life.pos_life.x > arg->inter.life.pos_limit.x)
    {
      while (arg->inter.life.speed > 0
	     && arg->inter.life.pos_life.x > ((arg->WIDTH / 75) - 1))
  	{
  	  pos.x = arg->inter.life.pos_life.x;
  	  pos.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) - 1;
  	  while (++pos.y < arg->inter.life.pos_life.y)
	    tekpixel3(arg->pix, &pos, WHITE);
  	  arg->inter.life.pos_life.x--;
  	  arg->inter.life.speed--;
  	}
      return (0);
    }
  return (1);
}

void			draw_life_bar(t_param *arg)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (arg->WIDTH / 75) - 1;
  pos_e.x = (arg->inter.life.life * 3 * arg->WIDTH) / 1000;
  pos_e.y = arg->HEIGHT - (arg->HEIGHT / 75);
  while (++pos_s.x < pos_e.x)
    {
      pos_s.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) - 1;
      while (++pos_s.y < pos_e.y)
	tekpixel3(arg->pix, &pos_s, RED);
    }
}

void			action_draw_square_life(t_param *arg,
						t_bunny_position pos_e,
						t_bunny_position pos_s)
{
  t_bunny_position      pos_eh;
  t_bunny_position      pos_sh;

  pos_eh.x = pos_e.x;
  pos_eh.y = pos_s.y - 1;
  pos_sh.x = pos_s.x - 1;
  pos_sh.y = pos_e.y;
  while (pos_s.x <= pos_eh.x)
    {
      tekpixel3(arg->pix, &pos_s, BLACK);
      pos_s.x++;
    }
  while (++pos_eh.y <= pos_e.y)
    tekpixel3(arg->pix, &pos_eh, BLACK);
  pos_s.x = (arg->WIDTH / 75) - 1;
  while (pos_s.y <= pos_e.y)
    {
      tekpixel3(arg->pix, &pos_s, BLACK);
      pos_s.y++;
    }
  while (++pos_sh.x <= pos_e.x)
    tekpixel3(arg->pix, &pos_sh, BLACK);
}

void			draw_square_life(t_param *arg)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (arg->WIDTH / 75) - 1;
  pos_s.y = (arg->HEIGHT - ((arg->HEIGHT / 65) + (arg->HEIGHT / 65))) - 1;
  pos_e.x = ((arg->WIDTH / 10) + (arg->WIDTH / 5)) + 1;
  pos_e.y = arg->HEIGHT - (arg->HEIGHT / 75);
  action_draw_square_life(arg, pos_e, pos_s);
}
