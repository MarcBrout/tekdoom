/*
** interface.c for interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue/src/interface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Jan 25 13:05:12 2016 maud marel
** Last update Mon Jan 25 15:18:05 2016 Mathieu Sauvau
*/

#include "wolf.h"

void                    interface(t_param *arg)
{
  if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) && arg->inter.life.nb_heart == 1)
    draw_game_over(arg);
  else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) && arg->inter.life.nb_heart == 2)
    draw_last_chance(arg);
  else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) && arg->inter.life.nb_heart == 3)
    draw_try_again(arg);
  if (arg->inter.life.nb_heart > 0)
    {
      if (arg->inter.life.pos_life.x == ((3 * arg->WIDTH) / 10 - 1))
        {
          draw_square_life(arg);
          draw_life_bar(arg);
          draw_heart(arg);
          draw_bullet(arg);
        }
      if (arg->inter.life.ok == 1)
        {
          draw_life_bar(arg);
          arg->inter.life.ok = 0;
        }
      if (arg->inter.life.life != 100)
        {
          arg->inter.life.speed = 3;
          draw_move_life(arg);
        }
    }
}

void    interface_init(t_param *arg)
{
  arg->inter.life.ok = 0;
  arg->inter.life.end = 0;
  arg->inter.life.life = 100;
  arg->inter.life.nb_heart = 3;
  arg->inter.bullet.nb_bullet = 5;
  draw_square_life(arg);
  draw_life_bar(arg);
}

int     load_picture(t_param *arg)
{
  if ((arg->inter.trigger.game_over
       = bunny_load_pixelarray("pictures/gameover.png")) == NULL)
    return (-1);
  if ((arg->inter.trigger.lastchance
       = bunny_load_pixelarray("pictures/lastchance.bmp")) == NULL)
    return (-1);
  if ((arg->inter.trigger.try_again
       = bunny_load_pixelarray("pictures/try_again.jpg")) == NULL\
      )
    return (-1);
  return (0);
}
