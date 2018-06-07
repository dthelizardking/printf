#include "ft_printf.h"

void	ft_strlower(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
}
