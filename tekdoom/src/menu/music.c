/*
** music.c for music
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Jan 26 11:11:29 2016 benjamin duhieu
** Last update Wed Jan 27 07:11:39 2016 maud marel
*/

#include "menu.h"

void	disp_sound(t_data *data)
{
  if (data->sound == 1)
    {
      bunny_sound_play(data->music);
      data->sound = -1;
    }
  bunny_sound_loop(data->music, true);
  bunny_sound_volume(data->music, (double)data->config->volume);
  bunny_sound_volume(data->menu_nav, CONFIG->volume);
  bunny_sound_volume(data->menu_select, CONFIG->volume);
  bunny_sound_volume(data->play, CONFIG->volume);
}
