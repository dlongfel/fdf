/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:58:13 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:58:14 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			error_proc(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				isnbr(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == ',' && (str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			check++;
			i++;
		}
		else if ((str[i] >= 48 && str[i] <= 57) || (i == 0 && str[i] == 45))
			i++;
		else if (i > 1 && check && ((str[i] >= 65 && str[i] <= 70)
		|| str[i] == 120))
			i++;
		else
			return (-1);
	}
	return (0);
}

int				check_file_name(char *file)
{
	while (*file && *file != '.')
		file++;
	if (*file == '\0')
		return (-1);
	else
		return (ft_strcmp(&(*file), ".fdf"));
}

int				check_file(char *file)
{
	int			fd;
	char		test_buf[10];

	if (check_file_name(file) != 0)
		return (-1);
	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	if (read(fd, test_buf, 10) <= 0)
		return (-1);
	close(fd);
	return (0);
}
