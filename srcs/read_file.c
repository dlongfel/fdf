/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:41 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:42 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		height++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (height);
}

int			get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wordcounter(line);
	ft_strdel(&line);
	close(fd);
	return (width);
}

void		get_line_matrix(int *mat_str, char *line, t_map *map)
{
	char	**buf;
	int		i;

	i = 0;
	buf = ft_strsplit(line, ' ');
	while (buf[i])
	{
		if (isnbr(buf[i]) == -1)
			error_proc(ERR_FILE);
		mat_str[i] = ft_atoi(buf[i]);
		if (mat_str[i] > map->z_max)
			map->z_max = mat_str[i];
		if (mat_str[i] < map->z_min)
			map->z_min = mat_str[i];
		ft_strdel(&buf[i]);
		i++;
	}
	free(buf);
}

int			read_file(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->height_map = get_height(file);
	map->width_map = get_width(file);
	map->matrix = (int **)malloc(sizeof(int *) * (map->height_map) * 2);
	fd = open(file, O_RDONLY);
	while (i <= map->height_map)
		map->matrix[i++] = (int *)malloc(sizeof(int) * (map->width_map));
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_wordcounter(line) != map->width_map)
			return (-1);
		get_line_matrix(map->matrix[i++], line, map);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (0);
}
