#include <stdio.h>
#include <stdlib.h>

int ft_recursive_factorial(int nb);

int main(void)
{
    if (ft_recursive_factorial(5) != 5*4*3*2*1)
		printf("KO, wrong 5 factorial");
	else if (ft_recursive_factorial(3) != 6)
		printf("KO, wrong 3 factorial");
	else if (ft_recursive_factorial(7) != 7*6*5*4*3*2*1)
		printf("KO, wrong 7 factorial");
	else if (ft_recursive_factorial(4) != 4*3*2*1)
		printf("KO, wrong 4 factorial");
	else if (ft_recursive_factorial(0) != 1)
		printf("KO, wrong 0 factorial");
	else if (ft_recursive_factorial(-3) != 0)
		printf("KO, wrong -3 factorial");
	else if (ft_recursive_factorial(2) != 2)
		printf("KO, wrong 2 factorial");
	else
		printf("OK\n");
}