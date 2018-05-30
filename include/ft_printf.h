/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:58:19 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 20:58:21 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_printf
{
	char			*flags;
	int				width;
	char			*size;
	int				prec;
	char			type;
	int				len_str;
	int				len_arg;
	int				sign;
	char			*f;
}					t_printf;

typedef struct		s_func
{
	char			*(*ptrfunc) (va_list *agrs, t_printf *my_struc);
	char			key;
}					t_func;

int					ft_printf(const char *format, ...);

char				*ft_parse_flags(t_printf *arg);

char				*mng_c(va_list *args, t_printf *type);
char				*mng_lc(va_list *args, t_printf *type);
char				*mng_s(va_list *args, t_printf *type);
char				*mng_ls(va_list *args, t_printf *type);
char				*mng_sb10(va_list *args, t_printf *type);
char				*mng_ub10(va_list *args, t_printf *type);
char				*mng_ub16_min(va_list *args, t_printf *type);
char				*mng_ub16_maj(va_list *args, t_printf *type);
char				*mng_ub8(va_list *args, t_printf *type);
char				*mng_percent(va_list *args, t_printf *type);

long long			get_signed_arg(va_list *args, t_printf *flag);
unsigned long long	get_unsigned_arg(va_list *arg, t_printf *flag);

t_printf			*initialize_struct(t_printf	*my_struc);
void				free_struc(t_printf	*my_struc);

char				*handle_precision(char *arg, t_printf *my_struc);
char				*handle_width(char *arg, t_printf *my_struc);
char				*put_signorspace(char *arg, t_printf *my_struc);
char				*put_hash(char *arg, t_printf *my_struc);

#endif
