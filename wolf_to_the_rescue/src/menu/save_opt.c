/*
** save_opt.c for tekdoom in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:41:40 2016 Mathieu Sauvau
** Last update Mon Jan 25 17:29:24 2016 Mathieu Sauvau
*/

#include <menu.h>

void			save_input(t_data *data)
{
  char			convert_int[12];

  if (CONFIG->ini)
    {
      itoa(INPUT->key[0], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "up", 0, convert_int);
      itoa(INPUT->key[1], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "down", 0, convert_int);
      itoa(INPUT->key[2], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "left", 0, convert_int);
      itoa(INPUT->key[3], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "right", 0, convert_int);
      itoa(INPUT->key[4], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "jump", 0, convert_int);
      itoa(INPUT->key[5], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "reload", 0, convert_int);
      itoa(INPUT->key[6], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "action", 0, convert_int);
      itoa(INPUT->key[7], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "fire", 0, convert_int);
      itoa(INPUT->key[8], convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "input", "zoom", 0, convert_int);
      bunny_save_ini(CONFIG->ini, "config.ini");
    }
}

void			save_opt(t_data *data)
{
  char			convert_int[12];

  if (CONFIG->ini)
    {
      itoa(CONFIG->fullscreen, convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "config", "fullscreen", 0, convert_int);
      itoa(CONFIG->volume, convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "config", "volume", 0, convert_int);
      itoa(RES[CONFIG->res_i].width, convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "config", "width", 0, convert_int);
      itoa(RES[CONFIG->res_i].height, convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "config", "height", 0, convert_int);
      itoa(CONFIG->fov, convert_int, 10);
      bunny_ini_set_field(CONFIG->ini, "config", "fov", 0, convert_int);
      bunny_save_ini(CONFIG->ini, "config.ini");
    }
}
