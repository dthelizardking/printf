/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:22:33 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:22:35 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** uses malloc(3) to return fresh substr from arg str
** substr begins at index start and is of size len
** if start and lenn aren't refering to valid substr
** behavior remains undefined. Allocation failure
** returns NULL
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_string;
	unsigned int	i;

	if (s != NULL)
	{
		new_string = (char*)malloc(sizeof(char) * len + 1);
		if (new_string != NULL)
		{
			i = 0;
			while (i < len)
			{
				new_string[i] = s[start];
				start++;
				i++;
			}
			new_string[i] = '\0';
			return (new_string);
		}
	}
	return (0);
}
