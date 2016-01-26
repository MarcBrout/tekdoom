/*
** textures.c for tekdoom
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Jan 25 02:40:20 2016 marc brout
** Last update Tue Jan 26 11:48:26 2016 marc brout
*/

#include "wolf.h"

char	get_textures(t_param *tpar)
{
  tpar->textures[NBTXT] = NULL;
  if (!(tpar->textures[0] = bunny_load_pixelarray(TXT_1)) ||
      !(tpar->textures[1] = bunny_load_pixelarray(TXT_2)))
    return (1);
  return (0);
}

/* void	project_textures(t_param *tpar, t_lvl *lvl) */
/* { */
  
/* } */
