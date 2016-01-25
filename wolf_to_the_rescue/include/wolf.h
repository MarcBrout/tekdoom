/*
** wolf3d.h for wolf
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Dec 17 15:13:48 2015 marc brout
** Last update Mon Jan 25 15:00:39 2016 maud marel
*/

#ifndef WOLF_H_
# define WOLF_H_
# define WIDTH 1024
# define HEIGHT 768
# define SKY 0xFF796C71
# define PLAYER 0xFF00D7FF
# define WALLA 0xFF8E7587
# define WALLB 0xFFC49B99
# define WALLC 0xFFDDC3A8
# define WALLD 0xFFE8DBB7
# define FLOOR 0xFF1F140C
# define BORDER 0xFF0045FF
# define BORDERIN 0xFF00A5FF
# define BORDEROU 0xFF00D7FF
# define FLD bunny_ini_get_field
# define NBTXT 1
# define TXT_1 "files/textures/01_brick_wall.png"
# define ZERO(val) (((val) > 0) ? (val) - 1 : -1)
# define ABS(val) (((val) < 0) ? -(val) : (val))
# define GET_X(val) ABS((WIDTH / 2) - WIDTH + (val))
# define DEGRE(val) (((val) / M_PI) * 180)
# define RAD(val) (((val) * M_PI) / 180)

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include "lapin.h"
# include "interface.h"

typedef struct		s_lvl
{
  char			*name;
  char			*desc;
  int			tiles;
  int			width;
  int			height;
  int			**map;
  t_bunny_pixelarray	*mini;
  int			minipos;
  double		playerx;
  double		playery;
  double		plangle;
  double		yangle;
}			t_lvl;

typedef struct		s_wmath
{
  double		ydep[WIDTH];
  double		costab[360];
  double		sintab[360];
}			t_wmath;

typedef struct		s_calc
{
  int			mini;
  double		d;
  double		p;
  double		k;
  char			x;
  double		vecx;
  double		vecy;
  double		xf;
  double		yf;
}			t_calc;

typedef struct		s_param
{
  t_calc		calc;
  t_wmath		wm;
  int			curlvl;
  int			nblvl;
  double		hight;
  t_lvl			*lvl;
  t_bunny_ini		*ini;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*textures[NBTXT + 1];
  t_bunny_window	*win;
  t_bunny_key		key;
  t_bunny_move		move;
  t_interface		inter;
  char			mov;
  char			vit;
  int			speedy;
  int			jump;
  int			chrono;
}			t_param;

t_bunny_response my_keys(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response main_wolf(void *);
t_bunny_response my_mouse(const t_bunny_position *, void *);
int my_strcmp(const char *, char *);
int my_strlen(const char *);
int my_getnbr(const char *);
int  sky(t_param *, int);
int next_casex(t_param *, double);
int next_casey(t_param *, double);
void whats_up(char **, int);
void bottom(t_param *, int);
void wall_north_east(t_param *, int, int, int);
void wall_south_east(t_param *, int, int, int);
void wall_north_west(t_param *, int, int, int);
void wall_south_west(t_param *, int, int, int);
void free_all(t_param *);
void set_lvl_minimap(t_param *, t_lvl *);
void set_minimaps(t_param *);
void tek_circle(t_lvl *, int);
void add_player_to_mini(t_param *, t_lvl *);
void basic_to_sec(t_param *, int);
void calc_walls(t_param *);
void celerity(t_param *);
void get_len(t_param *);
void get_player(t_param *, t_lvl *);
void mini_map(t_param *, t_lvl *);
void move(t_param *, double, double);
void new_hight(t_param *);
void project_k(t_param *, t_lvl *, int);
void put_border(t_param *, int, unsigned int);
void set_bump(t_param *, t_lvl *);
void set_cossin(t_param *);
void simple_tap(t_param *);
char *my_strdup(char *);
char mal_mini_map(t_param *, t_lvl *);
char aff_wolf(t_param *);
char check_args(int, char **);
char check_all_lvl(t_param *);
char check_lvl(t_param *, char *);
char get_lvl_map(t_param *, t_lvl *);
char get_tabmap(t_param *);
char launch_wolf(char **);
char mal_tablvl(t_param *);
char mal_lvl_map(t_param *, t_lvl *);
char open_ini(t_param *, char **);
char get_textures(t_param *);

void                    draw_life_bar(t_param *);
int                     draw_move_life(t_param *);
int                     draw_move_life2(t_param *, t_bunny_position);
void                    draw_square_life(t_param *);
void                    action_draw_square_life(t_param *,
						t_bunny_position,
						t_bunny_position);
void                    interface(t_param *);
void                    interface_init(t_param *);
int                     draw_heart(t_param *);
void                    draw_heart2(t_param *, t_bunny_position,
                                    t_bunny_position, int);
void                    draw_heart_else(t_param *, int, int);
int                     draw_bullet(t_param *);
void                    draw_bullet2(t_param *, t_bunny_position,
				     t_bunny_position, int);
void                    draw_bullet_else(t_param *, int, int);
int                     draw_game_over(t_param *);
int                     draw_last_chance(t_param *);
int                     draw_try_again(t_param *);
int                     load_picture(t_param *);
void                    tekpixel2(t_bunny_pixelarray *,
                                 t_bunny_position *,
                                 t_color *);

#endif /* !WOLF_H_ */
