/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:57:55 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:57:56 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			percent(int a, int b, int z)
{
	double		p;
	double		dist;

	p = z - a;
	dist = b - a;
	return ((dist == 0) ? 1.0 : (p / dist));
}

int				point_color(int z, t_fdf *data)
{
	double		perc;

	perc = percent(data->map->z_min, data->map->z_max, z);
	if (perc < 0.2)
		return (COLOR_1);
	else if (perc < 0.4)
		return (COLOR_2);
	else if (perc < 0.6)
		return (COLOR_3);
	else if (perc < 0.8)
		return (COLOR_3);
	else
		return (COLOR_4);
}

int				get_light(int start, int end, double perc)
{
	return ((1 - perc) * start + perc * end);
}

int				color(t_point point, t_point start, t_point end)
{
	int			r;
	int			g;
	int			b;
	double		perc;

	if (point.color == end.color)
		return (point.color);
	if (mod(start.x - end.x) > mod(start.y - end.y))
		perc = percent(start.x, end.x, point.x);
	else
		perc = percent(start.y, end.y, point.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	b = get_light(start.color & 0xFF, end.color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}
