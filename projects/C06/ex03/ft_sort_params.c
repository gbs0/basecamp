#include <unistd.h>

void ft_putchar(char s)
{
    write(1, &s, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int main(int argc, char *argv)
{
    int	args;

    args = 0;
    while (args < argc)
    {
        if(argv[args] > argv[args + 1])
        {
        }
            
    }

    return (0);
}