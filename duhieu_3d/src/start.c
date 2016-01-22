/*
** main.c<2> for main in /home/duhieu_b/infographie/rendu/gfx_wolf3d/src
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Jan 15 12:29:58 2016 benjamin duhieu
** Last update Fri Jan 22 19:39:50 2016 benjamin duhieu
*/

#include "main.h"

t_bunny_response		main_mouse(const t_bunny_position *relative,
					   void	*data)
{
  const t_bunny_position	*pos;
  t_main			*doom;

  doom = data;
  pos = bunny_get_mouse_position();
  if (!doom->mouse)
    {
      doom->pars.maps->next->lvls->next->pla += relative->x / 10;
      if (doom->pars.maps->next->lvls->next->pla > 359)
	doom->pars.maps->next->lvls->next->pla -= 359;
      if (doom->pars.maps->next->lvls->next->pla < 0)
	doom->pars.maps->next->lvls->next->pla += 359;
    }
  else
    doom->mouse = 0;
  if (pos->x >= WIDTH - 200 || pos->x <= ((WIDTH - WIDTH) + 200))
    {
      bunny_set_mouse_position_window(doom->win, WIDTH / 2, HEIGHT / 2);
      doom->mouse = 1;
    }
  return (GO_ON);
}

t_bunny_response	main_echap(t_bunny_event_state state,
				   t_bunny_keysym keysym,
				   void *data)
{
  const bool		*key;

  key = bunny_get_keyboard();
  data = data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (key[BKS_Z])
    write(1, "l", 1);
  /* if (key[BKS_S]) */
  /*     back(doom); */
  /* if (key[BKS_Q]) */
  /*   move(wolf, -90, -0.075); */
  /* if (key[BKS_D]) */
  /*   move(wolf, -90, 0.075); */
  return (GO_ON);
}

t_bunny_response	main_loop(void *main)
{
  t_main		*doom;

  doom = main;
  fill_screen(doom->pix);
  calc(doom);
  bunny_blit(&(doom->win->buffer), &(doom->pix->clipable), NULL);
  bunny_display(doom->win);
  bunny_set_key_response(main_echap);
  bunny_set_move_response(main_mouse);
  return (GO_ON);
}

int	init_main(int argc, char **argv, char **ae, t_main *doom)
{
  if (*ae == NULL)
    return (1);
  if (argc != 1 || argv == NULL)
    return (1);
  init_data(doom);
  return (0);
}

int		main(int argc, char **argv, char **ae)
{
  t_main	doom;

  if (init_main(argc, argv, ae, &doom))
    return (1);
  doom.mouse = 0;
  doom.pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  doom.win = bunny_start(WIDTH, HEIGHT, false, "doom");
  bunny_set_mouse_position_window(doom.win, WIDTH / 2, HEIGHT / 2);
  bunny_set_mouse_visibility(doom.win, 0);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(doom.win, 60, &doom);
  bunny_delete_clipable(&(doom.pix->clipable));
  bunny_stop(doom.win);
  return (0);
}
