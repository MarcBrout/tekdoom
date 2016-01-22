/*
** main.c for fdf1 in /home/sauvau_m/rendu/gfx_fdf1
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 20 18:46:14 2015 Mathieu Sauvau
** Last update Thu Jan 21 17:42:37 2016 Mathieu Sauvau
*/

#include <math.h>
#include "struct.h"

void			menu_nav(t_data *data)
{
  //	  if (data->selected_index == 0)
  //profl name for save -> play
  if (data->selected_index == 1)
    {
      data->menu_length = 7;
      data->selected_index = 0;
      data->menu_index = 1;
    }
  else if (data->selected_index == 2)
    {
      data->selected_index = 0;
      data->menu_index = 2;
    }
  else if (data->selected_index == 3)
    data->exit = true;
}

void			input_nav(t_bunny_event_state state, t_bunny_keysym keysym,
				 t_data *data)
{
  if (data->selected_index == 9)
    {
      data->menu_length = 7;
      data->selected_index = 0;
      data->menu_index = 1;
    }
  else
    {
      INPUT->change_key = true;
      INPUT->key_to_change = data->selected_index;
    }
}

int			check_key_inuse(t_data *data, int key)
{
  int			i;

  i = -1;
  while (++i < 10)
    {
      if (INPUT->key[i] == key)
	return (i);
    }
  return (-1);
}

void			swap_key(t_data *data, int key, int in_use)
{
  int			swap;

  swap = INPUT->key[INPUT->key_to_change];
  INPUT->key[INPUT->key_to_change] = key;
  INPUT->key[in_use] = swap;
}

void		        change_key(t_bunny_keysym keysym, t_data *data)
{
  t_bunny_position	pos_txt;
  const  bool		*k;
  int			i;
  int			in_use;

  if (data->selected_index != 9 && INPUT->change_key)
    {
      i = -1;
      k = bunny_get_keyboard();
      while (++i < 102)
	{
	  if (i != BKS_RETURN && k[i] == 1)
	    {
	      if ((in_use = check_key_inuse(data, i)) == -1)
		INPUT->key[INPUT->key_to_change] = i;
	      else
		swap_key(data, i, in_use);
	      save_input(data);
	      INPUT->change_key = false;
	      data->selected_index++;
	    }
	}
    }
}

void			option_nav(t_bunny_event_state state, t_bunny_keysym keysym,
				 t_data *data)
{
  if (data->selected_index == 0)
    data->config->fullscreen = !data->config->fullscreen;
  else if (data->selected_index == 1)
    (CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
  else if (data->selected_index == 4)
    {
      data->menu_length = 10;
      data->menu_index = 3;
      data->selected_index = 0;
    }
  else if (data->selected_index == 5)
    save_opt(data);
  else if (data->selected_index == 6)
    {
      data->menu_length = 4;
      data->menu_index = 0;
      data->selected_index = 0;
    }
}

void			option_nav2(t_bunny_event_state state, t_bunny_keysym keysym,
				 t_data *data)
{
  if ((keysym == BKS_LEFT || keysym == INPUT->key[2]) && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	(CONFIG->res_i == 0) ? (CONFIG->res_i = 3) : (CONFIG->res_i--);
      else if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume > 0)
	data->config->volume--;
      else if (data->menu_index == 1 && data->selected_index == 3
	  && data->config->fov > 50)
	data->config->fov--;
    }
  else if ((keysym == BKS_RIGHT || keysym == INPUT->key[3]) && state == GO_DOWN)
    {
      if (data->menu_index == 1 && data->selected_index == 1)
	(CONFIG->res_i == 3) ? (CONFIG->res_i = 0) : (CONFIG->res_i++);
      else if (data->menu_index == 1 && data->selected_index == 2
	  && data->config->volume < 100)
	data->config->volume++;
      else if (data->menu_index == 1 && data->selected_index == 3
	  && data->config->fov < 100)
	data->config->fov++;
    }
}

t_bunny_response	esc(t_bunny_event_state state, t_bunny_keysym keysym,
			    void *my_data)
{
  t_data		*data;

  (void)state;
  data = my_data;
  if (keysym == BKS_ESCAPE || data->exit)
    return (EXIT_ON_SUCCESS);
  if ((keysym == BKS_UP || keysym == INPUT->key[0]) && state == GO_DOWN
      && !INPUT->change_key)
    data->selected_index == 0 ?
      data->selected_index = data->menu_length - 1 : data->selected_index--;
  if ((keysym == BKS_DOWN || keysym == INPUT->key[1]) && state == GO_DOWN
      && !INPUT->change_key)
    data->selected_index == data->menu_length - 1 ?
      data->selected_index = 0 : data->selected_index++;
  if (keysym == BKS_RETURN && state == GO_DOWN)
    {
      //main_menu
      if (data->menu_index == 0)
	menu_nav(data);
      //option_menu
      else if (data->menu_index == 1)
	option_nav(state, keysym, data);
      else if (data->menu_index == 3)
	input_nav(state, keysym, data);
    }
  option_nav2(state, keysym, data);
  if (data->menu_index == 3)
    change_key(keysym, data);
  return (GO_ON);
}

void			save_input(t_data *data)
{
  char			convert_int[12];

  if (CONFIG->ini)
    {
      snprintf(convert_int, 4, "%d", INPUT->key[0]);
      bunny_ini_set_field(CONFIG->ini, "input", "up", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[1]);
      bunny_ini_set_field(CONFIG->ini, "input", "down", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[2]);
      bunny_ini_set_field(CONFIG->ini, "input", "left", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[3]);
      bunny_ini_set_field(CONFIG->ini, "input", "right", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[4]);
      bunny_ini_set_field(CONFIG->ini, "input", "jump", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[5]);
      bunny_ini_set_field(CONFIG->ini, "input", "reload", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[6]);
      bunny_ini_set_field(CONFIG->ini, "input", "action", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[7]);
      bunny_ini_set_field(CONFIG->ini, "input", "fire", 0, convert_int);
      snprintf(convert_int, 4, "%d", (int)INPUT->key[8]);
      bunny_ini_set_field(CONFIG->ini, "input", "zoom", 0, convert_int);
      bunny_save_ini(CONFIG->ini, "config.ini");
    }
}

void			save_opt(t_data *data)
{
  char			convert_int[12];

  if (CONFIG->ini)
    {
      snprintf(convert_int, 2, "%d", (int)CONFIG->fullscreen);
      bunny_ini_set_field(CONFIG->ini, "config", "fullscreen", 0, convert_int);
      snprintf(convert_int, 4, "%d", CONFIG->volume);
      bunny_ini_set_field(CONFIG->ini, "config", "volume", 0, convert_int);
      snprintf(convert_int, 5, "%d", RES[CONFIG->res_i].width);
      bunny_ini_set_field(CONFIG->ini, "config", "width", 0, convert_int);
      snprintf(convert_int, 5, "%d", RES[CONFIG->res_i].height);
      bunny_ini_set_field(CONFIG->ini, "config", "height", 0, convert_int);
      snprintf(convert_int, 4, "%d", CONFIG->fov);
      bunny_ini_set_field(CONFIG->ini, "config", "fov", 0, convert_int);
      bunny_save_ini(CONFIG->ini, "config.ini");
      /*      bunny_delete_clipable(&data->pix_ar->clipable);
      bunny_delete_ini(data->config->ini);
      bunny_free(data->config);
      bunny_stop(data->win);*/
      //
      //      data->exit = true;
      //main();

//      launch(data);
    }
}

t_bunny_position	calc_pos_txt(t_data *data, t_mrect ref, int offset_len)
{
  t_bunny_position	pos;

  pos = ref.pos;
  pos.x -= ref.size.x / 2 - data->pos.x + offset_len / 2 * 20;
  pos.y += data->pos.y;
  return (pos);
}

void			write_change_key(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt.x = WIDTH / 2 - 110;
  pos_txt.y = HEIGHT / 2 - 20;
  write_bmp(data, "Press a key", pos_txt);
}

void			write_input_menu(t_data *data)
{
  t_bunny_position	pos_txt;

  pos_txt =  calc_pos_txt(data, data->rect_input[0], strlen("Up"));
  write_bmp(data, "Up", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[1], strlen("Down"));
  write_bmp(data, "Down", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[2], strlen("Left"));
  write_bmp(data, "Left", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[3], strlen("Right"));
  write_bmp(data, "Right", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[4], strlen("Action"));
  write_bmp(data, "Action", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[5], strlen("Jump"));
  write_bmp(data, "Jump", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[6], strlen("Reload"));
  write_bmp(data, "Reload", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[7], strlen("Shoot"));
  write_bmp(data, "Shoot", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[8], strlen("Zoom"));
  write_bmp(data, "Zoom", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_input[9], strlen("Back"));
  write_bmp(data, "Back", pos_txt);
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
  char			convert_int[3];

  snprintf(convert_int, 4, "%d", data->config->volume);
  pos_txt = calc_pos_txt(data, data->rect_opt[0], strlen("Fullscreen"));
  write_bmp(data, "Fullscreen", pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[1], strlen("Resolution"));
  write_bmp(data, "Resolution", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[2], strlen(RES[CONFIG->res_i].res));
  write_bmp(data, RES[CONFIG->res_i].res, pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[3], strlen("Volume"));
  pos_txt.x -= 60;
  write_bmp(data, "Volume", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[3], 3);
  pos_txt.x += 60;
  write_bmp(data, convert_int, pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[5], strlen("FOV"));
  pos_txt.x -= 60;
  write_bmp(data, "FOV", pos_txt);
  snprintf(convert_int, 4, "%d", data->config->fov);
  pos_txt = calc_pos_txt(data, data->rect_opt[5], 3);
  pos_txt.x += 60;
  write_bmp(data, convert_int, pos_txt);

  pos_txt = calc_pos_txt(data, data->rect_opt[7], strlen("Input Config"));
  write_bmp(data, "Input Config", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[8], strlen("Save"));
  write_bmp(data, "Save", pos_txt);
  pos_txt = calc_pos_txt(data, data->rect_opt[9], strlen("Back"));
  write_bmp(data, "Back", pos_txt);
}

t_bunny_response	mainloop(void	*my_data)
{
  t_data		*data;

  data = my_data;
  my_fill(data->pix_ar, PINK);
  if (data->menu_index == 0)
    main_menu(data, data->rect, HEIGHT / 2, 20);
  else if (data->menu_index == 1)
    option_menu(data, data->selected_index);
  else if (data->menu_index == 3 && !INPUT->change_key)
    input_menu(data, data->rect_input, 0, 20);
  if (INPUT->change_key)
    label(data, false, pos_(400, 200), pos_(WIDTH / 2 - 200, HEIGHT / 2 - 100));
  bunny_blit(&data->win->buffer, &data->pix_ar->clipable, &data->pos);
  if (data->menu_index == 0)
    write_main_menu(data);
  else if (data->menu_index == 1)
    write_option_menu(data);
  else if (data->menu_index == 3 && !INPUT->change_key)
    write_input_menu(data);
  if (INPUT->change_key)
    write_change_key(data);
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

  rect.size = pos_(data->config->width / 2, 30);
  rect.pos = pos;
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
  int			margin;
  int			offset;

  margin = 20;
  offset = margin;
  size = pos_(WIDTH / 2 - 60, 50);
  size.y = (data->config->height - offset - (margin * 10)) / 10;
  pos.x = WIDTH / 2 - size.x / 2 - 30;
  pos.y = offset;
  (selected_index == 0) ? (data->rect_opt[0] = label(data, true, size, pos)) :
    (data->rect_opt[0] = label(data, false, size, pos));
  check_box(data, data->config->fullscreen, data->rect_opt[0].pos);
  size = pos_(WIDTH / 2, 50);
  size.y = (data->config->height - offset - (margin * 10)) / 10;
  pos.x = data->config->width / 2 - data->rect_opt[0].size.x / 2 - 30;
  pos.y = data->rect_opt[0].pos.y + data->rect_opt[0].size.y + margin;

  data->rect_opt[1] = label(data, false, size, pos);
  pos.x = data->config->width / 2 - data->rect_opt[1].size.x / 2;
  pos.y = data->rect_opt[1].pos.y + data->rect_opt[1].size.y + margin;
  (selected_index == 1) ? (data->rect_opt[2] = label(data, true, size, pos)) :
    (data->rect_opt[2] = label(data, false, size, pos));

  pos.y = data->rect_opt[2].pos.y + data->rect_opt[1].size.y + margin;
  data->rect_opt[3] = label(data, false, size, pos);

  pos.y = data->rect_opt[3].pos.y + data->rect_opt[1].size.y + 15;
  if (selected_index == 2)
    data->rect_opt[4] = slider(data, true, data->config->volume, pos);
  else
    data->rect_opt[4] = slider(data, false, data->config->volume, pos);

  pos.y = data->rect_opt[4].pos.y + data->rect_opt[1].size.y + margin;
  data->rect_opt[5] = label(data, false, size, pos);

  pos.y = data->rect_opt[5].pos.y + data->rect_opt[1].size.y + margin;
  if (selected_index == 3)
    data->rect_opt[6] = slider(data, true, data->config->fov, pos);
  else
    data->rect_opt[6] = slider(data, false, data->config->fov, pos);

  pos.y = data->rect_opt[6].pos.y + data->rect_opt[1].size.y + margin ;
  (selected_index == 4) ? (data->rect_opt[7] = label(data, true, size, pos)) :
    (data->rect_opt[7] = label(data, false, size, pos));

  pos.y = data->rect_opt[7].pos.y + data->rect_opt[1].size.y + margin;
  (selected_index == 5) ? (data->rect_opt[8] = label(data, true, size, pos)) :
    (data->rect_opt[8] = label(data, false, size, pos));

  pos.y = data->rect_opt[8].pos.y + data->rect_opt[1].size.y + margin;
  (selected_index == 6) ? (data->rect_opt[9] = label(data, true, size, pos)) :
  (data->rect_opt[9] = label(data, false, size, pos));
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

int			get_res(t_data *data, int height)
{
  int			i;

  i = -1;
  while (++i < 4)
    {
      if (height == RES[i].height)
	{
	  WIDTH = RES[i].width;
	  HEIGHT = RES[i].height;
	  return (i);
	}
    }
  WIDTH = RES[1].width;
  HEIGHT = RES[1].height;
  return (1);
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

void			input_menu_next(t_data *data, t_mrect *ref)
{
  t_mrect		box;

  box.size = pos_(60, ref->size.y);
  box.pos = pos_(ref->pos.x + 20, ref->pos.y);
  box.color[0] = WHITE;
  box.color[1] = WHITE;
  draw_square(data->pix_ar, &box);
}

void			input_menu(t_data *data, t_mrect *rect,  int offset, int margin)
{
  int			n;

  n = -1;
  rect[0].pos.y = margin;
  while (++n < data->menu_length)
    {
      rect[n].size.x = 200;
      rect[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      rect[n].pos.x = data->config->width / 2 - rect[n].size.x / 2;
      if (n != 0)
	rect[n].pos.y = rect[n - 1].pos.y + rect[n].size.y + margin;
      rect[n].color[0] = WHITE;
      rect[n].color[1] = RED;
      rect[n].contour = 3;
      if (n == data->selected_index)
	rect[n].selected = true;
      else
	rect[n].selected = false;
      draw_square(data->pix_ar, &rect[n]);
      input_menu_next(data, &rect[n]);
    }
}

void			main_menu(t_data *data, t_mrect *rect,  int offset, int margin)
{
  int			n;

  n = -1;
  rect[0].pos.y = offset;
  while (++n < data->menu_length)
    {
      rect[n].size.x = data->config->width / 2;
      rect[n].size.y = (data->config->height - offset
			      - (margin * (data->menu_length + 1))) / data->menu_length;
      rect[n].pos.x = data->config->width / 2 - rect[n].size.x / 2;
      if (n != 0)
	rect[n].pos.y = rect[n - 1].pos.y + rect[n].size.y + margin;
      rect[n].color[0] = WHITE;
      rect[n].color[1] = RED;
      rect[n].contour = 3;
      if (n == data->selected_index)
	rect[n].selected = true;
      else
	rect[n].selected = false;
      draw_square(data->pix_ar, &rect[n]);
    }
}

void			default_config(t_data *data)
{
  data->config->fullscreen = false;
  data->config->width = 800;
  data->config->height = 600;
  data->config->volume = 100;
  data->config->volume = 60;
  INPUT->key[0] = 25;
  INPUT->key[1] = 18;
  INPUT->key[2] = 16;
  INPUT->key[3] = 3;
  INPUT->key[4] = 57;
  INPUT->key[5] = 17;
  INPUT->key[6] = 4;
  //  INPUT->key[7] =
  //  INPUT->key[8] =
}

void			load_input(t_data *data)
{
  INPUT->key[0] = my_getnbr((char *)BGF(CONFIG->ini, "input", "up", 0));
  INPUT->key[1] = my_getnbr((char *)BGF(CONFIG->ini, "input", "down", 0));
  INPUT->key[2] = my_getnbr((char *)BGF(CONFIG->ini, "input", "left", 0));
  INPUT->key[3] = my_getnbr((char *)BGF(CONFIG->ini, "input", "right", 0));
  INPUT->key[4] = my_getnbr((char *)BGF(CONFIG->ini, "input", "jump", 0));
  INPUT->key[5] = my_getnbr((char *)BGF(CONFIG->ini, "input", "reload", 0));
  INPUT->key[6] = my_getnbr((char *)BGF(CONFIG->ini, "input", "action", 0));
  //INPUT->key[7] = my_getnbr((char *)BGF(CONFIG->ini, "input", "fire", 0));
  // INPUT->key[8] = my_getnbr((char *)BGF(CONFIG->ini, "input", "zoom", 0));

}

void			load_config(t_data *data)
{
  if ((CONFIG = bunny_malloc(sizeof(t_config))) == NULL)
    exit(1);
  if ((CONFIG->ini = bunny_load_ini("config.ini")) != NULL)
    {
      data->config->fullscreen =
	my_getnbr((char *)BGF(CONFIG->ini, "config", "fullscreen", 0));
      data->config->width = my_getnbr((char *)BGF(CONFIG->ini, "config", "width", 0));
      data->config->height = my_getnbr((char *)BGF(CONFIG->ini, "config", "height", 0));
      data->config->volume = my_getnbr((char *)BGF(CONFIG->ini, "config", "volume", 0));
      data->config->fov = my_getnbr((char *)BGF(CONFIG->ini, "config", "fov", 0));
      load_input(data);
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
  double		scale;

  i = -1;
  scale = 0.5;
  scale += 0.25 * CONFIG->res_i;
  strcpy(path, "text/a.bmp\0");
  strcpy(letter,
	 "  0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUWVXYZ()<>.,!?;:-_'\"");
  l_path = strlen(path);
  while (++i < 75)
    {
      path[l_path - 5] = letter[i];
      data->letter[i].name = letter[i];
      data->letter[i].letter = bunny_load_picture(path);
      data->letter[i].letter->scale.x *= scale;
      data->letter[i].letter->scale.y *= scale;
    }
}

int			init_data(t_data *data)
{
  data->menu_length = 4;
  if((data->rect = malloc(sizeof(t_mrect) * data->menu_length)) == NULL)
    return (1);
  load_config(data);
  init_res(data);
  CONFIG->res_i = get_res(data, CONFIG->height);
  load_letter(data);
  data->selected_index = 0;
  data->menu_index = 0;
  data->exit = false;
  if (CONFIG->fullscreen && CONFIG->height == 720)
    {
      data->pos.x = WIDTH / 4;
      data->pos.y = HEIGHT / 4;
    }
  else
    {
      data->pos.x = 0;
      data->pos.y = 0;
    }
  return (0);
}

int			launch(t_data *data)
{
  if (init_data(data) == 1)
    return (-1);
  memory_check = 1;
  data->win = bunny_start(WIDTH, HEIGHT,
			 CONFIG->fullscreen, "TEk-DOOM");
  data->pix_ar = bunny_new_pixelarray(WIDTH, HEIGHT);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(esc);
  bunny_loop(data->win, 10, data);
  return (0);
}

int			main()
{
  t_data		data;

  if (launch(&data) == 1)
    return (1);
  bunny_delete_clipable(&data.pix_ar->clipable);
  bunny_delete_ini(data.config->ini);
  bunny_free(data.config);
  bunny_stop(data.win);
  return (0);
}
