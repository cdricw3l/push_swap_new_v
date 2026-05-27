/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:35:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 09:41:51 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "../lib/libft.h"

#define RED  "\033[0;31m"
#define YELLOW  "\033[0;33m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"


#define ASSERT_DEBBUG(line) printf(RED"WE ARE HERE ligne:%d"RESET"\n", line)

#define OK 0
#define ERR -1
#define SPACE 32
#define PLUS 43
#define MINUS 45
#define STACK_A 0
#define STACK_B 1
#define A_AND_B 3
#define NO_MOVE 1
#define DISPLAY 0
#define NO_DISPLAY 1
#define NL printf("\n")
#define LEFT 0
#define RIGHT 1

enum e_algo
{
    NONE,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTATIVE
};

enum e_move
{
    S,
    P,
    R,
    RV,
    RR,
    RRR
};

typedef struct s_global_data
{
    int     *a;
    int     *b;
    int     *start;
    int     *end;
    int     stack[1024];
    int     algo;
    int     size_a;
    int     size_b;
    float   disorder;

} t_global_data;

typedef struct s_stack_data
{
    int     *arr;
    int     len;
    
} t_stack_data;

typedef struct s_best_move
{
    int number;
    int (*move)(t_global_data *, int, int);

} t_best_move;

/*

    rotate -> the last become the first
    rev_rotate <- the first become the last
*/

/* movement */

int push(t_global_data *data, int src, int dst, int mode);
int swap(t_global_data *data, int stack, int mode);
int rotate(t_global_data *data, int stack, int mode);
int rev_rotate(t_global_data *data, int stack, int mode);
int double_rotation(t_global_data *data, int move, int mode);

/* algo */

int three_values(t_global_data *data, int stack);
void five_values(t_global_data *data, int stk_src, int stk_dst);
int ft_buble_sort_push(t_global_data *data);

/* utils */

void    ft_swap(int *p1, int *p2);
void    display_data(t_global_data data);
void    display_stack(t_global_data *data, int stack);
void    print_move(int move, int stack);
float   compute_disorder(t_global_data *data);
void    put_float(float nb);
int     get_complexity(char *arg);
int     ft_is_sort(t_global_data *data, int stack);
int     *get_smalest_value(t_global_data *data, int stack);
int     *get_bigest_value(t_global_data *data, int stack);
int     get_stack_data(t_global_data data, int stack, t_stack_data *stk);

int	    at_beginning(t_global_data *data, int stack, int *(get_value)(t_global_data *, int));

#endif




//Doxygen