/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:14:45 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:14:47 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*get_precision(char *arg, t_printf *p)
{
	char *tmp;

	if (p->prec >= 0 && p->type != '\0' && *arg != '\0')
	{
		if (p->prec == 0 && ft_strcmp("0", arg) == 0)
		{
			arg[0] = 0;
			p->len_arg = 0;
			return (arg);
		}
		else if (p->len_arg > p->prec && (ft_strchr("sS", p->type)))
			arg = ft_strsub(arg, 0, p->prec);
		else if (p->len_arg - p->sign < p->prec &&
		(!(ft_strchr("cCsS%", p->type))))
		{
			if (p->type == 'o' && ft_strchr(p->flags, '#') && p->prec > 0)
				p->prec--;
			tmp = ft_strnew(p->prec - p->len_arg + p->sign);
			ft_memset(tmp, '0', (p->prec - p->len_arg + p->sign));
			arg = ft_strjoin_free(tmp, arg, 3);
		}
		p->len_arg = ft_strlen(arg) + p->sign;
	}
	return (arg);
}

static char	*get_len(char *arg, t_printf *p)
{
	char	*tmp;

	if (p->len_arg == 0)
		p->len_arg = ft_strlen(arg);
	if (p->sign == 1)
	{
		tmp = ft_strsub(arg, 1, p->len_arg);
		ft_strdel(&arg);
		arg = tmp;
	}
	return (arg);
}

char		*handle_flags(char *arg, t_printf *p)
{
	if (ft_strchr("idD", p->type) && p->type != '\0')
	{
		if (p->prec < 0 && ft_strchr(p->flags, '0') &&
		(!ft_strchr(p->flags, '-')))
		{
			if ((ft_strchr(p->flags, '+') || ft_strchr(p->flags, ' '))
			&& p->sign == 0)
				p->width -= 1;
			arg = handle_width(arg, p);
		}
		arg = put_signorspace(arg, p);
	}
	else if ((ft_strchr("oOxX", p->type) &&
		ft_strchr(p->flags, '#')) || p->type == 'p')
	{
		if (p->prec < 0 && ft_strchr("xXp", p->type)
		&& ft_strchr(p->flags, '0'))
		{
			(p->width > 1) ? p->width -= 2 : p->width;
			arg = handle_width(arg, p);
		}
		arg = put_hash(arg, p);
	}
	return (arg);
}

char		*handle_precision(char *arg, t_printf *p)
{
	arg = get_len(arg, p);
	arg = get_precision(arg, p);
	arg = handle_flags(arg, p);
	arg = handle_width(arg, p);
	return (arg);
}
