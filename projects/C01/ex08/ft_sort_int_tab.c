// Header

#include <unistd.h>

void ft_sort_int_tab(int *tab, int size) 
{
    int i;
    int j;
    int temp;

    i = 0;
    j = size - 1;
    while (i < j)
    {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
        i++;
        j--;
    }
}