/*
** interface.c for interface in /home/marel_m/Rendu/Infographie/gfx_tekdoom/wolf_to_the_rescue/src/interface
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Jan 25 13:05:12 2016 maud marel
** Last update Tue Jan 26 21:53:08 2016 maud marel
*/

#include "wolf.h"

void	interface(t_param *arg)
{
  /* if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /*     && arg->inter.life.nb_heart == 1) */
  /*   draw_game_over(arg); */
  /* else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /* 	   && arg->inter.life.nb_heart == 2) */
  /*   draw_last_chance(arg); */
  /* else if ((arg->inter.life.pos_life.x == ((arg->WIDTH / 75) - 2)) */
  /* 	   && arg->inter.life.nb_heart == 3) */
  /*   draw_try_again(arg); */
  interface_gun(arg);
  draw_life_bar(arg);
  draw_square_life(arg);
  if (arg->inter.life.nb_heart > 0)
    {
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

int	load_picture(t_param *arg)
{
  if ((arg->inter.gun.music =
       bunny_load_effect("0438.ogg")) == NULL)
    return (-1);
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
  if (load_picture2(arg) == -1)
    return (-1);
  return (0);
}

int	load_picture2(t_param *arg)
{
  if ((arg->inter.gun.reload1
       = bunny_load_pixelarray("pictures/reload1.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.reload2
       = bunny_load_pixelarray("pictures/reload2.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.reload3
       = bunny_load_pixelarray("pictures/reload3.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.punch1
       = bunny_load_pixelarray("pictures/punch1.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.punch2
       = bunny_load_pixelarray("pictures/punch2.bmp")) == NULL)
    return (-1);
  if ((arg->inter.gun.punch3
       = bunny_load_pixelarray("pictures/punch3.bmp")) == NULL)
    return (-1);
  return (0);
}
