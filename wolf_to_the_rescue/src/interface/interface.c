/*
** interface.c for interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue/src/interface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Jan 25 13:05:12 2016 maud marel
** Last update Mon Jan 25 13:56:45 2016 maud marel
*/

#include "wolf.h"

void                    interface(t_interface *inter)
{
  if ((inter->life.pos_life.x == ((WIDTH / 75) - 2)) && inter->life.nb_heart == 1)
    draw_game_over(inter);
  else if ((inter->life.pos_life.x == ((WIDTH / 75) - 2)) && inter->life.nb_heart == 2)
    draw_last_chance(inter);
  else if ((inter->life.pos_life.x == ((WIDTH / 75) - 2)) && inter->life.nb_heart == 3)
    draw_try_again(inter);
  if (inter->life.nb_heart > 0)
    {
      if (inter->life.pos_life.x == ((3 * WIDTH) / 10 - 1))
        {
          draw_square_life(inter);
          draw_life_bar(inter);
          draw_heart(inter);
          draw_bullet(inter);
        }
      if (inter->life.ok == 1)
        {
          draw_life_bar(inter);
          inter->life.ok = 0;
        }
      if (inter->life.life != 100)
        {
          inter->life.speed = 3;
          draw_move_life(inter);
        }
    }
}

void    interface_init(t_interface *inter)
{
  inter->life.ok = 0;
  inter->life.end = 0;
  inter->life.life = 100;
  inter->life.nb_heart = 3;
  inter->bullet.nb_bullet = 5;
  draw_square_life(inter);
  draw_life_bar(inter);
}

int     load_picture(t_interface *inter)
{
  if ((inter->trigger.game_over
       = bunny_load_pixelarray("pictures/gameover.png")) == NULL)
    return (-1);
  if ((inter->trigger.lastchance
       = bunny_load_pixelarray("pictures/lastchance.bmp")) == NULL)
    return (-1);
  if ((inter->trigger.try_again
       = bunny_load_pixelarray("pictures/try_again.jpg")) == NULL\
      )
    return (-1);
  return (0);
}
