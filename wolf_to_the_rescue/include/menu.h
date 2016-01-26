/*
** struct.h for struct in /home/sauvau_m/bunnyTGraph
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 13 17:07:03 2015 Mathieu Sauvau
** Last update Tue Jan 26 11:43:12 2016 benjamin duhieu
*/

#ifndef STRUCT_H_
# define  STRUCT_H_
# define WIDTH data->config->width
# define HEIGHT data->config->height
# define VOLUME data->config->volume
# define INPUT data->config->input
# define CONFIG data->config
# define RES data->config->res
# define BGF bunny_ini_get_field

#include "lapin.h"

typedef struct		s_resolution
{
  char			res[10];
  int			height;
  int			width;
}			t_res;

/*
** key index correspond to this
** up, down, left, right, jump, reload, action, fire, zoom
*/
typedef struct		s_input
{
  bool			change_key;
  int			key_to_change;
  int			key[9];
}			t_input;

typedef	struct		s_config
{
  t_bunny_ini		*ini;
  t_input		input[1];
  bool			fullscreen;
  int			width;
  int			height;
  int			volume;
  t_res			res[4];
  int			res_i;
  int			fov;
}			t_config;

typedef struct		s_menu_rectangle
{
  t_bunny_position	pos;
  t_bunny_position	size;
  unsigned int		color[2];
  int			contour;
  bool			selected;
}			t_mrect;

typedef struct		s_letter
{
  char			name;
  t_bunny_picture	*letter;
}			t_letter;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix_ar;
  t_config		*config;
  t_bunny_music		*music;
  t_bunny_position	pos;
  t_mrect		*rect;
  t_mrect		rect_opt[10];
  t_mrect		rect_input[10];
  int			menu_length;
  int			menu_index;
  int			selected_index;
  t_letter		letter[75];
  char			sound;
  bool			exit;
}			t_data;

void			tekpixel(t_bunny_pixelarray *pix_ar,
				 t_bunny_position pos,
				 unsigned int color);
void			inc_dx(t_bunny_pixelarray *pix_ar,
			       t_bunny_position point, t_bunny_position d,
			       t_color *color);
void			inc_dy(t_bunny_pixelarray *pix_ar,
			       t_bunny_position point, t_bunny_position d,
			       t_color *color);
void			tekline(t_bunny_pixelarray *pix_ar,
				t_bunny_position *coord,
				t_color *color);
void			main_menu(t_data *data, t_mrect *, int, int);
void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color);
void			disp_sound(t_data *data);
void			option_menu(t_data *data, int selected_index);
t_mrect			label(t_data *data, bool selected,
			      t_bunny_position, t_bunny_position);
t_mrect			check_box(t_data *data, bool activated, t_bunny_position label);
void			write_bmp(t_data *data, char *, t_bunny_position);
t_bunny_position	centered_pos(t_data *data, t_bunny_position size, int, int);
t_bunny_picture		*search_letter(t_letter *letter, char c);
void                    draw_slider(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect, int pos_slider);
void			save_opt(t_data *data);
t_bunny_position	calc_pos_txt(t_data *data, t_mrect ref, int offset_len);
int			launch(t_data *data);
int			my_getnbr(char *);
void		        input_menu(t_data *data, t_mrect *rect,  int offset, int margin);
t_bunny_position	pos_(int, int);
void			save_input(t_data *data);
void		        change_key(t_data *data);
int			my_strlen(char *);
char			*my_strcpy(char *, char *);
char			*my_strcat(char *, char *);
char			*my_revstr(char *);
char			*itoa(int, char *, int);
t_bunny_response	esc(t_bunny_event_state, t_bunny_keysym, void *);
int			menu_nav(t_data *data);
void			input_nav( t_data *data);
t_bunny_position	pos_(int x, int y);
t_mrect			slider(t_data *data, bool selected, int pos_slider,
			       t_bunny_position pos);
void			write_input_menu(t_data *data);
void			write_main_menu(t_data *data);
void			write_option_menu_2(t_data *data);
void			write_option_menu(t_data *data);
void			write_change_key(t_data *data);
void			init_res(t_data *data);
void			default_config(t_data *data);
int			init_data(t_data *data);
int			get_res(t_data *data, int height);
void			option_nav(t_data *data);
void			option_nav2(t_bunny_event_state state, t_bunny_keysym keysym,
				    t_data *data);
void                    draw_square(t_bunny_pixelarray *pix_ar,
                                    t_mrect *rect);
void			load_config(t_data *data);
void			load_letter(t_data *data);
int			start(t_data *data);
void			pos_pix_ar(t_data *);

#endif /* !STRUCT_H_ */
