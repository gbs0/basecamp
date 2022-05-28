#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
	int     i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}


int main()
{
	char    lorem[] = "Lorem ipsum dolor";
	char c;

	c = 'l';
	ft_strchr(lorem, c);

	printf("Caracter %d encontrado!", c);

	return (0);
}
