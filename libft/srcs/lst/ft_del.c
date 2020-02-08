
#include "libft.h"

void		ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}
