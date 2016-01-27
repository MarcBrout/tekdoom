/*
** load_picture.c for load_picture
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 26 23:55:32 2016 maud marel
** Last update Wed Jan 27 05:56:20 2016 maud marel
*/

#include "tekdoom.h"

int	load_picture(t_param *arg)
{
  if (((arg->inter.bullet.bullet
	   = bunny_load_pixelarray("pictures/bullet.bmp")) == NULL)
      || ((arg->inter.life.heart
	   = bunny_load_pixelarray("pictures/heart.png")) == NULL)
      || ((arg->inter.gun.gun_shoot1
	   = bunny_load_pixelarray("pictures/gunshot1.bmp")) == NULL)
      || ((arg->inter.gun.gun_shoot2
	   = bunny_load_pixelarray("pictures/gunshot2.bmp")) == NULL)
      || ((arg->inter.gun.gun_shoot3
	   = bunny_load_pixelarray("pictures/gunshot3.bmp")) == NULL)
      || (load_picture2(arg) == -1)
      || (load_picture3(arg) == -1)
      || (load_picture4(arg) == -1))
    return (-1);
  return (0);
}

int	load_picture2(t_param *arg)
{
  if (((arg->inter.gun.reload1
	= bunny_load_pixelarray("pictures/reload1.bmp")) == NULL)
      || ((arg->inter.gun.reload2
	   = bunny_load_pixelarray("pictures/reload2.bmp")) == NULL)
      || ((arg->inter.gun.reload3
	   = bunny_load_pixelarray("pictures/reload3.bmp")) == NULL)
      || ((arg->inter.gun.punch1
	   = bunny_load_pixelarray("pictures/punch1.bmp")) == NULL)
      || ((arg->inter.gun.punch2
	   = bunny_load_pixelarray("pictures/punch2.bmp")) == NULL)
      || ((arg->inter.gun.punch3
	   = bunny_load_pixelarray("pictures/punch3.bmp")) == NULL)
      || ((arg->inter.gun.scope
	   = bunny_load_pixelarray("pictures/scope.bmp")) == NULL)
      || ((arg->inter.trigger.game_over
	   = bunny_load_pixelarray("pictures/gameover.png")) == NULL))
    return (-1);
  return (0);
}

int	load_picture3(t_param *arg)
{
  if (((arg->inter.trigger.try_again
	= bunny_load_pixelarray("pictures/try_again.bmp")) == NULL)
      || ((arg->inter.trigger.lastchance
	   = bunny_load_pixelarray("pictures/lastchance.bmp")) == NULL)
      || ((arg->inter.gun.biggun1
	   = bunny_load_pixelarray("pictures/big1.png")) == NULL)
      || ((arg->inter.gun.biggun2
	   = bunny_load_pixelarray("pictures/big2.png")) == NULL)
      || ((arg->inter.gun.biggun3
	   = bunny_load_pixelarray("pictures/big3.png")) == NULL)
      || ((arg->inter.gun.biggun4
	   = bunny_load_pixelarray("pictures/big4.png")) == NULL)
      || ((arg->inter.gun.biggun5
	   = bunny_load_pixelarray("pictures/big5.png")) == NULL)
      || ((arg->inter.gun.biggun6
	   = bunny_load_pixelarray("pictures/big6.png")) == NULL))
    return (-1);
  return (0);
}

int	load_picture4(t_param *arg)
{
  if (((arg->inter.gun.sulf0
	= bunny_load_pixelarray("pictures/sulf0.png")) == NULL)
      || ((arg->inter.gun.sulf1
	= bunny_load_pixelarray("pictures/sulf1.png")) == NULL)
      || ((arg->inter.gun.sulf2
	   = bunny_load_pixelarray("pictures/sulf2.png")) == NULL)
      || ((arg->inter.gun.sulf3
	   = bunny_load_pixelarray("pictures/sulf3.png")) == NULL)
      || ((arg->inter.gun.knife1
	   = bunny_load_pixelarray("pictures/knife1.png")) == NULL)
      || ((arg->inter.gun.knife2
	   = bunny_load_pixelarray("pictures/knife2.png")) == NULL)
      || ((arg->inter.gun.knife3
	   = bunny_load_pixelarray("pictures/knife3.png")) == NULL)
      || ((arg->inter.gun.knife4
	   = bunny_load_pixelarray("pictures/knife4.png")) == NULL))
    return (-1);
  return (0);
}
