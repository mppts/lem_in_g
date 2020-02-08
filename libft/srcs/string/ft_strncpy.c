
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*sub_res;

	sub_res = dst;
	while (*src != '\0' && 0 < len)
	{
		*dst++ = *src++;
		--len;
	}
	while (0 < len)
	{
		*dst++ = '\0';
		--len;
	}
	return (sub_res);
}
