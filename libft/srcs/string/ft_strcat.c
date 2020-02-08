
char		*ft_strcat(char *s1, const char *s2)
{
	char *bogey;

	bogey = s1;
	while (*bogey != '\0')
		++bogey;
	while (*s2 != '\0')
		*bogey++ = *s2++;
	*bogey = '\0';
	return (s1);
}
