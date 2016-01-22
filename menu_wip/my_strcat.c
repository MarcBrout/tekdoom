/*
** my_strcat.c for strcat in /home/sauvau_m/rendu/Piscine_C_J07/lib/my
** 
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
** 
** Started on  Tue Oct  6 10:41:35 2015 Mathieu Sauvau
** Last update Tue Oct  6 11:15:53 2015 Mathieu Sauvau
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	dest_l;
  int	src_l;

  i = 0;
  src_l = my_strlen(src);
  dest_l = my_strlen(dest);
  while (i < src_l)
    {
      dest[dest_l + i] = src[i];
      i++;
    }
  dest[dest_l + i] = '\0';
  return (dest);
}
