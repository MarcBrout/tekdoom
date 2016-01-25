/*
** interface.h for interface in /home/marel_m/Rendu/Infographie/gfx_wolf3d/include
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:10:21 2015 maud marel
** Last update Mon Jan 25 15:06:02 2016 maud marel
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_
# define UNUSED __attribute__((__unused__))

#include <lapin.h>
#include <math.h>
#include <unistd.h>

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
}			t_interface;

t_bunny_response	my_loop(void *);
t_bunny_response	my_escape(t_bunny_event_state,
				  t_bunny_keysym,
				  void *);
void			tekpixel3(t_bunny_pixelarray *,
				 t_bunny_position *,
				 unsigned int);
/* void			tekpixel2(t_bunny_pixelarray *, */
/* 				 t_bunny_position *, */
/* 				 t_color *); */
void			my_set_square(t_bunny_pixelarray *,
				      unsigned int);
/* void			draw_life_bar(t_param *); */
/* int			draw_move_life(t_param *); */
/* int			draw_move_life2(t_param *, t_bunny_position); */
/* void			draw_square_life(t_param *); */
/* void			action_draw_square_life(t_param *, */
/* 						    t_bunny_position, */
/* 						    t_bunny_position); */
/* void			interface(t_param *); */
/* void			interface_init(t_param *); */
/* int			draw_heart(t_param *); */
/* void			draw_heart2(t_param *, t_bunny_position, */
/* 				    t_bunny_position, int); */
/* void			draw_heart_else(t_param *, int, int); */
/* int			draw_bullet(t_param *); */
/* void			draw_bullet2(t_param *, t_bunny_position, */
/* 				    t_bunny_position, int); */
/* void			draw_bullet_else(t_param *, int, int); */
/* int			draw_game_over(t_param *); */
/* int			draw_last_chance(t_param *); */
/* int			draw_try_again(t_param *); */
/* int			load_picture(t_param *); */

#endif /* !INTERFACE_H_ */
