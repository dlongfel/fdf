/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richardbrackswaide <richardbrackswaide@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:52:26 by richardbrac       #+#    #+#             */
/*   Updated: 2020/07/03 13:52:28 by richardbrac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ch;
	size_t	i;

	i = 0;
	ch = (char *)s;
	while (i < n)
	{
		ch[i] = '\0';
		i++;
	}
}
