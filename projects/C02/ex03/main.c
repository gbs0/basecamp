#include <stdio.h>
#include <stdlib.h>

int ft_str_is_numeric(char *str);

int main(void) {
    char *str = "";
    char *str1;
    char *str2;
    char *str3;

    str1 = calloc(10, sizeof(char));
    str2 = calloc(10, sizeof(char));
    str3 = calloc(10, sizeof(char));
    str1 = "123456789";
    str2 = "0987654321";
    str3 = "12345a67b89/";
    printf("str1: %s, is_numeric?: %d\n", str1, ft_str_is_numeric(str1));
    printf("str2: %s, is_numeric?: %d\n", str2, ft_str_is_numeric(str2));
    printf("str3: %s, is_numeric?: %d\n", str3, ft_str_is_numeric(str3));
    printf("str: %s, is_numeric?: %d\n", str, ft_str_is_numeric(str));
    return (0);
    
}