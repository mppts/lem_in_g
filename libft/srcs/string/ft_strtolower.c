
char		*ft_strtolower(char *str)
{
	char	*bogey;

	bogey = str;
	while (*bogey != '\0')
	{
		if (*bogey >= 'A' && *bogey <= 'Z')
			*bogey += 32;
		bogey++;
	}
	return (str);
}
