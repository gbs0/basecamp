// Header

#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    char word;

    word = 'z';
    while (word >= 'a')
    {
        write(1, &word, 1);
        word--;
    }
}
