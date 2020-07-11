/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:00 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:01 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	restart(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH_WIN, HEIGHT_WIN);
	data->data_addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	draw(data);
}

void	z_size(int key, t_fdf *data)
{
	if (key == Z_MINUS)
		data->camera->z_zoom += 0.5;
	else if (key == Z_PLUS)
		data->camera->z_zoom -= 0.5;
	if (data->camera->z_zoom < 0.5)
		data->camera->z_zoom = 0.5;
	else if (data->camera->z_zoom > 5.0)
		data->camera->z_zoom = 5.0;
	restart(data);
}

void	rotation(int key, t_fdf *data)
{
	if (key == KEY_2 || key == NUM_2)
		data->camera->alpha += 0.05;
	else if (key == KEY_8 || key == NUM_8)
		data->camera->alpha -= 0.05;
	else if (key == KEY_6 || key == NUM_6)
		data->camera->beta += 0.05;
	else if (key == KEY_4 || key == NUM_4)
		data->camera->beta -= 0.05;
	else if (key == KEY_1 || key == NUM_1)
		data->camera->gamma -= 0.05;
	else if (key == KEY_3 || key == NUM_3)
		data->camera->gamma += 0.05;
	else if (key == KEY_ISO)
	{
		data->camera->alpha = -0.7;
		data->camera->beta = -0.7;
		data->camera->gamma = 0.7;
	}
	else if (key == KEY_2D)
	{
		data->camera->alpha = 0;
		data->camera->beta = 0;
		data->camera->gamma = 0;
	}
	restart(data);
}

void	zoom(int key, t_fdf *data)
{
	if (key == PLUS || key == M_SCROLL_UP || key == NUM_PLUS)
		data->camera->zoom += 3;
	else if (key == MINUS || key == M_SCROLL_DOWN || key == NUM_MINUS)
		data->camera->zoom -= 3;
	if (data->camera->zoom < data->camera->zoom_max / 2)
		data->camera->zoom = data->camera->zoom_max / 2;
	else if (data->camera->zoom > 400)
		data->camera->zoom = 400;
	restart(data);
}

void	move(int key, t_fdf *data)
{
	if (key == KEY_UP)
		data->camera->shift_y -= 10;
	if (key == KEY_DOWN)
		data->camera->shift_y += 10;
	if (key == KEY_LEFT)
		data->camera->shift_x += 10;
	if (key == KEY_RIGTH)
		data->camera->shift_x -= 10;
	restart(data);
}
