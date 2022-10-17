/*
*    Time: 04/10/22 08:43:52
*    Create By yongheng
*/

#ifndef COUT_ERROR_MSG 
#define COUT_ERROR_MSG
#include <iostream>
#define COUT_ERROR(msg) std::cout << "\033[31m"<< msg << "\033[0m" << std::endl;

#endif
