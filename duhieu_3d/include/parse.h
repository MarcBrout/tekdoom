/*
** parse.h for doom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Jan 15 02:08:10 2016 marc brout
** Last update Sun Jan 24 11:42:54 2016 Mathieu Sauvau
*/

#ifndef PARSE_H_
# define PARSE_H_

# ifndef UNUSED
#  define UNUSED __attribute__((__unused__))
# endif /* !UNUSED */

# ifndef BISGF
#  define BISGF bunny_ini_scope_get_field
# endif /* !BISGF */

# define E_FLD "Missing folder\n"
# define E_FIL "File missing or corrupted\n"
# define E_PARSE "Parsing error\n"
# define SEGL lvls->segs
# define NBTXT 1

# ifndef TEXTURES
#  define TEXTURES
#  define TXT01 "files/textures/01_brick_wall.png"
# endif /* !TEXTURES */


typedef	enum{cac, dist} weapon_type;

typedef struct		s_seg
{
  double		ax;
  double		ay;
  double		bx;
  double		by;
  double		z;
  int			type;
  struct s_seg		*next;
}			t_seg;

typedef struct		s_lvl
{
  char			*name;
  char			*desc;
  int			**text;
  int			nbseg;
  double		**tabseg;
  int			plx;
  int			ply;
  double		pla;
  t_seg			*segs;
  struct s_lvl		*next;
  struct s_lvl		*prev;
}			t_lvl;

typedef struct		s_ini
{
  char			*file;
  t_lvl			*lvls;
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  struct s_ini		*next;
}			t_ini;

typedef struct		s_parse
{
  t_bunny_pixelarray	*textures[NBTXT];
  char			*folder[2];
  t_ini			*maps;
}			t_parse;

typedef struct		s_weapon
{
  weapon_type		type;
  t_bunny_pixelarray	*img;
  int			attack;
}			t_weapon;

typedef struct		s_player
{
  /* t_life		*life; */
  /* t_bullet		*bullet; */
  t_weapon		*weapon;
}			t_player;

typedef struct		s_enemy
{
  int			life;
  int			attack;
  int			speed;
  t_bunny_pixelarray	*img;
  t_bunny_position	pos;
  t_bunny_position	view;
}			t_enemy;

char mal_tab(t_lvl *);
char segment_listing(t_ini *, t_lvl *);
char set_line_length(int **, int, int);
char set_line_lengthd(double **, int, int);
char parse_map(t_ini *, t_lvl *, int **, char *);
char parse_mapd(t_ini *, t_lvl *, double **, char *);
double get_double(char *);
int my_perror(char *);
char add_lvl(t_ini *);
char parse(t_parse *);
char parse_maps(t_parse *);
char read_folder(t_parse *, char *);
char add_map(t_ini *, char *);
char set_paths(t_parse *);
char open_ini(t_ini *);
char *concat_path(char *, char, char *);

#endif /* !PARSE_H_ */
