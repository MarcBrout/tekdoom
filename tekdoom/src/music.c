/*
** music.c for music
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Jan 26 23:45:30 2016 benjamin duhieu
** Last update Wed Jan 27 08:44:18 2016 benjamin duhieu
*/

#include "tekdoom.h"

int	download_music(t_param *arg)
{
  if (((arg->sound = bunny_malloc(sizeof(t_sound))) == NULL) ||
      ((arg->play = bunny_load_music(ZIK_1)) == NULL) ||
      ((arg->sound->cac = bunny_load_effect(ZIK_2)) == NULL) ||
      ((arg->sound->shotgun = bunny_load_effect(ZIK_3)) == NULL) ||
      ((arg->sound->cac2 = bunny_load_effect(ZIK_4)) == NULL) ||
      ((arg->sound->burger = bunny_load_effect(ZIK_5)) == NULL) ||
      ((arg->sound->reload = bunny_load_effect(ZIK_6)) == NULL) ||
      ((arg->sound->door = bunny_load_effect(ZIK_7)) == NULL) ||
      ((arg->sound->bazook = bunny_load_effect(ZIK_8)) == NULL) ||
      ((arg->sound->sulf = bunny_load_effect(ZIK_9)) == NULL) ||
      ((arg->sound->knife = bunny_load_effect(ZIK_10)) == NULL))
    return (1);
  bunny_sound_volume(arg->play, arg->data->config->volume);
  return (0);
}
