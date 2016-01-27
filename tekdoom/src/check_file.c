/*
** check_file.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Dec 18 11:06:07 2015 marc brout
** Last update Wed Jan 27 03:57:56 2016 benjamin duhieu
*/

#include "tekdoom.h"

char		open_ini(t_param *arg, UNUSED char **av)
{
  if ((arg->ini = bunny_load_ini("files/ini/basic_format.ini")) == NULL)
    return (1);
  if (FLD(arg->ini, NULL, "lvlnb", 0) == NULL ||
      !(my_strcmp(FLD(arg->ini, NULL, "lvlnb", 0), "0")) ||
      FLD(arg->ini, NULL, "lvlscope", 0) == NULL)
    return (1);
  return (0);
}

char		check_lvl(t_param *arg,  char *name)
{
  if (FLD(arg->ini, name, "name", 0) == NULL ||
      FLD(arg->ini, name, "tile_size", 0) == NULL ||
      !my_strcmp((char *)FLD(arg->ini, name, "tile_size", 0), "0") ||
      FLD(arg->ini, name, "width", 0) == NULL ||
      !my_strcmp((char *)FLD(arg->ini, name, "width", 0), "0") ||
      FLD(arg->ini, name, "height", 0) == NULL ||
      !my_strcmp((char *)FLD(arg->ini, name, "height", 0), "0") ||
      FLD(arg->ini, name, "data", 0) == NULL ||
      FLD(arg->ini, name, "start_position", 0) == NULL ||
      FLD(arg->ini, name, "start_position", 1) == NULL ||
      FLD(arg->ini, name, "start_position", 2) == NULL)
    return (1);
  return (0);
}

char		check_all_lvl(t_param *arg)
{
  char		*name;
  int		i;

  arg->nblvl = my_getnbr((char *)FLD(arg->ini, NULL, "lvlnb", 0));
  i = -1;
  while (++i < arg->nblvl &&
	 (name = (char *)FLD(arg->ini, NULL, "lvlscope", i)) != NULL)
    if (check_lvl(arg, name))
      return (1);
  if (i != arg->nblvl)
    return (1);
  return (0);
}

char		check_args(int ac, char **env)
{
  if (ac > 1)
    {
      write(2, "Usage : ./tekdoom\n", 28);
      return (1);
    }
  if (env[0] == NULL)
    {
      write(2, "Missing Environnement Variables\n", 33);
      return (2);
    }
  return (0);
}
