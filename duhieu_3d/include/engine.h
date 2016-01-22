/*
** engine.h for engine
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 10:32:02 2016 benjamin duhieu
** Last update Fri Jan 22 20:20:09 2016 marc brout
*/

#ifndef ENGINE_H_
# define ENGINE_H_
# define WIDTH 1024
# define HEIGHT 768
# define ANG doom->pars.maps->next->lvls->next->pla
# define PLY doom->pars.maps->next->lvls->next->ply
# define PLX doom->pars.maps->next->lvls->next->plx
# define AX doom->pars.maps->next->lvls->segs->ax
# define AY doom->pars.maps->next->lvls->segs->ay
# define BX doom->pars.maps->next->lvls->segs->bx
# define BY doom->pars.maps->next->lvls->segs->by
# define HIGH doom->pars.maps->next->lvls->segs->z
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
  int		fov;
  double	a;
  double	b;
  double	na;
  double	nb;
  double	ny;
  double	nx;
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

int	calc(t_main *);
int	init_main(int, char **, char **, t_main *);
int	inter(t_main *, int);
t_bunny_response	main_loop(void *);
void	check_ang(t_main *);
void	disp_wall(t_main *, int);
void	forward(t_main *);
void	init_data(t_main *);
void	fill_cos_sin(t_ang *);
void	fill_screen(t_bunny_pixelarray *);

#endif /* !MY_ENGINE */
