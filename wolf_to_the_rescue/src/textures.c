/*
** textures.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Jan 25 02:40:20 2016 marc brout
** Last update Wed Jan 27 00:35:11 2016 marc brout
*/

#include "wolf.h"

char	get_textures(t_param *tpar)
{
  tpar->textures[NBTXT] = NULL;
  if (!(tpar->textures[0] = bunny_load_pixelarray(TXT_1)) ||
      !(tpar->textures[1] = bunny_load_pixelarray(TXT_2)) ||
      !(tpar->textures[2] = bunny_load_pixelarray(TXT_3)) ||
      !(tpar->textures[3] = bunny_load_pixelarray(TXT_4)) ||
      !(tpar->textures[4] = bunny_load_pixelarray(TXT_5)))
    return (1);
  tpar->sprites[NBOBJ] = NULL;
  if (!(tpar->sprites[0] = bunny_load_pixelarray(OBJ_1)))
    return (1);
  return (0);
}
