/*
** main.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 20 18:46:14 2015 Mathieu Sauvau
** Last update Sat Jan 16 16:09:02 2016 Mathieu Sauvau
*/

#include <math.h>
#include "struct.h"

t_bunny_response	esc(t_bunny_event_state state, t_bunny_keysym keysym,
			    void *my_data)
{
  t_data		*data;

  (void)state;
  data = my_data;
  if (keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (keysym == BKS_UP && state == GO_DOWN)
    data->selected_index == 0 ?
      data->selected_index = data->menu_length - 1 : data->selected_index--;
  if (keysym == BKS_DOWN && state == GO_DOWN)
    data->selected_index == data->menu_length - 1 ?
      data->selected_index = 0 : data->selected_index++;
  if (keysym == BKS_RETURN && state == GO_DOWN)
    {
      //main_menu
      if (data->menu_index == 0)
	{
	  //	  if (data->selected_index == 0)
	    //profl name for save -> play
	  if (data->selected_index == 1)
	    {
	      data->menu_length = 5;
	      data->selected_index = 0;
	      data->menu_index = 1;
	    }
	 else if (data->selected_index == 2)
	    {
	      data->selected_index = 0;
	      data->menu_index = 2;
	    }
	 else if (data->selected_index == 3)
	    exit(0);
	}
      //option_menu
      if (data->menu_index == 1)
	{
	  if (data->selected_index == 0)
	    data->config->fullscreen = !data->config->fullscreen;
	  else if (data->selected_index == 1)
	    (CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
	  else if (data->selected_index == 4)
	    {
	      data->menu_length = 4;
	      data->menu_index = 0;
	      data->selected_index = 0;
	    }
	}
    }
  if (keysym == BKS_LEFT && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	  (CONFIG->res_i == 0) ? (CONFIG->res_i = 3) : (CONFIG->res_i--);
      if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume > 0)
	data->config->volume--;
    }
  if (keysym == BKS_RIGHT && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	    (CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
      if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume < 100)
	data->config->volume++;
    }
  return (GO_ON);
}

t_bunny_position	calc_pos_txt(t_data *data, t_mrect ref, int offset_len)
{
  t_bunny_position	pos;

  pos = ref.pos;
  pos.x -= ref.size.x / 2 - data->pos.x + offset_len / 2 * 20;
  pos.y += data->pos.y;
  return (pos);
}

void			write_main_menu(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt =  calc_pos_txt(data, data->rect[0], strlen("Play"));
  write_bmp(data, "Play", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[1], strlen("Option"));
  write_bmp(data, "Option", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[2], strlen("Credits"));
  write_bmp(data, "Credits", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect[3], strlen("Quit"));
  write_bmp(data, "Quit", pos_txt);
}

void			write_option_menu(t_data *data)
{
  t_bunny_position	pos_txt;
  char			volume[3];

  snprintf(volume, 4, "%d", data->config->volume);
  pos_txt = calc_pos_txt(data, data->rect_opt[0], strlen("Fullscreen"));
  write_bmp(data, "Fullscreen", pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[1], strlen("Resolution"));
  write_bmp(data, "Resolution", pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[1], strlen("Resolution"));
  write_bmp(data, "Resolution", pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[2], strlen(RES[CONFIG->res_i].res));
  write_bmp(data, RES[CONFIG->res_i].res, pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[3], strlen("Volume"));
  pos_txt.x -= pos_txt.x / 3;
  write_bmp(data, "Volume", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[3], 3);
  pos_txt.x += pos_txt.x / 3;
  write_bmp(data, volume, pos_txt);
}

t_bunny_response	mainloop(void	*my_data)
{
  t_data		*data;

  data = my_data;
  my_fill(data->pix_ar, BLACK);
  if (data->menu_index == 0)
    main_menu(data);
  if (data->menu_index == 1)
    option_menu(data, data->selected_index);
  bunny_blit(&data->win->buffer, &data->pix_ar->clipable, &data->pos);
  if (data->menu_index == 0)
    write_main_menu(data);
  if (data->menu_index == 1)
    write_option_menu(data);
  bunny_display(data->win);
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

t_bunny_position	pos_(int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  return(pos);
}

t_bunny_position	centered_pos(t_data *data, t_bunny_position size,
				     int offset_x, int offset_y)
{
  t_bunny_position      pos;

  pos.x = data->config->width / 2 - size.x / 2 + offset_x;
  pos.y = data->config->height / 2 + offset_y;
  return (pos);
}

t_mrect			check_box(t_data *data, bool activated, t_bunny_position label)
{
  t_mrect		rect;

  rect.size = pos_(50, 50);
  rect.pos = pos_(label.x + 10, label.y);
  rect.selected = activated;
  if (!activated)
    {
      rect.color[0] = WHITE;
      rect.color[1] = RED;
    }
  else
    {
      rect.color[0] = RED;
      rect.color[1] = WHITE;
    }
  rect.contour = 5;
  draw_square(data->pix_ar, &rect);
  return (rect);
}

t_mrect			label(t_data *data, bool selected,
			      t_bunny_position size, t_bunny_position pos)
{
  t_mrect		rect;

  rect.size = size;
  rect.pos = pos;
  rect.selected = selected;
  rect.color[0] = WHITE;
  rect.color[1] = RED;
  rect.contour = 3;
  draw_square(data->pix_ar, &rect);
  return (rect);
}

void                    draw_slider(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect, int pos_slider)
{
  int			rapport;
  int			x;
  int			y;

  x = rect->pos.x;
  y = rect->pos.y;
  rapport = x + (rect->size.x * pos_slider) / 100;
  while (rect->pos.x < rect->size.x + x)
    {
      while (rect->pos.y < rect->size.y + y)
        {
	  if (rect->pos.x <= x + rect->contour - 1
	      || rect->pos.x >= rect->size.x + x - rect->contour ||
	       rect->pos.y <= y + rect->contour - 1
	       || rect->pos.y >= rect->size.y + y - rect->contour)
	    {
	      if (rect->selected)
		tekpixel(pix_ar, rect->pos, rect->color[1]);
	      else
		tekpixel(pix_ar, rect->pos, WHITE);
	    }
	  else
	    {
	      if (rect->pos.x < rapport)
		tekpixel(pix_ar, rect->pos, rect->color[0]);
	      else
		tekpixel(pix_ar, rect->pos, WHITE);
	    }
          rect->pos.y++;
        }
      rect->pos.x++;
      rect->pos.y = y;
    }
}

t_mrect			slider(t_data *data, bool selected, int pos_slider,
			       t_bunny_position pos)
{
  t_mrect		rect;

  rect.size = pos_( data->config->width / 2, 30);
  rect.pos = pos;//centered_pos(data, rect.size, offset.x, offset.y);
  rect.selected = selected;
  rect.color[0] = BLUE;
  rect.color[1] = RED;
  rect.contour = 3;
  draw_slider(data->pix_ar, &rect, pos_slider);
  return (rect);
}

void			option_menu(t_data *data, int selected_index)
{
  t_bunny_position	pos;
  t_bunny_position	size;
  int			n;
  int			margin;
  int			offset;

  n = -1;
  margin = 20;
  offset = margin;
  /*while (++n < data->menu_length)
    {
      data->rect_opt[n].size.x = data->config->width / 2;
      data->rect_opt[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      data->rect_opt[n].pos.x = data->config->width / 2 - data->rect_opt[n].size.x / 2;
      if (n != 0)
	data->rect_opt[n].pos.y = data->rect_opt[n - 1].pos.y + data->rect_opt[n].size.y + margin;
      data->rect_opt[n].color[0] = WHITE;
      data->rect_opt[n].color[1] = RED;
      data->rect_opt[n].contour = 3;
      if (n == data->selected_index)
	data->rect_opt[n].selected = true;
      else
	data->rect_opt[n].selected = false;
      draw_square(data->pix_ar, &data->rect_opt[n]);
    }
}*/
  size = pos_(WIDTH / 2 - 60, 50);//(data->config->height - offset
  // - (margin * (data->menu_length + 1))) / data->menu_length);
  pos.x = WIDTH / 2 - size.x / 2 - 30;
  pos.y = offset;
  (selected_index == 0) ? (data->rect_opt[0] = label(data, true, size, pos)) :
    (data->rect_opt[0] = label(data, false, size, pos));
  check_box(data, data->config->fullscreen, data->rect_opt[0].pos);
  size = pos_(WIDTH / 2, 50);
  pos.x = data->config->width / 2 - data->rect_opt[0].size.x / 2 - 30;
  pos.y = data->rect_opt[0].pos.y + data->rect_opt[0].size.y + margin;

  data->rect_opt[1] = label(data, false, size, pos);
  pos.x = data->config->width / 2 - data->rect_opt[1].size.x / 2;
  pos.y = data->rect_opt[1].pos.y + data->rect_opt[1].size.y + margin;
  (selected_index == 1) ? (data->rect_opt[2] = label(data, true, size, pos)) :
    (data->rect_opt[2] = label(data, false, size, pos));


  pos.x = data->config->width / 2 - data->rect_opt[1].size.x / 2;
  pos.y = data->rect_opt[2].pos.y + data->rect_opt[1].size.y + margin;
  data->rect_opt[3] = label(data, false, size, pos);

  pos.x = data->config->width / 2 - data->rect_opt[1].size.x / 2;
  pos.y = data->rect_opt[3].pos.y + data->rect_opt[1].size.y + margin;
  if (selected_index == 2)
    data->rect_opt[4] = slider(data, true, data->config->volume, pos);
  else
  data->rect_opt[4] = slider(data, false, data->config->volume, pos);
}

t_bunny_picture		*search_letter(t_letter *letter, char c)
{
  int			i;

  i = -1;
  while(++i < 76)
    {
      if (letter[i].name == c)
	return (letter[i].letter);
    }
  return (NULL);
}

void			write_bmp(t_data *data, char *txt, t_bunny_position start)
{
  int			i;
  t_bunny_position	pos;
  t_bunny_picture	*pic;

  i = -1;
  pos = start;
  while (txt[++i])
    {
      if ((pic = search_letter(data->letter, txt[i])) != NULL)
	bunny_blit(&data->win->buffer, pic, &pos);
      pos.x += 20;
    }
}

int			find_res(t_data *data, char *res)
{
  int			i;

  i = -1;
  while (++i < 4)
    {
      //      if (strcmp(RES[i].width, res) == 0)
	return (i);
    }
  return (0);
}

void			init_res(t_data *data)
{
  strcpy(RES[0].res, "640x480");
  RES[0].width = 640;
  RES[0].height = 480;
  strcpy(RES[1].res, "800x600");
  RES[1].width = 800;
  RES[1].height = 600;
  strcpy(RES[2].res, "1280x720");
  RES[2].width = 1280;
  RES[2].height = 720;
  strcpy(RES[3].res, "1280x1024");
  RES[3].width = 1280;
  RES[3].height = 1024;
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

void			load_config(t_data *data)
{
  t_bunny_ini		*config;

  if ((data->config = bunny_malloc(sizeof(t_config))) == NULL)
    exit(1);
  if ((config = bunny_load_ini("config.ini")) != NULL)
    {
      data->config->fullscreen =
	atoi(bunny_ini_get_field(config, "config", "fullscreen", 0));
      //      CONFIG->res_i = find_res(data, bunny_ini_get_field(config, "config", "width", 0));
      data->config->width = atoi(bunny_ini_get_field(config, "config", "width", 0));
      data->config->height = atoi(bunny_ini_get_field(config, "config", "height", 0));
      data->config->volume = atoi(bunny_ini_get_field(config, "config", "volume", 0));
    }
  else
    default_config(data);
}

void			load_letter(t_data *data)
{
  int			i;
  int			len;
  char			path[11];
  char			letter[90];
  int			l_path;

  i = -1;
  strcpy(path, "text/a.bmp\0");
  strcpy(letter,
	 "  0123456789abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ()<>.,!?;:-_'\"");
  l_path = strlen(path);
  while (++i < 75)
    {
      path[l_path - 5] = letter[i];
      data->letter[i].name = letter[i];
      data->letter[i].letter = bunny_load_picture(path);
    }
}

int			main()
{
  t_data		data;

  data.menu_length = 4;
  load_letter(&data);
  if((data.rect = malloc(sizeof(t_mrect) * data.menu_length)) == NULL)
    return (1);
  load_config(&data);
  init_res(&data);
  data.config->res_i = 0;
  data.selected_index = 0;
  data.menu_index = 0;
  (data.config->fullscreen) ? (data.pos.x = data.config->width / 4) : (data.pos.x = 0);
  (data.config->fullscreen) ? (data.pos.y = data.config->height / 4) : (data.pos.y = 0);
  memory_check = 1;
  data.win = bunny_start(data.config->width, data.config->height,
			 data.config->fullscreen, "TEk-DOOM");
  data.pix_ar = bunny_new_pixelarray(data.config->width, data.config->height);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(esc);
  bunny_loop(data.win, 10, &data);
  bunny_delete_clipable(&data.pix_ar->clipable);
  bunny_delete_ini(data.config->ini);
  bunny_free(data.config);
  bunny_stop(data.win);
  return (0);
}
