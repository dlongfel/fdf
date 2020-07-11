/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:04 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:05 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_control(int key, void *p)
{
	t_fdf	*data;

	data = (t_fdf *)p;
	if (key == ESC)
		exit(0);
	else if (key == KEY_DOWN || key == KEY_LEFT
	|| key == KEY_RIGTH || key == KEY_UP)
		move(key, data);
	else if (key == PLUS || key == MINUS ||
	key == NUM_PLUS || key == NUM_MINUS)
		zoom(key, data);
	else if (key == KEY_2 || key == KEY_4 || key == KEY_6 || key == KEY_8 ||
	key == KEY_1 || key == KEY_3 || key == KEY_ISO || key == KEY_2D ||
	key == NUM_1 || key == NUM_2 || key == NUM_3 || key == NUM_4 ||
	key == NUM_6 || key == NUM_8)
		rotation(key, data);
	else if (key == Z_MINUS || key == Z_PLUS)
		z_size(key, data);
	return (0);
}

void		control(t_fdf *data)
{
	mlx_hook(data->win, 2, 0, key_control, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
	mlx_hook(data->win, 5, 0, mouse_release, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
}
