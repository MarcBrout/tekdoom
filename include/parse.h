/*
** parse.h for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 15 02:08:10 2016 marc brout
** Last update Fri Jan 15 12:11:00 2016 marc brout
*/

#ifndef PARSE_H_
# define PARSE_H_
# ifndef UNUSED
#  define UNUSED __attribute__((_unused__))
# endif /* !UNUSED */
# ifndef BISGF
#  define BISGF bunny_ini_scope_get_field
# endif /* !BISGF */

typedef struct		s_ini
{
  char			*file;
  struct s_ini		*next;
}			t_ini;

typedef struct		s_parse
{
  t_bunny_ini		*ini;
  t_bunny_ini_scope	*scope;
  char			*folder[2];
  t_ini			maps;
}			t_parse;


#endif /* !PARSE_H_ */
