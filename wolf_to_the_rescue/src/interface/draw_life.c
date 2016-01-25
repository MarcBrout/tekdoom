/*
** draw_life.c for draw_life in /home/mmaud/Rendu/Infographie/gfx_tekdoom/Interface
**
** Made by Maud MAREL
** Login   <marel_m@epitech.net>
**
** Started on  Sun Jan 17 10:45:26 2016 Maud MAREL
** Last update Mon Jan 25 13:54:50 2016 maud marel
*/

#include "wolf.h"

int			draw_move_life(t_interface *inter)
{
  t_bunny_position      pos;

  if (inter->life.end == 0)
    pos.x = (inter->life.life * 3 * WIDTH) / 1000;
  else
    pos.x = (WIDTH / 75) - 1;
  while (++pos.x < inter->life.pos_life.x)
    {
      pos.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while (++pos.y < (HEIGHT - (HEIGHT / 75)))
	tekpixel(inter->pix, &pos, 0x008CFF);
    }
  if (draw_move_life2(inter, pos) == 0)
    return (0);
  inter->life.pos_life.x = inter->life.pos_limit.x - 1;
  return (0);
}

int	draw_move_life2(t_interface *inter, t_bunny_position pos)
{
  if (inter->life.pos_life.x > inter->life.pos_limit.x)
    {
      while (inter->life.speed > 0
	     && inter->life.pos_life.x > ((WIDTH / 75) - 1))
  	{
  	  pos.x = inter->life.pos_life.x;
  	  pos.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
  	  while (++pos.y < inter->life.pos_life.y)
  	    tekpixel(inter->pix, &pos, WHITE);
  	  inter->life.pos_life.x--;
  	  inter->life.speed--;
  	}
      return (0);
    }
  return (1);
}

void			draw_life_bar(t_interface *inter)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_e.x = (inter->life.life * 3 * WIDTH) / 1000;
  pos_e.y = HEIGHT - (HEIGHT / 75);
  while (++pos_s.x < pos_e.x)
    {
      pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
      while (++pos_s.y < pos_e.y)
	tekpixel(inter->pix, &pos_s, RED);
    }
  inter->life.pos_life.x = (3 * WIDTH) / 10 - 1;
  inter->life.pos_life.y = HEIGHT - (HEIGHT / 75);
}

void			action_draw_square_life(t_interface *inter,
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
      tekpixel(inter->pix, &pos_s, BLACK);
      pos_s.x++;
    }
  while (++pos_eh.y <= pos_e.y)
    tekpixel(inter->pix, &pos_eh, BLACK);
  pos_s.x = (WIDTH / 75) - 1;
  while (pos_s.y <= pos_e.y)
    {
      tekpixel(inter->pix, &pos_s, BLACK);
      pos_s.y++;
    }
  while (++pos_sh.x <= pos_e.x)
    tekpixel(inter->pix, &pos_sh, BLACK);
}

void			draw_square_life(t_interface *inter)
{
  t_bunny_position      pos_s;
  t_bunny_position      pos_e;

  pos_s.x = (WIDTH / 75) - 1;
  pos_s.y = (HEIGHT - ((HEIGHT / 65) + (HEIGHT / 65))) - 1;
  pos_e.x = ((WIDTH / 10) + (WIDTH / 5)) + 1;
  pos_e.y = HEIGHT - (HEIGHT / 75);
  action_draw_square_life(inter, pos_e, pos_s);
}
