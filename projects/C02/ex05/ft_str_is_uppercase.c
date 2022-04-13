// Header 

#include <unistd.h>

int ft_str_is_uppercase(char *str)
{
    int i;
    
    i = 0;
    
    if (*str == '\0')
        return (1);
    
    while(*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            str++;
        } else {
            return (0);
        }
    }
    
    return(1);
}