// Header

#include <unistd.h>

int ft_str_is_printable(char *str)
{
    int i;
    
    i = 0;
    
    if (*str == '\0')
        return (1);
    
    while(*str != '\0')
    {
        if (*str >= 32 && *str <= 126)
        {
            str++;
        } else {
            return (0);
        }
    }
    
    return(1);
}