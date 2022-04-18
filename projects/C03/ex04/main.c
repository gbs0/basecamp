#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char *str;
	char *to_find;
	char *result;
	char *ft_result;

	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(7, sizeof(char)), "galera");
	result = strstr(str, to_find);
	ft_result = ft_strstr(str, to_find);
	if (result != ft_result)
		printf("[1] KO, substrings don't match(expected:%s, got:%s)\n", result, ft_result); 
	else
		printf("[1] OK. expected: %s result: %s\n", result, ft_result);
	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(7, sizeof(char)), "galerA");
	result = strstr(str, to_find);
	ft_result = ft_strstr(str, to_find);
	if (result != ft_result)
		printf("[2] KO, substrings don't match(expected:%s, got:%s)\n", result, ft_result); 
	else
		printf("[2] OK. expected: %s result: %s\n", result, ft_result);
	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(1, sizeof(char)), "");
	result = strstr(str, to_find);
	ft_result = ft_strstr(str, to_find);
	if (result != ft_result)
		printf("[3] KO, substrings don't match(expected:%s, got:%s)\n", result, ft_result); 
	else
		printf("[3] OK. expected: %s result: %s\n", result, ft_result);
	return (0);
}