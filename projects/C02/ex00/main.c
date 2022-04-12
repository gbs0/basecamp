#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char *src;
	char *dest;
	char *result;

	src = calloc(11, sizeof(char));
	src = "0123456789";
	dest = calloc(11, sizeof(char));
	result = ft_strcpy(dest, src);	
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("result: %s\n", result);
    return (0);

}