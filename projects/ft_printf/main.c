#include "./include/libftprintf.h"
#include <stdio.h>

int main(){
    void* ptr = 0;
    int ret_orig = printf("%p", ptr);
    int ret_gschiavo = ft_printf("%p", ptr);

    int n = 15;
    void* ptr2 = &n;
    int ret_orig_2 = printf("%p", ptr2);
    int ret_gschiavo_2 = ft_printf("%p", ptr2);


    printf("\nret orig = %d\nret gschiavo = %d\n", ret_orig, ret_gschiavo);
    printf("\nret orig = %d\nret gschiavo = %d\n", ret_orig_2, ret_gschiavo_2);
    return 0;
}