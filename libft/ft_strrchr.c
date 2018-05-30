/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:14:37 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 23:14:39 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches for the last occurrence of the char c,
** in the string pointed to by arg str
*/

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				save;
	char			*s1;

	s1 = (char*)s;
	i = 0;
	save = -1;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			save = i;
		i++;
	}
	if (save != -1)
		return (&s1[save]);
	if (c == '\0')
		return (&s1[i]);
	return (NULL);
}
