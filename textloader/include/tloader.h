/*
** tloarder.h for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Jan 21 21:52:59 2016 marc brout
** Last update Fri Jan 22 01:26:03 2016 marc brout
*/

#ifndef TLOADER_H_
# define TLOARDER_H_
# define UNUSED __attribute__((__unused__))

# include "lapin.h"
# include "stdio.h"

typedef struct		s_sprite
{
  int			i;
  int			w;
  int			h;
  unsigned int		back;
  t_bunny_pixelarray	*sprt;
  t_bunny_pixelarray	**anim;
}			t_sprite;

typedef struct		s_arg
{
  t_sprite		*texture;
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
}			t_arg;
#endif /* !TLOADER_H_ */
