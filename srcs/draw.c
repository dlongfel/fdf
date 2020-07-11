/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:09 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:09 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(t_fdf *data, int x, int y, int color)
{
	int			*pixel;

	pixel = (int *)(data->data_addr);
	if (x > 0 && y > 0 && x < WIDTH_WIN && y < HEIGHT_WIN)
		pixel[x + (y * WIDTH_WIN)] = color;
}

void			draw_image(t_fdf *data)
{
	int			*image;
	int			i;

	ft_bzero(data->data_addr, WIDTH_WIN * HEIGHT_WIN *
	(data->bits_per_pixel / 8));
	image = (int *)(data->data_addr);
	i = 0;
	while (i < HEIGHT_WIN * WIDTH_WIN)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

void			position(float *x, float *y, int *z, t_fdf *data)
{
	*x -= data->map->width_map / 2;
	*y -= data->map->height_map / 2;
	*x *= data->camera->zoom;
	*y *= data->camera->zoom;
	*z *= data->camera->zoom / data->camera->z_zoom;
	rot_x(y, z, data->camera->alpha);
	rot_y(x, z, data->camera->beta);
	rot_z(x, y, data->camera->gamma);
	*x += WIDTH_WIN / 2;
	*y += HEIGHT_WIN / 2;
	*x += data->camera->shift_x;
	*y += data->camera->shift_y;
}

void			bresenham(t_point p1, t_point p2, t_fdf *data)
{
	float		x_step;
	float		y_step;
	t_point		start;
	int			max;
	int			check;

	position(&p1.x, &p1.y, &p1.z, data);
	position(&p2.x, &p2.y, &p2.z, data);
	start.x = p1.x;
	start.y = p1.y;
	start.z = p1.z;
	start.color = p1.color;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = max_v(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	check = check_point(p1, p2);
	while (check && ((int)(p1.x - p2.x) || (int)(p1.y - p2.y)))
	{
		put_pixel(data, p1.x, p1.y, color(p1, start, p2));
		p1.x += x_step;
		p1.y += y_step;
	}
}

void			draw(t_fdf *data)
{
	int			x;
	int			y;

	draw_image(data);
	y = 0;
	while (y < data->map->height_map)
	{
		x = 0;
		while (x < data->map->width_map)
		{
			if (x < data->map->width_map - 1)
				bresenham(point_init(x, y, data),
						point_init(x + 1, y, data), data);
			if (y < data->map->height_map - 1)
				bresenham(point_init(x, y, data),
						point_init(x, y + 1, data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	print_menu(data);
}
