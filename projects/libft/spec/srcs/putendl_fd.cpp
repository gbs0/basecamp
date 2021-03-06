/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:42:51 by trofidal          #+#    #+#             */
/*   Updated: 2022/05/31 14:37:00 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#define new bar
#include "include/libft.h"
#undef new
};

#include "../includes/main_header.hpp"

std::string testing;
int         test_number;

int create_test_file( char *file_name, char *str ){
    int __FILE_DESCRIPTOR__ = 0, found = 0;
    char    occur[20];
    memset(occur, 0, 20);
	std::string	find;

    #define a ft_putendl_fd
    
    __FILE_DESCRIPTOR__ = open(file_name, O_RDWR | O_CREAT);
    found = 0;
    chmod(file_name, 777);
    a(str, __FILE_DESCRIPTOR__);
    strcpy(occur, str);
    std::ifstream test_nd(file_name);
	std::getline(test_nd, find);
    if (strcmp(find.c_str(), occur) == 0)
    	found++;
    remove(file_name);
    return (found);
}

int main(void){
    std::string fN = "putendl_fd"; //Function Name
    Infos   trofidal(fN, 4);
    signal(SIGSEGV, segfault_handler);
    
    #define a ft_putendl_fd
    #define s std::to_string
    #define t setTesting
    int    found = 0;
    
    found = create_test_file((char *)"test_file", (char *)"hi i am test one");
    /*1*/trofidal.t(fN, "hi i am test one");trofidal.tInt(found, 1); 
    found = create_test_file((char *)"test_file", (char *)"yo soy test deux");
    /*2*/trofidal.t(fN, "yo soy test deux, fd");trofidal.tInt(found, 1);
    found = create_test_file((char *)"test_file", (char *)"t");
    /*3*/trofidal.t(fN, "t, fd");trofidal.tInt(found, 1); 
    found = create_test_file((char *)"test_file", (char *)"");
    /*4*/trofidal.t(fN, ", fd");trofidal.tInt(found, 1);  
}