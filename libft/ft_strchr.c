/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:14:15 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 23:14:17 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches for the first occurence of character c in the
** string pointed to by the argument
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char*)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	if (p[i] == (char)c)
		return (&p[i]);
	return (0);
}
