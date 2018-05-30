/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:52:27 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 22:52:31 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares the first n bytes of s1 and s2
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*point_string1;
	unsigned const char		*point_string2;
	size_t					i;

	i = 0;
	point_string1 = s1;
	point_string2 = s2;
	while (n--)
	{
		if (point_string1[i] != point_string2[i])
			return (point_string1[i] - point_string2[i]);
		i++;
	}
	return (0);
}
