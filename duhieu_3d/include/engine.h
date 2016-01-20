/*
** engine.h for engine in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 10:32:02 2016 benjamin duhieu
** Last update Sun Jan 17 12:28:43 2016 benjamin duhieu
*/

#ifndef ENGINE_H_
# define ENGINE_H_
# define WIDTH 1024
# define HEIGHT 768
# define ABS(Value) ((Value < 0) ? -Value : Value)
# include <math.h>

typedef			struct s_ang
{
  double		cosi[3600];
  double		sinu[3600];
  double		tang[3600];
}			t_ang;

typedef struct	s_calc
{
  int		fov;
  t_ang		ang;
  int		dim;
  int		teta;
  int		px;
  int		py;
  int		xa;
  int		ya;
  int		ax;
  int		ay;
  int		bx;
  int		by;
  int		ma;
  int		hight;
}		t_calc;

typedef			struct s_main
{
  int			ang;
  t_calc		calc;
  t_bunny_position	pos[2];
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_color		col;
}			t_main;
