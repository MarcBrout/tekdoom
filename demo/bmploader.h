/*
** bmploader.h for loader
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Jan 19 19:51:38 2016 marc brout
** Last update Wed Jan 20 14:50:53 2016 marc brout
*/

#ifndef BMPLOADER_H_
# define BMPLOADER_H_
# define UNUSED __attribute__((__unused__))

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "lapin.h"

typedef struct		s_head
{
  unsigned short int	head;
  unsigned int		size;
  unsigned short int	app;
  unsigned short int	resapp;
  unsigned int		offset;
}			__attribute__((__packed__)) t_head;

typedef struct		s_bmp
{
  unsigned int		headsize;
  int			width;
  int			height;
  unsigned short int	plane;
  unsigned short int	type;
  unsigned int		compression;
  unsigned int		imgsize;
  int			hrez;
  int			vrez;
  unsigned int		nbcol;
  unsigned int		impcol;
}			__attribute__((__packed__)) t_bmp;

typedef struct		s_loop
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
}			t_loop;

typedef struct		t_col
{
  unsigned char		a;
  unsigned char		r;
  unsigned char		b;
  unsigned char		alpha;
}			t_col;

#endif /* !BMPLOADER_H_ */
