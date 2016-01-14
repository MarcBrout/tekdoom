/*
** struct.h for struct in /home/sauvau_m/bunnyTGraph
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 13 17:07:03 2015 Mathieu Sauvau
** Last update Thu Jan 14 20:18:36 2016 Mathieu Sauvau
*/

#ifndef STRUCT_H_
# define  STRUCT_H_

# include <lapin.h>
# include <unistd.h>
# include <string.h>

# define WIDTH (800)
# define HEIGHT (600)

typedef	struct		s_config
{
  t_bunny_ini		*ini;
  bool			fullscreen;
  int			width;
  int			height;
  int			volume;
}			t_config;

typedef struct		s_menu_rectangle
{
  t_bunny_position	pos;
  t_bunny_position	size;
  unsigned int		color[2];
  int			contour;
  bool			selected;
}			t_mrect;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix_ar;
  t_config		*config;
  t_bunny_position	pos;
  t_mrect		*rect;
  int			menu_length;
  int			menu_index;
  int			selected_index;
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
void			main_menu(t_data *data);
void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color);
void			option_menu(t_data *data,
				    int nb, int selected_index);
void			check_box(t_data *data, bool selected, bool activated);
void			write_bmp(t_data *data, char *, t_bunny_position);

#endif /* !STRUCT_H_ */
