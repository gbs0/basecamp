#include <stdio.h>
#include <stdlib.h>

int ft_str_is_lowercase(char *str);

int main(void) {
    char *str = "";
    char *str1;
    
    char *str3;
    char *str4;
    char *str5;
    char *str6;

    str1 = calloc(10, sizeof(char));
    str3 = calloc(10, sizeof(char));
    str4 = calloc(10, sizeof(char));
    str5 = calloc(10, sizeof(char));
    str6 = calloc(10, sizeof(char));
    str1 = "123456789";
    str3 = "12345a67b89/";
    str4 = "Abcdefghi";
	str5 = "abc:efghi";
	str6 = "abcdefgh2";
    printf("str1: %s, is_lowercase?: %d\n", str1, ft_str_is_lowercase(str1));
    printf("str3: %s, is_lowercase?: %d\n", str3, ft_str_is_lowercase(str3));
    printf("str: %s, is_lowercase?: %d\n", str, ft_str_is_lowercase(str));
    return (0);
    
}