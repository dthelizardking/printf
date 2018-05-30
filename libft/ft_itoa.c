/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:23:41 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:23:43 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** converts int data type to string data type
*/

static int		ft_nint(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	m;
	char			*res;

	i = ft_nint(n);
	if ((res = (char*)malloc(sizeof(char) * i + 2)) == NULL)
		return (NULL);
	if (n < 0)
		m = -1 * n;
	else
		m = n;
	res[i + 1] = '\0';
	while (i >= 0)
	{
		if (m >= 10)
			res[i] = m % 10 + '0';
		else
			res[i] = m + '0';
		m = m / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
