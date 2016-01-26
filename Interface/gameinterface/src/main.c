/*
** main.c for main in /home/marel_m/Rendu/Infographie/gfx_wolf3d
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Dec 16 17:28:05 2015 maud marel
** Last update Sun Jan 24 23:07:05 2016 maud marel
*/

#include "interface.h"

void			interface(t_data *data)
{
  if ((data->life.pos_life.x == ((WIDTH / 75) - 2)) && data->life.nb_heart == 1)
    {
      my_set_square(data->pix, BLACK);
	draw_game_over(data);
    }
  else if ((data->life.pos_life.x == ((WIDTH / 75) - 2)) && data->life.nb_heart == 2)
    {
      my_set_square(data->pix, BLACK);
	draw_last_chance(data);
    }
  else if ((data->life.pos_life.x == ((WIDTH / 75) - 2)) && data->life.nb_heart == 3)
    {
      my_set_square(data->pix, BLACK);
      draw_try_again(data);
    }
  if (data->life.nb_heart > 0)
    {
      if (data->life.pos_life.x == ((3 * WIDTH) / 10 - 1))
	{
	  my_set_square(data->pix, WHITE);
	  draw_square_life(data);
	  draw_life_bar(data);
	  draw_heart(data);
	  draw_bullet(data);
	}
      if (data->life.ok == 1)
	{
	  draw_life_bar(data);
	  data->life.ok = 0;
	}
      if (data->life.life != 100)
	{
	  data->life.speed = 3;
	  draw_move_life(data);
	}
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
  if (key == BKS_A && state == GO_DOWN && all->life.nb_heart > 0)
    {
      all->life.life = 100;
      all->life.ok = 1;
      all->life.nb_heart--;
      all->life.end = 0;
    }
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (key == BKS_RETURN && state == GO_DOWN)
    {
      if (all->bullet.nb_bullet == 0)
	all->bullet.nb_bullet = 5;
      else
	all->bullet.nb_bullet--;
    }
  return (GO_ON);
}

void	interface_init(t_data *data)
{
  data->life.ok = 0;
  data->life.end = 0;
  data->life.life = 100;
  data->life.nb_heart = 3;
  data->bullet.nb_bullet = 5;
  my_set_square(data->pix, WHITE);
  draw_square_life(data);
  draw_life_bar(data);
}

int	load_picture(t_data *data)
{
  if ((data->trigger.game_over
       = bunny_load_pixelarray("pictures/gameover.png")) == NULL)
    return (-1);
  if ((data->trigger.lastchance
       = bunny_load_pixelarray("pictures/lastchance.bmp")) == NULL)
    return (-1);
  if ((data->trigger.try_again
       = bunny_load_pixelarray("pictures/try_again.jpg")) == NULL)
    return (-1);
  return (0);
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
  if (load_picture(&data) == -1)
    return (-1);
  escape = &my_escape;
  loop = &my_loop;
  bunny_set_key_response(escape);
  bunny_set_loop_main_function(loop);
  bunny_loop(data.win, 50, &data);
  bunny_stop(data.win);
  bunny_delete_clipable(&data.pix->clipable);
  return (0);
}
