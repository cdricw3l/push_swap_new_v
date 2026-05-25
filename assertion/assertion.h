#ifndef ASSERTION_H
#define ASSERTION_H

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/push_swap.h"

#define RED  "\033[0;31m"
#define YELLOW  "\033[0;33m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

#define ASSERT_START(msg, line) printf(YELLOW"Test assertion %s line: %d\n" RESET, msg, line)
#define ASSERT_END(msg) printf(GREEN"End assertion %s --> Ok!\n"RESET, msg)

void    move_assertions(int argc, char **argv);
int     init_and_check_assert(int argc, char **argv);


void display_stack(t_global_data *data, int stack);
int check_args(char **argv, t_global_data *data);
int check_digit(char *str);
int get_complexity(char *arg);
int check_args(char **argv, t_global_data *data);
int create_stack(char **argv, t_global_data *data);
int check_duplicate(t_global_data *data);
int init_global_data(char **argv, t_global_data *data);
void display_data(t_global_data data);


void algo_assert(char **argv);

#endif