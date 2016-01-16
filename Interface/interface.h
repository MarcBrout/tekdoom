/*
** interface.h for interface in /home/marel_m/Rendu/Infographie/gfx_wolf3d/include
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:10:21 2015 maud marel
** Last update Fri Jan 15 09:52:43 2016 Maud MAREL
*/

#ifndef INTERFACE_H_
# define INTERFACE_H_
# define UNUSED __attribute__((__unused__))
# define HEIGHT 768
# define WIDTH 1024

#include <lapin.h>
#include <math.h>
#include <unistd.h>

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
}			t_data;

t_bunny_response	my_loop(void *);
t_bunny_response	my_escape(t_bunny_event_state,
				  t_bunny_keysym,
				  void *);
void			tekpixel(t_bunny_pixelarray *,
				 t_bunny_position *,
				 unsigned int);
void			my_set_square(t_bunny_pixelarray *);
void			draw_life_bar(t_data *);
void			draw_square_life_bar(t_data *);
void			draw_life(t_data *);

#endif /* !INTERFACE_H_ */
