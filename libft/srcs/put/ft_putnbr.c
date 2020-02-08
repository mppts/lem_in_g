
#include "libft.h"

void		ft_putnbr(int n)
{
	long long		num;

	num = (long long)n;
	if (n < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}
