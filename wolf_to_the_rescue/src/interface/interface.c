/*
** interface.c for interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue/src/interface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Jan 25 13:05:12 2016 maud marel
** Last update Wed Jan 27 00:11:10 2016 maud marel
*/

#include "tekdoom.h"

void	interface(t_param *arg)
{
  interface_gun(arg);
  draw_scope(arg);
  draw_life_bar(arg);
  draw_square_life(arg);
  if (arg->inter.life.nb_heart > 0)
    {
      if (arg->inter.life.pos_life.x == (arg->WIDTH / 75) - 2)
	{
	  /* if (arg->inter.life.nb_heart == 1) */
	  /*   draw_game_over(arg); */
	  /* if (arg->inter.life.nb_heart == 2) */
	  /*   draw_last_chance(arg); */
	  /* if (arg->inter.life.nb_heart == 3) */
	  /*   draw_try_again(arg); */
	  if (arg->inter.life.nb_heart > 1)
	    {
	      arg->inter.life.life = 100;
	      arg->inter.life.end  = 0;
	      arg->inter.life.pos_life.x = (3 * arg->WIDTH) / 10 - 1;
	    }
	  arg->inter.life.nb_heart--;
	}
      draw_heart(arg);
      if (arg->inter.gun.shoot != 2)
	draw_bullet(arg);
      if (arg->inter.life.life != 100)
        {
	  arg->inter.life.speed = 3;
	  draw_move_life(arg);
        }
    }
}

void	interface_gun(t_param *arg)
{
  if (arg->inter.gun.shoot == 0 && arg->inter.gun.check_r == 0)
    draw_gunshot1(arg);
  if (arg->inter.gun.check_r == 0
      && arg->inter.bullet.nb_bullet >= 0 && arg->inter.gun.shoot == 1)
    draw_gunshot(arg);
  draw_reload(arg);
  if (arg->inter.gun.punch == 1 && arg->inter.gun.check_p == 0)
    draw_punch1(arg);
  if (arg->inter.gun.check_p != 0 && arg->inter.gun.punch == 1)
    draw_punch(arg);
}

void	interface_init(t_param *arg)
{
  arg->inter.life.end = 0;
  arg->inter.life.life = 100;
  arg->inter.life.nb_heart = 3;
  arg->inter.bullet.nb_bullet = 5;
  arg->inter.life.pos_life.x = (3 * arg->WIDTH) / 10 - 1;
  arg->inter.life.pos_life.y = arg->HEIGHT - (arg->HEIGHT / 75);
  arg->inter.gun.shoot = 0;
  arg->inter.gun.check_r = 0;
  arg->inter.gun.check_p = 0;
  arg->inter.gun.punch = 0;
}
