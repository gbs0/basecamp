#include <stdio.h>
#include <stdlib.h>

int ft_str_is_uppercase(char *str);

int main(void) {
    char *str = "";
    char *str1;
    char *str2;
    char *str3;
    char *str4;
    char *str5;
    char *str6;

    str1 = calloc(10, sizeof(char));
    str2 = calloc(10, sizeof(char));
    str3 = calloc(10, sizeof(char));
    str4 = calloc(10, sizeof(char));
    str5 = calloc(10, sizeof(char));
    str6 = calloc(10, sizeof(char));
    str1 = "Abcdefghi";
    str2 = "123456789";
    str3 = "12345a67b89/";
    str4 = "abcdefghiJ";
	str5 = "abc:efghi";
	str6 = "ABCDEFGHIJ";
    printf("str1: %s, is_lowercase?: %d\n", str1, ft_str_is_uppercase(str1));
    printf("str2: %s, is_lowercase?: %d\n", str2, ft_str_is_uppercase(str2));
    printf("str3: %s, is_lowercase?: %d\n", str3, ft_str_is_uppercase(str3));
    printf("str4: %s, is_lowercase?: %d\n", str4, ft_str_is_uppercase(str4));
    printf("str5: %s, is_lowercase?: %d\n", str5, ft_str_is_uppercase(str5));
    printf("str6: %s, is_lowercase?: %d\n", str6, ft_str_is_uppercase(str6));
    printf("str: %s, is_lowercase?: %d\n", str, ft_str_is_uppercase(str));
    return (0);
    
}