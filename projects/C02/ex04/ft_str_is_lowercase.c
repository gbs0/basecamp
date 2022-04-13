// Header

#include <unistd.h>

int ft_str_is_lowercase(char *str) 
{
    int i;
    
    i = 0;
    
    if (*str == '\0')
        return (1);

    while(*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            str++;
        } else {
            return (0);
        }
    }

    return(1);
}
