/*
** parse.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan 15 02:14:11 2016 marc brout
** Last update Fri Jan 15 12:32:05 2016 marc brout
*/

#include "main.h"

char		open_folder(t_parse *parse, char *folder)
{
  DIR		*dir;
  dirent	*file;

  if ((dir = opendir(folder)) == NULL)
    return (1);
  while ((file = readdir(dir)) != NULL)
    {
      
    }
  return (0);
}

char		add_map(t_ini *maps, char *str)
{
  t_ini		*ini;
  t_ini		elem;

  ini = maps;
  while (ini->next != NULL)
    ini = ini->next;
  elem->file = str;
  elem->next = NULL;
  ini->next = elem;
  return (0);
}

char		set_paths(t_parse *parse)
{
  parse->maps.file = "root";
  parse->maps.next = NULL;
  parse->folder[0] = "files/maps";
  parse->folder[1] = NULL;
}

char		open_ini(t_parse *parse, char **path)
{
  if ((parse.ini = bunny_load_ini(path)) == NULL)
    return (1);
  if ((parse.scope = bunny_ini_first(parse.ini)) == NULL)
    return (1);
  if ((parse.scope = bunny_ini_next(parse.ini, parse.scope)) == NULL)
    reuturn (1);
  return (0);
}

char		parse()
{
  t_parse	parse;
  int		i;
  
  i = -1;
  set_paths(parse);
  while (parse.folder[++i])
    {
      if (!access(parse.folder[i]))
	write(2, "missing folder\n", 18);
      if (open_ini(&parse, parse.folder[i]))
	write(2, "file missing or corrupted\n", 27);
    }
  return (0);
}

void		main()
{
  parse();
}
