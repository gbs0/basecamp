/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:05:23 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/31 10:56:57 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n);

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    unsigned char *src_c;

    i = 0;
    src_c = (unsigned char *)s;
    if (n == 0)
        return (0);
    while (i < n)
    {
        if (src_c[i] == (unsigned char)c)
            return ((void *)&src_c[i]);
        i++;
    }
    return (0);
}

void ft_memchr_test(char ptr, char ptr_ref)
{
    printf("ft_memchar() - It Should Return %c\033[29m\n", ptr);
    if (ptr == ptr_ref)
        printf("\033[32m Success\033[0m\n");
    else
        printf("\033[31m Failed\033[0m\n");
}

int main(int argc, const char * argv[])
{
    char search[] = "TechOnTheNet";
    char long_string[] = "LoremIpsumDolorSitAmet.";
    char *lng;
    char *lng_ref;
    char *ptr;
    char *ptr_ref;

    /* Return a pointer to the first 'N' within the search string */
    ptr = (char*)memchr(search, 'N', strlen(search));
    ptr_ref = ft_memchr(search, 'N', strlen(search));
    lng = (char *)memchr(long_string, 'y', strlen(long_string));
    lng_ref = ft_memchr(long_string, 'y', strlen(long_string));

    /* If 'N' was found, print its location (This should produce "10") */
    // if (ptr != NULL) printf("Found 'N' at position %ld.\n", 1+(ptr-search));
    // else printf("'N' was not found.\n");

    ft_memchr_test(*ptr, *ptr_ref);
    ft_memchr_test(*lng, *lng_ref);
    return 0;
}