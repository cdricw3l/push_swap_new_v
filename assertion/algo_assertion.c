/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 07:46:39 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int         place_int_stack(t_global_data *data, int stack, int value);
t_best_move best_move(t_global_data data, int range[2]);
/*

    rotate -> the last become the first
    rev_rotate <- the first become the last
*/

/*
    case 0: 3 4 5; 
    case 1: 3 5 4; 
    case 2: 4 3 5;

    case 3: 4 5 3;
    case 4: 5 3 4; 
    case 5: 5 4 3
*/





void find_best_value_of_range_assert(void)
{
    int range[2];
    t_global_data data;
    t_best_move best;
    
    //range 1 > 2 6 10 12 20
    //range 2 > 22 31 54 132 558
    char *s[] = {"132 12 10 22  31 558 54 6 78 -5", NULL};
    assert(init_global_data(s, &data) == OK);
    range[0] = 1;
    range[1] = 5;
    
    display_stack(&data, STACK_A);
    while (data.a)
    {
        best = best_move(data, range);
        while (best.number > 0)
        {
            best.move(&data, STACK_A, DISPLAY);
            best.number--;
        }
        push(&data, STACK_A, STACK_B, DISPLAY);
        if(data.size_b == range[1])
        {
            five_values(&data, STACK_B);
            range[0] += 5;
            range[1] += 5;
        }
    }
    display_stack(&data, STACK_B);
}

void algo_assert(char **argv)
{
    (void)argv;
    
    three_value_assert();
    five_value_assert();
}   