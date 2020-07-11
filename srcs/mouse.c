/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:33 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:33 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					mouse_press(int button, int x, int y, void *p)
{
	t_fdf			*data;

	(void)x;
	(void)y;
	data = (t_fdf *)p;
	if (button == M_SCROLL_UP || button == M_SCROLL_DOWN)
		zoom(button, data);
	else if (button == M_LEFT)
		data->mouse->press = 1;
	return (0);
}

int					mouse_release(int button, int x, int y, void *p)
{
	t_fdf			*data;

	(void)x;
	(void)y;
	(void)button;
	data = (t_fdf *)p;
	data->mouse->press = 0;
	return (0);
}

int					mouse_move(int x, int y, void *p)
{
	t_fdf			*data;

	data = (t_fdf *)p;
	data->mouse->prev_x = data->mouse->x;
	data->mouse->prev_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->press)
	{
		data->camera->beta += (x - data->mouse->prev_x) * 0.002;
		data->camera->alpha += (y - data->mouse->prev_y) * 0.002;
		restart(data);
	}
	return (0);
}
