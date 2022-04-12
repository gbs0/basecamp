// Header

#include <unistd.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int     i;
    i = 0;
    
    if (n == 0)
        return (dest);
    
    while(i < n)
    {
        dest[i] = src[i];
        i++;
    }
    
    return(dest);
}