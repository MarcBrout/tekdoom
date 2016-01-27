/*
** my_strlen.c for my_strlen in /home/brout_m/dev/PJ4
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Oct  1 16:44:35 2015 marc brout
** Last update Fri Jan 22 15:33:03 2016 Mathieu Sauvau
*/

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
