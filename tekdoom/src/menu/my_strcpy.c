/*
** my_strcpy.c for str copy in /home/sauvau_m/rendu/Piscine_C_J06
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon Oct  5 10:09:58 2015 Mathieu Sauvau
** Last update Tue Jan 26 22:10:37 2016 Mathieu Sauvau
*/

char	*my_strcpy(char *dest, char *src)
{
  int	 i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
