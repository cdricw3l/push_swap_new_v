/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:35:55 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/19 19:09:25 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

#define OK 0
#define ERR 1
#define SPACE 32
#define PLUS 43
#define MINUS 45

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
    int algo;
    size_t size_a;
    size_t size_b;

} t_data;

int check_args(char **argv, t_data *data);
int check_digit(char *str);
int get_complexity(char *arg);


#endif




