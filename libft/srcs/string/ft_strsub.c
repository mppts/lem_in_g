
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s || !(sub_s = ft_strnew(len)))
		return (NULL);
	s = s + start;
	ft_memcpy((void *)sub_s, (const void *)s, len);
	return (sub_s);
}
