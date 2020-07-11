/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:51:18 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:51:24 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "key_control.h"
# include <mlx.h>
# include <math.h>

# define WIDTH_WIN		1600
# define HEIGHT_WIN		900

# define BACKGROUND		0x2e2e2e
# define TEXT_COLOR		0xebebeb
# define COLOR_1		0x9A1F6A
# define COLOR_2		0xC2294E
# define COLOR_3		0xEC4B27
# define COLOR_4		0xEF8633
# define COLOR_5		0xF3AF3D

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_FILE			"Incorrect MAP_FILE"

typedef struct			s_point
{
	float				x;
	float				y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	int					**matrix;
	int					width_map;
	int					height_map;
	int					x;
	int					y;
	int					z_max;
	int					z_min;
}						t_map;

typedef struct			s_position
{
	float				z_zoom;
	int					zoom;
	int					zoom_max;
	int					shift_x;
	int					shift_y;
	double				alpha;
	double				beta;
	double				gamma;
}						t_position;

typedef struct			s_mouse
{
	int					press;
	int					x;
	int					y;
	int					prev_x;
	int					prev_y;
}						t_mouse;

typedef struct			s_fdf
{
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_map				*map;
	t_position			*camera;
	t_mouse				*mouse;
	void				*mlx;
	void				*win;
}						t_fdf;

int						read_file(t_map *map, char *file);
void					draw(t_fdf *map);
void					control(t_fdf *map);
t_fdf					*fdf_init();
void					zoom(int key, t_fdf *data);
void					move(int key, t_fdf *data);
void					rotation(int key, t_fdf *data);
void					rot_x(float *y, int *z, double alpha);
void					rot_y(float *x, int *z, double beta);
void					rot_z(float *x, float *y, double gamma);
void					z_size(int key, t_fdf *data);
int						mouse_press(int button, int x, int y, void *param);
int						mouse_release(int button, int x, int y, void *param);
int						mouse_move(int x, int y, void *param);
void					print_menu(t_fdf *data);
t_point					point_init(float x, float y, t_fdf *data);
int						point_color(int z, t_fdf *data);
int						color(t_point point, t_point start, t_point end);
void					restart(t_fdf *data);
int						check_point(t_point p1, t_point p2);
float					mod(float a);
float					max_v(float a, float b);
float					min_v(float a, float b);
void					error_proc(char *str);
int						isnbr(char *str);
int						check_file(char *file);

#endif
