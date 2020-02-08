
#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	size_src;

	size_src = ft_strlen(src) + 1;
	ft_memcpy((void *)dst, (void *)src, size_src);
	return (dst);
}
