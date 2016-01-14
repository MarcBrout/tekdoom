/*
** main.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 20 18:46:14 2015 Mathieu Sauvau
** Last update Thu Jan 14 20:26:21 2016 Mathieu Sauvau
*/

#include <math.h>
#include "struct.h"

t_bunny_position	pol_to_carth(t_bunny_position *pol)
{
  t_bunny_position	convert;

  convert.x = pol->x * cos(pol->y * M_PI / 180);
  convert.y = pol->x * sin(pol->y * M_PI / 180);
  return (convert);
}

t_bunny_position	carth_to_pol(t_bunny_position *carth)
{
  t_bunny_position	convert;

  convert.x = sqrt(pow(carth->x, 2) + pow(carth->y, 2));
  convert.y = atan2(carth->x, carth->y);
  return (convert);
}

void			create_pov(t_bunny_pixelarray *pix_ar,
				   t_bunny_position pos,
				   t_bunny_position view)
{
  t_bunny_position	pov;

  tekpixel(pix_ar, pos, WHITE);
  pov = pol_to_carth(&view);
  pov.x += pos.x;
  pov.y += pos.y;
  tekpixel(pix_ar, pov, RED);
}

t_bunny_response	esc(t_bunny_event_state state, t_bunny_keysym keysym,
			    void *data)
{
  t_data		*my_data;

  (void)state;
  my_data = data;
  if (keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (keysym == BKS_UP && state == GO_DOWN)
    my_data->selected_index == 0 ?
      my_data->selected_index = my_data->menu_length - 1 : my_data->selected_index--;
  if (keysym == BKS_DOWN && state == GO_DOWN)
    my_data->selected_index == my_data->menu_length - 1 ?
      my_data->selected_index = 0 : my_data->selected_index++;
  if (keysym == BKS_SPACE && state == GO_DOWN)
    {
      if (my_data->menu_index == 0)
	{
	  //	  if (my_data->selected_index == 0)
	    //profl name for save -> play
	  if (my_data->selected_index == 1)
	    {
	      my_data->selected_index = 0;
	      my_data->menu_index = 1;
	    }
	  if (my_data->selected_index == 2)
	    {
	      my_data->selected_index = 0;
	      my_data->menu_index = 2;
	    }
	  if (my_data->selected_index == 3)
	    exit(0);
	}
      if (my_data->menu_index == 1)
	{
	  if (my_data->selected_index == 0)
	    my_data->config->fullscreen = !my_data->config->fullscreen;

	}
    }
  /*  if (keysym == BKS_Z)
    my_data->pos2.y -= 1;
  if (keysym == BKS_S)
    my_data->pos2.y += 1;
  if (keysym == BKS_Q)
    my_data->pos2.x -= 1;
  if (keysym == BKS_D)
    my_data->pos2.x += 1;

  if (keysym == BKS_UP)
    my_data->view.x += 5;
  if (keysym == BKS_DOWN)
    my_data->view.x -= 5;
  if (keysym == BKS_LEFT)
    {
      my_data->view.y -= 5;
    }
  if (keysym == BKS_RIGHT)
    {
      my_data->view.y += 5;
    }*/
  return (GO_ON);
}

t_bunny_response	mainloop(void	*data)
{
  t_data		*my_data;

  my_data = data;
    my_fill(my_data->pix_ar, BLACK);
  if (my_data->menu_index == 0)
    main_menu(my_data);
  if (my_data->menu_index == 1)
    option_menu(my_data, 1, my_data->selected_index);
  //create_pov(my_data->pix_ar, my_data->pos2, my_data->view);

  bunny_blit(&my_data->win->buffer, &my_data->pix_ar->clipable, &my_data->pos);
  t_bunny_position pos = my_data->rect[0].pos;
  pos.x -= my_data->rect[0].size.x / 2 + 40;
  write_bmp(my_data, "Play", pos);
  bunny_display(my_data->win);
  return (GO_ON);
}

void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color)
{
  int                   x;
  int                   y;
  t_color               *col;
  int                   new_pos;

  x = 0;
  y = 0;
  col = pix_ar->pixels;
  while (x < pix_ar->clipable.clip_width)
    {
      while (y < pix_ar->clipable.clip_height)
        {
          new_pos = pix_ar->clipable.clip_width * y  + x;
          col[new_pos].full = color;
          y++;
        }
      x++;
      y = 0;
    }
}

void                    draw_square(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect)
{
  int			x;
  int			y;

  x = rect->pos.x;
  y = rect->pos.y;
  while (rect->pos.x < rect->size.x + x)
    {
      while (rect->pos.y < rect->size.y + y)
        {
	  if (rect->selected &&
	      (rect->pos.x <= x + rect->contour - 1
	       || rect->pos.x >= rect->size.x + x - rect->contour ||
	       rect->pos.y <= y + rect->contour - 1
	       || rect->pos.y >= rect->size.y + y - rect->contour))
	    tekpixel(pix_ar, rect->pos, rect->color[1]);
	  else
	      tekpixel(pix_ar, rect->pos, rect->color[0]);
          rect->pos.y++;
        }
      rect->pos.x++;
      rect->pos.y = y;
    }
}

void			check_box(t_data *data, bool selected, bool activated)
{
  t_mrect		rect[2];

  rect[0].size.x = 200;
  rect[0].size.y = 50;
  rect[0].pos.x = data->config->width / 2 - rect[0].size.x / 2;
  rect[0].pos.y = data->config->height / 2;
  rect[0].selected = selected;
  rect[0].color[0] = WHITE;
  rect[0].color[1] = RED;
  rect[0].contour = 3;
  draw_square(data->pix_ar, &rect[0]);

  rect[1].size.x = 50;
  rect[1].size.y = 50;
  rect[1].pos.x = rect[0].pos.x + 10 ;//+ rect[0].size.x / 2 + rect[1].size.x / 2;
  rect[1].pos.y = rect[0].pos.y;
  rect[1].selected = activated;
  if (!activated)
    {
      rect[1].color[0] = WHITE;
      rect[1].color[1] = RED;
    }
  else
    {
      rect[1].color[0] = RED;
      rect[1].color[1] = WHITE;
    }
  rect[1].contour = 5;
  draw_square(data->pix_ar, &rect[1]);
}

void			option_menu(t_data *data,
				    int nb, int selected_index)
{
  if (selected_index == 0)
    {
      check_box(data, true, data->config->fullscreen);
    }
  else
    check_box(data, false, data->config->fullscreen);
}

void			write_bmp(t_data *data, char *txt, t_bunny_position start)
{
  char			path[1024];
  int			i;
  int			l_path;
  t_bunny_position	pos;
  t_bunny_picture	*pic;

  i = -1;
  getcwd(path, 1024);
  strcat(path, "/text/");
  strcat(path,"a");
  strcat(path, ".bmp");
  l_path = strlen(path);
  pos = start;
  while (txt[++i])
    {
      path[l_path - 5] = txt[i];
      pic = bunny_load_picture(path);
      bunny_blit(&data->win->buffer, pic, &pos);
      pos.x += 20;
      bunny_delete_clipable(pic);
    }
}

void			main_menu(t_data *data)
{
  int			n;
  int			margin;
  int			offset;

  n = -1;
  margin = 20;
  offset = data->config->height / 2;
  data->rect[0].pos.y = offset;
  while (++n < data->menu_length)
    {
      data->rect[n].size.x = data->config->width / 2;
      data->rect[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      data->rect[n].pos.x = data->config->width / 2 - data->rect[n].size.x / 2;
      if (n != 0)
	data->rect[n].pos.y = data->rect[n - 1].pos.y + data->rect[n].size.y + margin;
      data->rect[n].color[0] = WHITE;
      data->rect[n].color[1] = RED;
      data->rect[n].contour = 3;
      if (n == data->selected_index)
	data->rect[n].selected = true;
      else
	data->rect[n].selected = false;
      draw_square(data->pix_ar, &data->rect[n]);
    }
}

void			default_config(t_data *data)
{
  data->config->fullscreen = false;
  data->config->width = 800;
  data->config->height = 600;
  data->config->volume = 100;
}

void			load_config(t_data *data, char **av)
{
  t_bunny_ini		*config;

  if ((data->config = bunny_malloc(sizeof(t_config))) == NULL)
    exit(1);
  if (av[1] && (config = bunny_load_ini(av[1])) != NULL)
    {
      data->config->fullscreen =
	atoi(bunny_ini_get_field(config, "config", "fullscreen", 0));
      data->config->width = atoi(bunny_ini_get_field(config, "config", "width", 0));
      data->config->height = atoi(bunny_ini_get_field(config, "config", "height", 0));
      data->config->volume = atoi(bunny_ini_get_field(config, "config", "volume", 0));
	}
  else
    default_config(data);
}

int			main(int ac, char **av)
{
  t_data		data;

  data.menu_length = 4;
  if((data.rect = malloc(sizeof(t_mrect) * data.menu_length)) == NULL)
    return (1);
  load_config(&data, av);
  data.selected_index = 0;
  data.menu_index = 0;
  data.pos.x = 0;
  data.pos.y = 0;
  memory_check = 1;
  data.win = bunny_start(data.config->width, data.config->height,
			 data.config->fullscreen, "TEk-DOOM");
  data.pix_ar = bunny_new_pixelarray(data.config->width, data.config->height);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(esc);
  bunny_loop(data.win, 30, &data);
  bunny_delete_clipable(&data.pix_ar->clipable);
  bunny_delete_ini(data.config->ini);
  bunny_free(data.config);
  bunny_stop(data.win);
  return (0);
}
