/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:52:20 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:52:22 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	unsigned long long	r;
	int					x;

	i = 0;
	x = 1;
	r = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
	str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		x = (str[i++] == '-') ? -1 : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = (unsigned long long)(r * 10) + (str[i++] - '0');
		if (r > (long long)LLMAX && x == 1)
			return (-1);
		if (r > (long long)LLMAX && x == -1)
			return (0);
	}
	return (r * x);
}
