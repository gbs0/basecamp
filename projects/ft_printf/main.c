#include "./include/libftprintf.h"
#include <stdio.h>

int main(){
    void* ptr = 0;
    int ret_orig = printf("%p", ptr);
    int ret_gschiavo = ft_printf("%p", ptr);

	
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
    printf("\nret orig = %d\nret gschiavo = %d\n", ret_orig, ret_gschiavo);
	
    return 0;
}