
#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	uint8_t	*ss1;
	uint8_t	*ss2;

	if (n == 0 && s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-*s2);
	if (s2 == NULL)
		return (*s1);
	ss1 = (uint8_t*)s1;
	ss2 = (uint8_t*)s2;
	while (--n && *ss1 && *ss2 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}