/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:22:16 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:22:17 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares s1 and s2, if identical returns 1 or 0 if not
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if ((s1 != NULL) && (s2 != NULL))
	{
		i = 0;
		while ((n > 0) && ((s1[i] != '\0') || (s2[i] != '\0')))
		{
			if (s1[i] != s2[i])
				return (0);
			n--;
			i++;
		}
	}
	return (1);
}
