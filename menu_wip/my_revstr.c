/*
** my_revstr.c for revstr in /home/sauvau_m/rendu/Piscine_C_J06/ex_04
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Oct  5 11:07:42 2015 Mathieu Sauvau
** Last update Fri Jan  8 22:26:07 2016 Mathieu Sauvau
*/

char	*my_revstr(char *str)
{
  int	i;
  int	l;
  char	tmp;

  i = 0;
  l = my_strlen(str);
  while (i < (l / 2))
    {
      tmp = str[i];
      str[i] = str[l - i - 1];
      str[l - i - 1] = tmp;
      i++;
    }
  return (str);
}
