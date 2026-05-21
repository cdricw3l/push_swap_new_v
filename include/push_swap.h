/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:35:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/21 14:34:29 by cdric.b          ###   ########.fr       */
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
#define NO_MOVE 1
#define NL printf("\n")

enum e_algo
{
    NONE,
    SIMPLE,
    MEDIUM,
    COMPLEX,
    ADAPTATIVE
};

typedef struct s_data
{
    int *a;
    int *b;
    int *start;
    int *end;
    int stack[1024];
    int algo;
    int size_a;
    int size_b;

} t_data;


/* utils */

void ft_swap(int *p1, int *p2);

#endif




