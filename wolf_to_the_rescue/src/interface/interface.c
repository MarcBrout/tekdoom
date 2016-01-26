/*
** interface.c for interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue/src/interface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Jan 25 13:05:12 2016 maud marel
** Last update Tue Jan 26 17:32:41 2016 maud marel
*/

#include "wolf.h"

void                    interface(t_param *arg)
{
  draw_life_bar(arg);
  draw_square_life(arg);
  if (arg->inter.gun.shoot == 0 && arg->inter.gun.check_r == 0)
    draw_gunshot1(arg);
  if (arg->inter.gun.check_r == 0 && arg->inter.bullet.nb_bullet >= 0 && arg->inter.gun.shoot == 1)
    draw_gunshot(arg);
  draw_reload(arg);
  /* if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /*     && arg->inter.life.nb_heart == 1) */
  /*   draw_game_over(arg); */
  /* else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /* 	   && arg->inter.life.nb_heart == 2) */
  /*   draw_last_chance(arg); */
  /* else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /* 	   && arg->inter.life.nb_heart == 3) */
  /*   draw_try_again(arg); */
  if (arg->inter.life.nb_heart > 0)
    {
      draw_heart(arg);
      draw_bullet(arg);
      if (arg->inter.life.life != 100)
        {
	  arg->inter.life.speed = 3;
	  draw_move_life(arg);
        }
    }
}

void    interface_init(t_param *arg)
{
  arg->inter.life.end = 0;
  arg->inter.life.life = 100;
  arg->inter.life.nb_heart = 3;
  arg->inter.bullet.nb_bullet = 5;
  arg->inter.life.pos_life.x = (3 * arg->WIDTH) / 10 - 1;
  arg->inter.life.pos_life.y = arg->HEIGHT - (arg->HEIGHT / 75);
  arg->inter.gun.shoot = 0;
  arg->inter.gun.check_r = 0;
}

int     load_picture(t_param *arg)
{
  if ((arg->inter.bullet.bullet
       = bunny_load_pixelarray("pictures/bullet.bmp")) == NULL)
    return (-1);
  if ((arg->inter.life.heart
       = bunny_load_pixelarray("pictures/heart.png")) == NULL)
    return (-1);
  if ((arg->inter.gun.gun_shoot1
       = bunny_load_pixelarray("pictures/gunshot1.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.gun_shoot2
       = bunny_load_pixelarray("pictures/gunshot2.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.gun_shoot3
       = bunny_load_pixelarray("pictures/gunshot3.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.reload1
       = bunny_load_pixelarray("pictures/reload1.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.reload2
       = bunny_load_pixelarray("pictures/reload2.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.reload3
       = bunny_load_pixelarray("pictures/reload3.bmp")) == NULL)
    return (-1);
  return (0);
}
