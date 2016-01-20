/*
** main.c<2> for main in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:29:58 2016 benjamin duhieu
** Last update Tue Jan 19 21:42:34 2016 benjamin duhieu
*/

#include "main.h"

t_bunny_response	main_loop(void *main)
{
  t_main		*doom;

  doom = main;
  fill_screen(doom->pix);
  calc(doom);
  bunny_blit(&(doom->win->buffer), &(doom->pix->clipable), NULL);
  bunny_display(doom->win);
  /* bunny_set_key_response(main_echap); */
  /* bunny_set_move_response(main_mouse); */
  return (GO_ON);
}

int	init_main(int argc, char **argv, char **ae, t_main *doom)
{
  if (*ae == NULL)
    return (1);
  if (argc != 1 || argv == NULL)
    return (1);
  /* if ((doom->ini = bunny_load_ini(argv[1])) == NULL) */
  /*   return (1); */
  /* if ((doom->music = bunny_load_music */
  /*      ("Pan_39_s_Labyrinth_Lullaby_-_Piano_and_Violin_Vers.ogg")) == NULL) */
  /*   return (1); */
  /* doom->sound = 0; */
  /* if (ini(doom)) */
  /*   return (1); */
  init_data(doom);
  return (0);
}

int		main(int argc, char **argv, char **ae)
{
  t_main	doom;

  if (init_main(argc, argv, ae, &doom))
    return (1);
  /* doom.mouse = 0; */
  doom.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  doom.win = bunny_start(WIDTH, HEIGHT, false, "doom");
  /* bunny_set_mouse_position_window(doom.win, WIDTH / 2, HEIGHT / 2); */
  /* bunny_set_mouse_visibility(doom.win, 0); */
  bunny_set_loop_main_function(main_loop);
  bunny_loop(doom.win, 60, &doom);
  bunny_delete_clipable(&(doom.pix->clipable));
  bunny_stop(doom.win);
  /* bunny_delete_ini(doom.ini); */
  /* bunny_delete_sound(doom.music); */
  return (0);
}
