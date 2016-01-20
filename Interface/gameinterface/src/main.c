/*
** main.c for main in /home/marel_m/Rendu/Infographie/gfx_wolf3d
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:28:05 2015 maud marel
** Last update Wed Jan 20 19:01:28 2016 Maud MAREL
*/

#include "lifebar.h"

void			interface(t_data *data)
{
  draw_heart(data);
  if (data->life.ok == 1)
    {
      draw_life_bar(data);
      data->life.ok = 0;
    }
  if (data->life.life != 100)
    {
      data->life.pos_life.x--;
      draw_move_life(data);
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
      if (all->life.life > 25)
	{
	  all->life.life -= 25;
	  all->life.pos_limit.x = (all->life.life * 3 * WIDTH) / 1000;
	}
      else
	{
	  all->life.pos_limit.x = (WIDTH / 75) - 1;
	  all->life.end = 1;
	}
    }
  if (key == BKS_A && state == GO_DOWN)
    {
      all->life.life = 100;
      all->life.ok = 1;
      all->life.nb_heart--;
      all->life.end = 0;
    }
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

void	interface_init(t_data *data)
{
  data->life.ok = 0;
  data->life.end = 0;
  data->life.life = 100;
  data->life.nb_heart = 3;
  my_set_square(data->pix);
  draw_life_bar(data);
  draw_square_life(data);
  draw_bullet_start(data);
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
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "interface")) == NULL)
    return (-1);
  interface_init(&data);
  escape = &my_escape;
  loop = &my_loop;
  bunny_set_key_response(escape);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 50, &data);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
