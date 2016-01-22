/*
** parse.h for doom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Jan 15 02:08:10 2016 marc brout
** Last update Tue Jan 19 19:49:22 2016 benjamin duhieu
*/

#ifndef PARSE_H_
# define PARSE_H_
# ifndef UNUSED
#  define UNUSED __attribute__((_unused_))
# endif /* !UNUSED */
# ifndef BISGF
#  define BISGF bunny_ini_scope_get_field
# endif /* !BISGF */
# define E_FLD "Missing folder\n"
# define E_FIL "File missing or corrupted\n"
# define E_PARSE "Parsing error\n"

typedef struct		s_lvl
{
  char			*name;
  char			*desc;
  int			wid;
  int			hei;
  int			**type;
  int			**size;
  int			**text;
  int			plx;
  int			ply;
  int			pla;
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
  char			*folder[2];
  t_ini			*maps;
}			t_parse;

int my_perror(char *);
char add_lvl(t_ini *);
char parse_maps(t_parse *);
char read_folder(t_parse *, char *);
char add_map(t_ini *, char *);
char set_paths(t_parse *);
char open_ini(t_ini *);
char *concat_path(char *, char, char *);

#endif /* !PARSE_H_ */
