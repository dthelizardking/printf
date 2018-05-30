/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:13:53 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:13:54 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long long			get_signed_arg(va_list *args, t_printf *p)
{
	long long			i;

	i = 0;
	if (*p->size == 'N' && p->type != 'D')
		return (((long long)va_arg(*args, int)));
	else if (*p->size == 'l' || p->type == 'D')
		return (((long long)va_arg(*args, long)));
	else if (*p->size == 'h' && p->size[1] == 'h')
		return ((long long)((signed char)va_arg(*args, int)));
	else if (*p->size == 'h')
		return ((long long)((short int)va_arg(*args, int)));
	else if (*p->size == 'l' && p->size[1] == 'l')
		return (((long long)va_arg(*args, long long)));
	else if (*p->size == 'j')
		return (((long long)va_arg(*args, intmax_t)));
	else if (*p->size == 'z')
		return (((long long)va_arg(*args, size_t)));
	else
		return (i);
}

unsigned long long	get_unsigned_arg(va_list *args, t_printf *p)
{
	unsigned long long	i;

	i = 0;
	if (*p->size == 'N' && p->type != 'U' && p->type != 'O' && p->type != 'p')
		return (((unsigned long long)va_arg(*args, unsigned int)));
	else if (*p->size == 'N' && p->type == 'p')
		return (((unsigned long long)va_arg(*args, void *)));
	else if (*p->size == 'l' || p->type == 'U' || p->type == 'O')
		return (((unsigned long long)va_arg(*args, unsigned long)));
	else if (*p->size == 'h' && p->size[1] == 'h')
		return ((unsigned long long)((unsigned char)va_arg(*args, int)));
	else if (*p->size == 'l' && *(p->size + 1) == 'l')
		return (((unsigned long long)va_arg(*args, unsigned long long)));
	else if (*p->size == 'h')
		return ((unsigned long long)((unsigned short)va_arg(*args, int)));
	else if (*p->size == 'j')
		return (((unsigned long long)va_arg(*args, uintmax_t)));
	else if (*p->size == 'z')
		return (((unsigned long long)va_arg(*args, size_t)));
	else
		return (i);
}
