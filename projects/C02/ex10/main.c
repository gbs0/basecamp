
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void ft_strlcpy_test(int ft_res, int str_res)
{
	
	if (ft_res != str_res)
		printf("> KO, expected: %d, got: %d\n", ft_res, str_res);
	else
		printf("> OK, result: %d\n", ft_res);
}

int				main(void)
{
	int 	ft_size1;
	int 	ft_size2;
	int 	ft_size3;
	int 	str_size1;
	int 	str_size2;
	int 	str_size3;
	char 	*src;
	char 	*dest;


	src = calloc(11, sizeof(char));
	dest = calloc(8, sizeof(char));
	src = "alo galera";
	ft_size1 = ft_strlcpy(dest, src, 8);
	ft_size2 = ft_strlcpy(dest, src, 11);
	ft_size3 = ft_strlcpy(dest, src, 0);
	str_size1 = strlcpy(dest, src, 8);
	str_size2 = strlcpy(dest, src, 11);
	str_size3 = strlcpy(dest, src, 0);

	ft_strlcpy_test(ft_size1, str_size1);
	ft_strlcpy_test(ft_size2, str_size2);
	ft_strlcpy_test(ft_size3, str_size3);
	
	// printf("src: %s\n", src);
	// printf("dest: %s\n", dest);
	// printf("src_size: %d\n", src_size1);
	// printf("src_size: %d\n", src_size2);
	// printf("src_size: %d\n", src_size3);

	return(0);
}

// ----------------------  Teste  --------------------------------
