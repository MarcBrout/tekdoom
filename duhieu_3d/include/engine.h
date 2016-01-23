/*
** engine.h for engine
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 10:32:02 2016 benjamin duhieu
** Last update Sat Jan 23 21:24:54 2016 benjamin duhieu
*/

#ifndef ENGINE_H_
# define ENGINE_H_
# define WIDTH 1024
# define HEIGHT 768
# define ABS(value) (((value) < 0) ? -(value) : (value))
# define RAD(value) (((value) * M_PI) / 180)
# define DEG(value) (((value) * 180) / M_PI)
# include <math.h>

typedef			struct s_ang
{
  double		cosi[3600];
  double		sinu[3600];
  double		tang[3600];
}			t_ang;

typedef struct	s_calc
{
  t_ang		ang;
  double	fov;
  double	a;
  double	b;
  double	na;
  double	nb;
  double	ny;
  double	nx;
  double	cos;
  double	sin;
}		t_calc;

typedef			struct s_main
{
  t_calc		calc;
  t_bunny_position	pos[2];
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_parse		*pars;
  t_color		col;
  double		mouse;
  double		speed;
}			t_main;

int	calc(t_main *, t_lvl *);
int	init_main(int, char **, char **, t_main *);
int	inter(t_main *, int, t_seg *, t_lvl *);
t_bunny_response	main_loop(void *);
void	check_ang(t_main *);
void	disp_wall(t_main *, int, t_lvl *);
void	forward(t_main *);
void	init_data(t_main *);
void	fill_cos_sin(t_ang *);
void	fill_screen(t_bunny_pixelarray *);
void	put_in_k(t_main *, int, t_seg *, t_lvl *);

#endif /* !MY_ENGINE */
