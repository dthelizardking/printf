#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char*)s + i);
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
