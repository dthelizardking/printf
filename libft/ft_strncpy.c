/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:33:16 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:33:17 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies up to n chars from str pointed to by src to dest
** if len of src is < n, remainder of dest will be
** padded with null bytes
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((len > 0) && (src[i]) != '\0')
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len--)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
