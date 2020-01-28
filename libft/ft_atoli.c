long long		ft_atoli(const char *str)
{
	long long	res;
	long long	sign;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str += 1;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
	{
		str += 1;
	}
	res = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str += 1;
		if (res >= 223372036854775808 && *str == '9' && sign == -1)
			return (0);
		if (res > 223372036854775807 && *str == '9')
			return (-1);
	}
	res *= sign;
	return (res);
}
