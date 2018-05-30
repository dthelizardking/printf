/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:21:17 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:21:19 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Applies the function f to each character of the string
** to create a fresh string with malloc(3)
** resulting from repeated applications of f
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_string;
	int		lengh;
	int		i;

	if (s != NULL)
	{
		lengh = ft_strlen(s);
		new_string = (char*)malloc(sizeof(char) * lengh + 1);
		if (new_string != NULL)
		{
			i = 0;
			while (i < lengh)
			{
				new_string[i] = (*f)(s[i]);
				i++;
			}
			new_string[i] = '\0';
			return (new_string);
		}
	}
	return (0);
}
