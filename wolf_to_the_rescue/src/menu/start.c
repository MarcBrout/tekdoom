/*
** main.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 20 18:46:14 2015 Mathieu Sauvau
** Last update Tue Jan 26 16:48:52 2016 Mathieu Sauvau
*/

#include "menu.h"

void			loop_next(t_data *data)
{
 if (data->menu_index == 0)
    write_main_menu(data);
  else if (data->menu_index == 1)
    write_option_menu(data);
  else if (data->menu_index == 2)
    write_credit_menu(data);
  else if (data->menu_index == 3 && !INPUT->change_key)
    write_input_menu(data);
  if (INPUT->change_key)
    write_change_key(data);
}

t_bunny_response	mainloop(void	*my_data)
{
  t_data		*data;

  data = my_data;
  cpy_bg(data->pix_ar, data->bg);
  /*  my_fill(data->pix_ar, PINK);*/
  /*  bunny_blit(&data->win->buffer, data->bg, &data->pos);*/
  if (data->menu_index == 0)
    main_menu(data, data->rect, HEIGHT / 2, 20);
  else if (data->menu_index == 1)
    option_menu(data, data->selected_index);
  else if (data->menu_index == 2)
    credit_menu(data);
  else if (data->menu_index == 3 && !INPUT->change_key)
    input_menu(data, data->rect_input, 0, 20);
  if (INPUT->change_key)
    label(data, false, pos_(400, 200),
	  pos_(WIDTH / 2 - 200, HEIGHT / 2 - 100));
  bunny_blit(&data->win->buffer, &data->pix_ar->clipable, &data->pos);
  loop_next(data);
  bunny_display(data->win);
  return (GO_ON);
}

int			launch(t_data *data)
{
  if (init_data(data) == 1)
    return (-1);
  memory_check = 1;
  if ((data->win = bunny_start(WIDTH, HEIGHT,
			      CONFIG->fullscreen, "TEk-DOOM")) == NULL
      || (data->pix_ar = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (-1);
  bunny_blit(&data->win->buffer, &data->pix_ar->clipable, &data->pos);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&esc);
  bunny_loop(data->win, 10, data);
  return (0);
}

int			start(t_data *data)
{
  if (launch(data) == -1)
    return (1);
  bunny_delete_clipable(&data->pix_ar->clipable);
  bunny_delete_ini(data->config->ini);
  bunny_free(data->config);
  bunny_stop(data->win);
  return (0);
}
