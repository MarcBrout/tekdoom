/*
** textures.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Jan 25 02:40:20 2016 marc brout
** Last update Tue Jan 26 22:09:57 2016 maud marel
*/

#include "tekdoom.h"

char	get_textures(t_param *tpar)
{
  tpar->textures[NBTXT] = NULL;
  if (!(tpar->textures[0] = bunny_load_pixelarray(TXT_1)) ||
      !(tpar->textures[1] = bunny_load_pixelarray(TXT_2)) ||
      !(tpar->textures[2] = bunny_load_pixelarray(TXT_3)))
    return (1);
  return (0);
}

/* void	project_textures(t_param *tpar, t_lvl *lvl) */
/* { */
/* } */
