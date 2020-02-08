
#include "./libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t dstlen;

	if (!dst || !src)
		return (-1);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (0 == size)
		return (srclen);
	if (srclen <= size && srclen <= dstlen)
	{
		ft_memcpy((void *)dst, (const void *)src, srclen + 1);
		return (srclen);
	}
	ft_memcpy((void *)dst, (const void *)src, size - 1);
	*(dst + size - 1) = '\0';
	return (srclen);
}
