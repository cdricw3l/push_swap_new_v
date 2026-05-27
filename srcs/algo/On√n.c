/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   On√n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:17:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 16:13:22 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int place_int_stack(t_global_data *data, int stack, int value)
{
    t_stack_data    stk;
    int             count;
    
    if(get_stack_data(*data, stack, &stk) == ERR)
        return (ERR);
    count = 1;
    if(stack == STACK_A)
    {
        while (stk.arr <= data->end)
        {
            if (*(stk.arr) < value)
                count++;
            stk.arr++;
        }
    }
    if(stack == STACK_B)
    {
        while (stk.arr >= data->start)
        {
            if (*(stk.arr) < value)
                count++;
            stk.arr--;
        }
    }
    return(count);
}


t_best_move best_move(t_global_data data, int range[2])
{
    t_best_move best_move;
    int *p_start;
    int *p_end;
    int place;
    
    p_start = data.a;
    p_end = data.a + (data.size_a - 1);
    while (p_start < (data.a + (data.size_a - 1)))
    {
        place = place_int_stack(&data, STACK_A ,*p_start);
        if(place >= range[0] && place <= range[1])
            break;
        p_start++;
    }
    while (p_end > data.a)
    {
        place = place_int_stack(&data, STACK_A ,*p_end);
        if(place >= range[0] && place <= range[1])
            break;
        p_end--;
    }
    if(p_start - data.a < (data.a + (data.size_a - 1)  - p_end) + 1)
    {
        best_move.number = p_start - data.a;
        best_move.move= rotate;
    }
    else
    {
        best_move.number = (data.a + (data.size_a - 1)  - p_end) + 1;
        best_move.move= rev_rotate;
    }
    return (best_move);
}

#define RANGE_SIZE 5
#include <assert.h>

void middle_rank(t_global_data *data)
{
    int range[2];
    int nb_range;
    t_best_move best;

    nb_range = data->size_a / RANGE_SIZE;
    range[1] = (RANGE_SIZE * nb_range);
    range[0] =  (range[1] - RANGE_SIZE) + 1;
    best_move(*data, range);
    while (nb_range > 0)
    {
        while (data->size_b != RANGE_SIZE)
        {
            best = best_move(*data, range);
            while (best.number > 0)
            {
                best.move(data, STACK_A, DISPLAY);
                best.number--;
            }
            push(data, STACK_A, STACK_B, DISPLAY);
        }
        five_values(data,STACK_B);
        while (data->b)
            push(data, STACK_B, STACK_A, DISPLAY);
        int i = 0;
        if(range[0] > 1)
        {
            while (i < RANGE_SIZE)
            {
                rotate(data, STACK_A, DISPLAY);
                i++;
            }
        }
        range[1] -= RANGE_SIZE;
        range[0] -= RANGE_SIZE;
        nb_range--;
    }
    
}