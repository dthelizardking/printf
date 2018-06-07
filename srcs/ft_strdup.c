#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = -1;
	while (s1[++i])
		;
	if (!(s2 = (char*)malloc(sizeof(*s2) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
