
char		*ft_strtoupper(char *str)
{
	char	*bogey;

	bogey = str;
	while (*bogey != '\0')
	{
		if (*bogey >= 'a' && *bogey <= 'z')
			*bogey -= 32;
		bogey++;
	}
	return (str);
}
