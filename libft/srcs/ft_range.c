/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:54:49 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:54:50 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_range(int min, int max)
{
	int		*x;
	int		i;
	int		a;

	if (max > min)
	{
		i = 0;
		a = min;
		x = malloc(sizeof(int) * (max - min));
		while (a < max)
		{
			x[i] = a;
			a++;
			i++;
		}
		return (x);
	}
	else
		return (NULL);
}
