/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:25:17 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:25:18 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** outputs the integer n to the standard output
*/

void	ft_putnbr(int n)
{
	unsigned int	new;

	if (n < 0)
	{
		new = -n;
		ft_putchar('-');
	}
	else
		new = n;
	if (new >= 10)
	{
		ft_putnbr(new / 10);
		ft_putchar(new % 10 + '0');
	}
	else
		ft_putchar(new + '0');
}
