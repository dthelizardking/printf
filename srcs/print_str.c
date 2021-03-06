#include "ft_printf.h"

void	print_str_width(t_pf_env *e)
{
	int len;

	len = ft_strlen(e->out);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
}

void	print_null_str(t_pf_env *e)
{
	int len;

	len = (e->flag.prec < 0 ? 6 : e->flag.prec);
	while (e->flag.width-- > len)
		e->ret += (e->flag.zero == 1 ?
		write(e->fd, "0", 1) : write(e->fd, " ", 1));
	e->ret += write(e->fd, "(null)", len);
	++e->i;
}

void	print_str(t_pf_env *e)
{
	char	*tmp;

	if (e->flag.prec >= 0 && e->flag.prec < (int)ft_strlen(e->out))
	{
		tmp = ft_strsub(e->out, 0, (e->flag.prec));
		free(e->out);
		e->out = tmp;
	}
	if (e->flag.minus)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_str_width(e);
	}
	else
	{
		print_str_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
