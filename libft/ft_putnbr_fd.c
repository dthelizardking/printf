/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:26:42 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:26:44 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**outputs integer n to fd
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new;

	if (n < 0)
	{
		new = -n;
		ft_putchar_fd('-', fd);
	}
	else
		new = n;
	if (new >= 10)
	{
		ft_putnbr_fd(new / 10, fd);
		ft_putchar_fd(new % 10 + '0', fd);
	}
	else
		ft_putchar_fd(new + '0', fd);
}
