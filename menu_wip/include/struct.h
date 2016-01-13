/*
** struct.h for struct in /home/sauvau_m/bunnyTGraph
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Nov 13 17:07:03 2015 Mathieu Sauvau
** Last update Wed Jan 13 14:52:03 2016 Mathieu Sauvau
*/

#ifndef STRUCT_H_
# define  STRUCT_H_

# include <lapin.h>

# define WIDTH (800)
# define HEIGHT (600)

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
void			create_menu(t_bunny_pixelarray *pix_ar,
				    int nb, int selected_index);

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix_ar;
  t_bunny_position	pos;
  int			menu_length;
  int			menu_index;
  int			selected_index;
}			t_data;

typedef struct		s_menu_rectangle
{
  t_bunny_position	pos;
  t_bunny_position	size;
  unsigned int		color[2];
  int			contour;
  bool			selected;
}			t_mrect;

#endif /* !STRUCT_H_ */
