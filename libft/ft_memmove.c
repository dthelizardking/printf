/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:51:38 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 22:51:40 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies n bytes from src to dest. To prevent overlap the bytes in
** src are copied into a temp arry that does not overlap src or dest.
** the bytes are then copied from the temp arry to the dest.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*point_dst;
	unsigned char		*point_src;

	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	if (point_dst == point_src)
		return (dst);
	if (point_dst > point_src)
	{
		point_dst = point_dst + len - 1;
		point_src = point_src + len - 1;
		while (len-- > 0)
			*(point_dst--) = *(point_src--);
		return (dst);
	}
	while (len-- > 0)
		*(point_dst++) = *(point_src++);
	return (dst);
}
