/*
** music.c for music
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Jan 26 23:45:30 2016 benjamin duhieu
** Last update Wed Jan 27 01:55:10 2016 benjamin duhieu
*/

#include "wolf.h"

int	download_music(t_param *arg)
{
  if ((arg->play = bunny_load_music(ZIK_1)) == NULL)
    return (1);
  if ((arg->sound->cac = bunny_load_effect(ZIK_2)) == NULL)
    return (1);
  if ((arg->sound->shotgun = bunny_load_effect(ZIK_3)) == NULL)
    return (1);
  if ((arg->sound->cac2 = bunny_load_effect(ZIK_4)) == NULL)
    return (1);
  if ((arg->sound->burger = bunny_load_effect(ZIK_5)) == NULL)
    return (1);
  if ((arg->sound->reload = bunny_load_effect(ZIK_6)) == NULL)
    return (1);
  if ((arg->play->door = bunny_load_effect(ZIK_7)) == NULL)
    return (1);
  if ((arg->play->bazook = bunny_load_effect(ZIK_8)) == NULL)
    return (1);
  if ((arg->play->sulf = bunny_load_effect(ZIK_9)) == NULL)
    return (1);
  if ((arg->play->knife = bunny_load_effect(ZIK_10)) == NULL)
    return (1);
  return (0);
}
