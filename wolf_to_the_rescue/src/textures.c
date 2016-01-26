/*
** textures.c for tekdoom
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Jan 25 02:40:20 2016 marc brout
<<<<<<< HEAD
** Last update Tue Jan 26 15:45:00 2016 benjamin duhieu
=======
** Last update Tue Jan 26 11:48:26 2016 marc brout
>>>>>>> 6bb0b2f23731a6f355e3a6c5f61649337d5a4159
*/

#include "wolf.h"

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
