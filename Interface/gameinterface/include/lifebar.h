/*
** interface.h for interface in /home/marel_m/Rendu/Infographie/gfx_wolf3d/include
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:10:21 2015 maud marel
** Last update Wed Jan 20 18:52:11 2016 Maud MAREL
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_
# define UNUSED __attribute__((__unused__))
# define HEIGHT 768
# define WIDTH 1024

#include <lapin.h>
#include <math.h>
#include <unistd.h>

typedef struct          s_letter
{
  char                  name;
  t_bunny_picture       *letter;
}                       t_letter;

typedef struct		s_life
{
  t_bunny_pixelarray	*heart;
  t_bunny_pixelarray	*bullet;
  int			nb_heart;
  int			life;
  int			ok;
  int			end;
  int			res;
  t_bunny_position	pos_limit;
  t_bunny_position	pos_life;
}			t_life;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_life		life;
}			t_data;

t_bunny_response	my_loop(void *);
t_bunny_response	my_escape(t_bunny_event_state,
				  t_bunny_keysym,
				  void *);
void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *,
				 unsigned int);
void			tekpixel2(t_bunny_pixelarray *,
				 t_bunny_position *,
				 t_color *);
void			my_set_square(t_bunny_pixelarray *);
void			draw_life_bar(t_data *);
int			draw_move_life(t_data *);
void			draw_square_life(t_data *);
void			action_draw_square_life(t_data *,
						    t_bunny_position,
						    t_bunny_position);
void			interface(t_data *);
void			interface_init(t_data *);
int			draw_heart(t_data *);
void			draw_heart_else(t_data *, int, int);
int			draw_bullet_start(t_data *);

#endif /* !INTERFACE_H_ */
