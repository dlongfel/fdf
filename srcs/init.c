/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:17 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:18 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				point_init(float x, float y, t_fdf *data)
{
	t_point			p;

	p.x = x;
	p.y = y;
	p.z = data->map->matrix[(int)y][(int)x];
	p.color = point_color(p.z, data);
	return (p);
}

t_position			*camera_init(void)
{
	t_position		*camera;

	camera = (t_position *)malloc(sizeof(t_position));
	camera->shift_x = 0;
	camera->shift_y = 0;
	camera->zoom = 0;
	camera->zoom_max = 0;
	camera->alpha = -0.7;
	camera->beta = -0.7;
	camera->gamma = 0.7;
	camera->z_zoom = 2;
	return (camera);
}

t_map				*map_init(void)
{
	t_map			*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->height_map = 0;
	map->width_map = 0;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

t_mouse				*mouse_init(void)
{
	t_mouse			*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	mouse->press = 0;
	mouse->x = 0;
	mouse->y = 0;
	mouse->prev_x = 0;
	mouse->prev_y = 0;
	return (mouse);
}

t_fdf				*fdf_init(void)
{
	t_fdf			*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH_WIN, HEIGHT_WIN, "FDF");
	data->img = mlx_new_image(data->mlx, WIDTH_WIN, HEIGHT_WIN);
	data->data_addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	data->map = map_init();
	data->camera = camera_init();
	data->mouse = mouse_init();
	return (data);
}
