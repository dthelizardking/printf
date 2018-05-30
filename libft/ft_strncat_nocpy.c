/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_nocpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:05:21 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:05:26 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat_nocpy(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		i++;
	while (j < n)
	{
		if (ft_strchr(s1, s2[j]))
			j++;
		if (j < n)
		{
			s1[i + k] = s2[j];
			j++;
			k++;
		}
	}
	s1[i + j] = '\0';
	return (s1);
}
