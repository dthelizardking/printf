/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:16:11 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:16:12 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** detecs memory leaks
*/

void	*ft_memalloc(size_t size)
{
	char		*s;
	size_t		i;

	if (size > 0)
	{
		i = 0;
		s = (char*)malloc(sizeof(char) * size);
		if (s != NULL)
		{
			while (size > 0)
			{
				s[i] = 0;
				size--;
				i++;
			}
			return (s);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
