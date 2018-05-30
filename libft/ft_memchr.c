/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:52:00 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 22:52:02 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** looks for first occurrence of character c in the first n
** bytes of the targeted string
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*point;
	size_t			i;

	i = 0;
	point = (unsigned char*)s;
	while (n--)
	{
		if (point[i] == (unsigned char)c)
			return (&point[i]);
		i++;
	}
	return (NULL);
}
