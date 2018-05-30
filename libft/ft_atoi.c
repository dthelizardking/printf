/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:34:39 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:34:40 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** converts string argument (str) to an interger (type int)
*/

int		ft_atoi(char *s)
{
	int		isneg;
	int		n;

	isneg = 0;
	n = 0;
	while (ft_isspace(*s))
		s++;
	if (ft_strcmp(s, "-2147483648") == 0)
		return (-2147483648);
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		isneg = 1;
		s++;
	}
	while (*s && ft_isdigit(*s))
		n = n * 10 + (*s++ - '0');
	return (isneg ? -n : n);
}
