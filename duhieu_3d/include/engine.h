/*
** engine.h for engine in /home/duhieu_b/infographie/rendu/gfx_tekdoom/duhieu_3d/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 10:32:02 2016 benjamin duhieu
** Last update Fri Jan 22 00:10:11 2016 benjamin duhieu
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
  double	nx;
  double	ny;
}		t_calc;

typedef			struct s_main
{
  t_calc		calc;
  t_bunny_position	pos[2];
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_parse		pars;
  t_color		col;
  double		mouse;
  double		speed;
}			t_main;

double	correct_dist_mh(t_main *, int, double);
double	correct_dist_mv(t_main *, int, double);
int	init_main(int, char **, char **, t_main *);
int	intersection_horizontal(t_main *);
int	intersection_vertical(t_main *);
int	up(t_main *);
t_bunny_response	main_loop(void *);
void	back(t_main *);
void	calc(t_main *);
void	check_ang(t_main *);
void	dist_to_wall(t_main *);
void	dist_wall(t_main *);
void	forward(t_main *);
void	init_data(t_main *);
void	init_left(t_main *);
void	init_right(t_main *);
void	fill_cos_sin(t_ang *);
void	fill_screen(t_bunny_pixelarray *);

#endif /* !MY_ENGINE */
