/*
** tekdoom.h for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Dec 17 15:13:48 2015 marc brout
** Last update Wed Jan 27 08:41:06 2016 benjamin duhieu
*/

#ifndef TEKDOOM_H_
# define TEKDOOM_H_

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
# define BIS bunny_ini_scope_get_field
# define ZIK_1 "sounds/Emotional Dark Music - The Eternal Forest.ogg"
# define ZIK_2 "sounds/dsbrssit.ogg"
# define ZIK_3 "sounds/dsdshtgn.ogg"
# define ZIK_4 "sounds/dspdiehi.ogg"
# define ZIK_5 "sounds/Burp.ogg"
# define ZIK_6 "sounds/dswpnup.ogg"
# define ZIK_7 "sounds/Creaky door sound effect.ogg"
# define ZIK_8 "sounds/1459.ogg"
# define ZIK_9 "sounds/sulf.ogg"
# define ZIK_10 "sounds/3502.ogg"
# define NBTXT 5
# define TXT_2 "files/textures/wall_test2.bmp"
# define TXT_1 "files/textures/02_floor.png"
# define TXT_3 "files/textures/sky.bmp"
# define TXT_4 "files/textures/door_0.bmp"
# define TXT_5 "files/textures/door_1.bmp"
# define NBOBJ 1
# define OBJ_1 "files/sprites/01_potion.png"
# define ZERO(val) (((val) > 0) ? (val) - 1 : -1)
# define ABS(val) (((val) < 0) ? -(val) : (val))
# define GET_X(val) ABS((WIDTH / 2) - WIDTH + (val))
# define DEGRE(val) (((val) / M_PI) * 180)
# define RAD(val) (((val) * M_PI) / 180)
# define DEC(val) ((val) - (int)(val))
# define XF arg->calc.xf
# define YF arg->calc.yf
# define CWID clipable.clip_width
# define CHEI clipable.clip_height
# define I arg->curlvl
# define JUMP (arg->hight * 200)
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include "lapin.h"
# include "interface.h"
# include "menu.h"

typedef struct		s_obj
{
  int			type;
  int			x;
  char			alive;
  char			trace;
  double		k;
}			t_obj;

typedef struct		s_lvl
{
  char			*name;
  char			*desc;
  int			tiles;
  int			width;
  int			height;
  int			**map;
  t_obj			***objs;
  t_bunny_pixelarray	*mini;
  int			minipos;
  double		playerx;
  double		playery;
  double		plangle;
  double		yangle;
}			t_lvl;

typedef struct		s_wmath
{
  double		*ydep;
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

typedef struct		s_sound
{
  t_bunny_effect	*shotgun;
  t_bunny_effect	*door;
  t_bunny_effect	*burger;
  t_bunny_effect	*cac;
  t_bunny_effect	*cac2;
  t_bunny_effect	*sulf;
  t_bunny_effect	*knife;
  t_bunny_effect	*bazook;
  t_bunny_effect	*reload;
}			t_sound;

typedef struct		s_param
{
  t_calc		calc;
  t_data		*data;
  t_bunny_music		*play;
  t_sound		*sound;
  t_wmath		wm;
  int			curlvl;
  int			nblvl;
  double		hight;
  t_lvl			*lvl;
  t_bunny_ini		*ini;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*textures[NBTXT + 1];
  t_bunny_pixelarray	*sprites[NBOBJ + 1];
  t_bunny_window	*win;
  t_bunny_key		key;
  t_bunny_move		move;
  t_interface		inter;
  char			mov;
  char			vit;
  int			speedy;
  int			jump;
  int			chrono;
  bool			trans;
}			t_param;

t_bunny_response	my_keys(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response	main_click(t_bunny_event_state,
				   t_bunny_mousebutton, void *);
t_bunny_response	main_tekdoom(void *);
t_bunny_response	my_mouse(const t_bunny_position *, void *);
int			my_strcmp(const char *, char *);
int			next_casex(t_param *, double);
int			next_casey(t_param *, double);
int			download_music(t_param *);
void			whats_up(char **, int);
void			sky(t_param *);
void			delete_sound(t_param *);
void			bottom(t_param *);
void			check_obj(t_param *);
void			set_lvl_minimap(t_param *, t_lvl *);
void			set_minimaps(t_param *);
void			tek_circle(t_lvl *, int);
void			add_player_to_mini(t_param *, t_lvl *);
void			basic_to_sec(t_param *, int);
void			calc_walls(t_param *, t_data *);
void			celerity(t_param *);
void			get_len(t_param *, int);
void			get_player(t_param *, t_lvl *);
void			mini_map(t_param *, t_lvl *, t_data *);
void			move(t_param *, double, double);
void			new_hight(t_param *);
void			project_k(t_param *, t_lvl *, int, int);
void			put_border(t_param *, int, unsigned int);
void			set_bump(t_param *, t_lvl *);
void			set_cossin(t_param *);
void			simple_tap(t_param *);
char			test_k(t_param *, int);
char			*my_strdup(char *);
char			mal_mini_map(t_param *, t_lvl *);
char			aff_tekdoom(t_param *);
char			check_args(int, char **);
char			check_all_lvl(t_param *);
char			check_lvl(t_param *, char *);
char			get_lvl_map(t_param *, t_lvl *);
char			get_tabmap(t_param *);
char			launch_tekdoom(t_param *, char **);
char			mal_tablvl(t_param *);
char			mal_lvl_map(t_param *, t_lvl *);
char			open_ini(t_param *, char **);
char			get_textures(t_param *);
void			set_max_heap_size(size_t);
void                    draw_life_bar(t_param *);
int                     draw_move_life(t_param *);
int                     draw_move_life2(t_param *, t_bunny_position);
void                    draw_square_life(t_param *);
void                    action_draw_square_life(t_param *,
						t_bunny_position,
						t_bunny_position);
void                    interface(t_param *);
void			interface_gun(t_param *);
void                    interface_init(t_param *);
void                    draw_heart(t_param *);
void                    draw_heart2(t_param *, t_bunny_position,
                                    t_bunny_position, int);
void                    draw_bullet(t_param *);
void                    draw_bullet2(t_param *, t_bunny_position,
				     t_bunny_position, int);
void                    draw_game_over(t_param *);
void                    draw_last_chance(t_param *);
void                    draw_try_again(t_param *);
int                     load_picture(t_param *);
int                     load_picture2(t_param *);
int                     load_picture3(t_param *);
int                     load_picture4(t_param *);
void			inertie(t_param *);
void                    tekpixel2(t_bunny_pixelarray *,
				  t_bunny_position *,
				  t_color *);
void                    tekpixel3(t_bunny_pixelarray *,
				  t_bunny_position *,
				  unsigned int);
int			check_color(t_param *, int);
int			check_color2(t_param *, int);
int			check_color3(t_param *, int);
int			check_color4(t_param *, int);
int			check_color5(t_param *, int);
void			draw_shoot(t_param *,
				   t_bunny_pixelarray *);
void			draw_biggun(t_param *);
void			draw_biggun2(t_param *);
void			draw_gunshot(t_param *);
void			draw_reload(t_param *);
void			draw_punch(t_param *);
void			draw_sulf(t_param *);
void			draw_sulf2(t_param *);
void			draw_sulf3(t_param *);
void			draw_knife(t_param *);
void			keyboard_interface(t_param *);
void			keyboard_interface2(t_bunny_event_state,
					    t_bunny_keysym,
					    t_param *);
void			keyboard_interface3(t_bunny_event_state,
					    t_bunny_keysym,
					    t_param *);
void			draw_scope(t_param *);
void			transition(t_param *);
void			weapon(t_param *);
void			action_weapon(t_param *);
void			draw_action(t_param *);
void			draw_action2(t_param *);
void			action_reload(t_param *);

#endif /* !TEKDOOM_H_ */
