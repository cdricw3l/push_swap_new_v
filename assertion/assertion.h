#ifndef ASSERTION_H
#define ASSERTION_H

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/push_swap.h"


#define ASSERT_START(msg, line) printf(YELLOW"Test assertion %s line: %d" RESET"\n", msg, line)
#define ASSERT_END(msg) printf(GREEN"End assertion %s --> Ok!"RESET"\n", msg)

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
void middle_algo_assert(void);


void three_value_assert(void);
void five_value_assert();

#endif