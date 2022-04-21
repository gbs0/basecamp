#include <stdlib.h>
#include <stdio.h>

int     ft_is_prime(int nb);
int main(void) {
    int i;
    i = 0;
    while (i < 100) {
        printf("%i: ", i);
        printf("%i, ", ft_is_prime(i));
        i++;
    }
}