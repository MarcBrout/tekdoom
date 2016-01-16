/*
** main.c for main in /home/marel_m/Rendu/Infographie/gfx_wolf3d
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:28:05 2015 maud marel
** Last update Fri Jan 15 09:51:46 2016 Maud MAREL
*/

#include "interface.h"

t_bunny_response	my_loop(void *data)
{
  t_data		*all;

  all = (void*)data;
  bunny_blit(&all->win->buffer,
	     &all->pix->clipable, NULL);
  bunny_display(all->win);
  return (GO_ON);
}

t_bunny_response	my_escape(t_bunny_event_state state,
				  t_bunny_keysym key,
				  UNUSED void *data)
{
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_data		data;
  t_bunny_key		escape;
  t_bunny_loop		loop;

  if (*env == NULL)
    return (-1);
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (-1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, true, "interface")) == NULL)
    return (-1);
  my_set_square(data.pix);
  draw_life_bar(&data);
  draw_square_life_bar(&data);
  draw_life(&data);
  escape = &my_escape;
  loop = &my_loop;
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(escape);
  bunny_loop(data.win, 60, &data);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
