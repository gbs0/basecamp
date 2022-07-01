#include "./include/libftprintf.h"
#include <stdio.h>

int main(){
    void* ptr = 0;
    int ret_orig = printf(" %p %p ", ptr, ptr);
    int ret_gschiavo = ft_printf("%p %p ", ptr, ptr);

	
	// printf("%p\n", ptr);
	// ft_printf("%p\n", ptr);
    
    printf("\nret orig = %d\nret gschiavo = %d\n", ret_orig, ret_gschiavo);
	
    // printf(" %p %p \n", (void *) 0, (void *) 0);
    // ft_printf(" %p %p \n", (void *) 0, (void *) 0);
    return 0;
}