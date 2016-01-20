/*
** main.c for main in /home/marel_m/Rendu/Infographie/gfx_wolf3d
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:28:05 2015 maud marel
** Last update Tue Jan 19 19:06:38 2016 Maud MAREL
*/

#include "interface.h"

void			interface(t_data *data)
{
  if (data->life_bar.ok == 1)
    {
      data->life_bar.pos_life.x--;
      draw_move_life_bar(data);
    }
}

t_bunny_response	my_loop(void *data)
{
  t_data		*all;

  all = (void*)data;
  interface(all);
  bunny_blit(&all->win->buffer,
	     &all->pix->clipable, NULL);
  bunny_display(all->win);
  return (GO_ON);
}

t_bunny_response	my_escape(t_bunny_event_state state,
				  t_bunny_keysym key,
				  void *data)
{
  t_data		*all;

  all = (void*)data;
  if (key == BKS_SPACE && state == GO_DOWN)
    {
      if (all->life_bar.life > 25)
	{
	  all->life_bar.ok = 1;
	  all->life_bar.life -= 25;
	  all->life_bar.pos_limit.x = (all->life_bar.life * 3 * WIDTH) / 1000;
	}
      else
	{
	  all->life_bar.ok = 1;
	  all->life_bar.pos_limit.x = (WIDTH / 75) - 1;
	  all->life_bar.end = 1;
	}
    }
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void	interface_init(t_data *data)
{
  data->life_bar.ok = 0;
  data->life_bar.end = 0;
  data->life_bar.life = 100;
  my_set_square(data->pix);
  draw_square_life_bar(data);
  draw_life_bar(data);
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
  interface_init(&data);
  escape = &my_escape;
  loop = &my_loop;
  bunny_set_key_response(escape);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 200, &data);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
