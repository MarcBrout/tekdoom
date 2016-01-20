/*
** parse.c for doom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Jan 15 02:14:11 2016 marc brout
** Last update Tue Jan 19 20:05:36 2016 benjamin duhieu
*/

#include "main.h"

char		read_folder(t_parse *parse, char *folder)
{
  DIR		*dir;
  struct dirent	*file;
  char		*str;
  int		i;

  if ((dir = opendir(folder)) == NULL)
    return (1);
  i = 0;
  while ((file = readdir(dir)) != NULL && ++i)
    {
      my_revstr(file->d_name);
      if (!my_strncmp(file->d_name, "ini.", 3))
	{
	  my_revstr(file->d_name);
	  if ((str = concat_path(folder, '/', file->d_name)) == NULL ||
	      (add_map(parse->maps, str)))
	    return (1);
	  free(str);
	}
    }
  return (0);
}

char		add_map(t_ini *maps, char *str)
{
  t_ini		*ini;
  t_ini		*elem;

  ini = maps;
  while (ini->next != NULL)
    ini = ini->next;
  if ((elem = malloc(sizeof(t_ini))) == NULL ||
      (elem->lvls = malloc(sizeof(t_lvl))) == NULL)
    return (1);
  elem->file = my_strdup(str);
  elem->next = NULL;
  elem->lvls->next = elem->lvls;
  elem->lvls->prev = elem->lvls;
  ini->next = elem;
  return (0);
}

char		set_paths(t_parse *parse)
{
  if ((parse->maps = malloc(sizeof(t_ini))) == NULL)
    return (1);
  parse->maps->file = "root";
  parse->maps->next = NULL;
  parse->folder[0] = "files/maps";
  parse->folder[1] = NULL;
  return (0);
}

char		parse(t_parse *parse)
{
  int		i;

  i = -1;
  if (set_paths(parse))
    return (1);
  while (parse->folder[++i] != NULL)
    if (read_folder(parse, parse->folder[i]))
      return (my_perror(E_PARSE));
  parse_maps(parse);
  return (0);
}
