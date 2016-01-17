/*
** my_revstr.c for my_revstr in /home/brout_m/dev/piscine/PJ6
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Oct  5 13:49:10 2015 marc brout
** Last update Fri Jan 15 12:31:16 2016 marc brout
*/

char	*my_revstr(char *str)
{
  int	i;
  int	end;
  char	stock;

  i = -1;
  end = my_strlen(str);
  while (++i < (my_strlen(str) / 2) && end--)
    {
      stock = str[i];
      str[i] = str[end];
      str[end] = stock;
    }
  return (str);
}
