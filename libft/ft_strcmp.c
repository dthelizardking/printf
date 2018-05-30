/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:32:30 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:32:32 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares s1 to s2
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (p1[i] == p2[i] && p2[i] != '\0')
		i++;
	if ((p1[i] == '\0') && (p2[i] == '\0'))
		return (0);
	return (p1[i] - p2[i]);
}
