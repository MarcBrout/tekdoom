/*
** tools.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 17 11:50:43 2016 marc brout
** Last update Sun Jan 17 11:51:30 2016 marc brout
*/

#include "main.h"

int		my_perror(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}

char		*concat_path(char *folder, char c, char *file)
{
  char		*str;
  int		size;
  int		i;
  int		j;

  size = my_strlen(folder) + my_strlen(file) + 1;
  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  str[size] = 0;
  i = -1;
  j = -1;
  while (folder[++j] && (str[++i] = folder[j]));
  str[++i] = c;
  j = -1;
  while (file[++j] && (str[++i] = file[j]));
  return (str);
}
