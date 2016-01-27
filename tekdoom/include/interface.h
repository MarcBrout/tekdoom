/*
** interface.h for interface in /home/marel_m/Rendu/Infographie/gfx_wolf3d/include
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:10:21 2015 maud marel
** Last update Wed Jan 27 07:03:50 2016 maud marel
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_
# define UNUSED __attribute__((__unused__))

#include <lapin.h>
#include <math.h>
#include <unistd.h>

typedef struct		s_gun
{
  t_color		*color;
  t_bunny_pixelarray	*gun_shoot1;
  t_bunny_pixelarray	*gun_shoot2;
  t_bunny_pixelarray	*gun_shoot3;
  t_bunny_pixelarray	*reload1;
  t_bunny_pixelarray	*reload2;
  t_bunny_pixelarray	*reload3;
  t_bunny_pixelarray	*punch1;
  t_bunny_pixelarray	*punch2;
  t_bunny_pixelarray	*punch3;
  t_bunny_pixelarray	*scope;
  t_bunny_pixelarray	*biggun1;
  t_bunny_pixelarray	*biggun2;
  t_bunny_pixelarray	*biggun3;
  t_bunny_pixelarray	*biggun4;
  t_bunny_pixelarray	*biggun5;
  t_bunny_pixelarray	*biggun6;
  t_bunny_pixelarray	*sulf0;
  t_bunny_pixelarray	*sulf1;
  t_bunny_pixelarray	*sulf2;
  t_bunny_pixelarray	*sulf3;
  t_bunny_pixelarray	*knife1;
  t_bunny_pixelarray	*knife2;
  t_bunny_pixelarray	*knife3;
  int			i;
  int			check_s;
  int			check_sul;
  int			check_r;
  int			check_p;
  int			check_b;
  int			check_k;
}			t_gun;

typedef struct		s_bullet
{
  int			nb_bullet;
  t_bunny_pixelarray	*bullet;
  t_color		*color;
}			t_bullet;

typedef struct		s_life
{
  t_bunny_pixelarray	*heart;
  int			nb_heart;
  int			life;
  int			ok;
  int			end;
  int			res;
  int			speed;
  t_bunny_position	pos_limit;
  t_bunny_position	pos_life;
  t_color		*color;
}			t_life;

typedef struct		s_trigger
{
  t_bunny_pixelarray	*game_over;
  t_bunny_pixelarray	*try_again;
  t_bunny_pixelarray	*lastchance;
}			t_trigger;

typedef struct		s_interface
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_life		life;
  t_bullet		bullet;
  t_trigger		trigger;
  t_gun			gun;
}			t_interface;

void			tekpixel3(t_bunny_pixelarray *,
				 t_bunny_position *,
				 unsigned int);

#endif /* !INTERFACE_H_ */
