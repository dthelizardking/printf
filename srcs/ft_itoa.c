
#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	len = 1;
	n < 0 ? ++len : 0;
	nb = n < 0 ? -(long)n : n;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long)n : n;
	while (nb > 9)
	{
		s[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	s[--len] = nb + 48;
	return (s);
}
