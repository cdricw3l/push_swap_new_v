/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:35:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/23 14:10:30 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "../lib/libft.h"

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

typedef struct s_data
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

} t_data;

/* movement */

int push(t_data *data, int src, int dst, int mode);
int swap(t_data *data, int stack, int mode);
int rotate(t_data *data, int stack, int mode);
int rev_rotate(t_data *data, int stack, int mode);
int double_rotation(t_data *data, int move, int mode);

/* utils */

void    ft_swap(int *p1, int *p2);
void    display_data(t_data data);
void    display_stack(t_data *data, int stack);
void    print_move(int move, int stack);
float   compute_disorder(t_data *data);
void    put_float(float nb);
int     get_complexity(char *arg);

#endif




