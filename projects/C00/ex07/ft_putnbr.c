// Header

#include <unistd.h>

void ft_putnbr(int nb)
{
    write(1, '"' + &nb + '"', 1);
}