#ifndef ASSERTION_H
#define ASSERTION_H

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/push_swap.h"

#define YELLOW  "\033[0;33m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

#define ASSERT_START(msg) printf(YELLOW"Test assertion %s\n"RESET, msg)
#define ASSERT_END(msg) printf(GREEN"End assertion %s --> Ok!\n"RESET, msg)




#endif