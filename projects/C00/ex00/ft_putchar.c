// Header

#include <unistd.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

// ft_putchar("42");