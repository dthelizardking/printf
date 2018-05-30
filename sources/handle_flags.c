/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:14:24 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:14:26 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*put_signorspace(char *arg, t_printf *p)
{
	char	*tmp;

	if (p->sign == 1)
	{
		tmp = ft_strjoin_free("-", arg, 2);
		return (tmp);
	}
	if (ft_strchr(p->flags, '+') && p->sign == 0)
	{
		tmp = ft_strjoin_free("+", arg, 2);
		p->len_arg = ft_strlen(tmp);
		return (tmp);
	}
	else if (ft_strchr(p->flags, ' ') && (!ft_strchr(p->flags, '+'))
	&& arg[0] != '-')
	{
		tmp = ft_strjoin_free(" ", arg, 2);
		p->len_arg = ft_strlen(tmp);
		return (tmp);
	}
	return (arg);
}

char	*put_hash(char *arg, t_printf *p)
{
	char	*tmp;

	if (ft_strcmp("0", arg) == 0 && p->type != 'p')
		return (arg);
	if ((ft_strchr("x", p->type) && *arg) || p->type == 'p')
		tmp = ft_strjoin_free("0x", arg, 2);
	else if (ft_strchr("X", p->type) && *arg)
		tmp = ft_strjoin_free("0X", arg, 2);
	else if (ft_strchr("oO", p->type))
		tmp = ft_strjoin_free("0", arg, 2);
	else
		return (arg);
	p->len_arg = ft_strlen(tmp);
	return (tmp);
}

char	*handle_width(char *arg, t_printf *p)
{
	char	*tmp;

	if (p->len_arg < p->width && p->width != 0)
	{
		tmp = ft_strnew(p->width - p->len_arg);
		if (ft_strchr(p->flags, '-'))
		{
			tmp = ft_memset(tmp, ' ', p->width - p->len_arg);
			arg = ft_memjoin(arg, tmp, p->len_arg, p->width - p->len_arg);
			p->len_arg = p->width;
			return (arg);
		}
		if (ft_strchr(p->flags, '0') &&
		(p->prec < 0 || ft_strchr("cCsS%", p->type)))
			tmp = ft_memset(tmp, '0', p->width - p->len_arg);
		else
			tmp = ft_memset(tmp, 32, p->width - p->len_arg);
		arg = ft_memjoin(tmp, arg, p->width - p->len_arg, p->len_arg);
		p->len_arg = p->width;
	}
	return (arg);
}
