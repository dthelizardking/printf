#include "ft_printf.h"

char	*ft_itoa_base(int n, int base)
{
	char	*s;
	long	nb;
	int		len;

	len = 1;
	nb = n < 0 ? -(long)n : n;
	nb < 0 ? ++len : 0;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long)n : n;
	while (nb >= base)
	{
		s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
		nb /= base;
	}
	s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
	return (s);
}
