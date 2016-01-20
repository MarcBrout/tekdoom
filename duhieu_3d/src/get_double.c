/*
** get_double.c for doom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Jan 20 22:50:36 2016 marc brout
** Last update Wed Jan 20 23:50:46 2016 marc brout
*/

double		get_double(char *str)
{
  double	dec;
  int		ent;
  int		neg;
  int		count;
  int		i;

  i = -1;
  neg = 1;
  while (str[++i] && (str[i] == '-' || str[i] == '+'))
    if (str[i] == '-')
      neg = -neg;
  ent = 0;
  while (str[i] && str[i] != '.' && str[i] >= '0' && str[i] <= '9')
    ent = (ent * 10) + (str[i++] - 48);
  dec = 0;
  count = 1;
  i += (str[i] == '.') ? 1 : 0;
  while (str[i] && str[i] >= '0' && str[i] <= '9' && (count *= 10))
    dec = (dec * 10) + (str[i++] - 48);
  return ((double)ent + (dec / count));
}
