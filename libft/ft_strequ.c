/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:22:05 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:22:06 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares s1 and s2; if identical returns 1, if not 0
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if ((s1 != NULL) && (s2 != NULL))
	{
		i = 0;
		while ((s1[i] != '\0') || (s2[i] != '\0'))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
