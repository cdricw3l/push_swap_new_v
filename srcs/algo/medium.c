/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:17:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 14:49:37 by cebouhad         ###   ########.fr       */
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


t_best_move *best_move(t_global_data data, int range[2])
{
    t_best_move *best_move;
    int *p_start;
    int *p_end;
    int place;
    
    p_start = data.a;
    p_end = data.a + (data.size_a - 1);
    best_move = malloc(sizeof(t_best_move));
    if(!best_move)
        return (NULL);
    while (p_start < (data.a + (data.size_a - 1)))
    {
        place = place_int_stack(&data, STACK_A ,*p_start);
        if(place >= range[0] && place <= range[1])
            break;
        p_start++;
    }
    if (p_start == (data.a + (data.size_a - 1)))
        return (NULL);
    while (p_end > data.a)
    {
        place = place_int_stack(&data, STACK_A ,*p_end);
        if(place >= range[0] && place <= range[1])
            break;
        p_end--;
    }
    /*   
        check if the best move is to the left or to the right.
    */
    if(p_start - data.a < (data.a + (data.size_a - 1)  - p_end) + 1)
    {
        best_move->value = *p_start;
        best_move->number = p_start - data.a;
        best_move->move= rotate;
    }
    else
    {
        best_move->value = *p_end;
        best_move->number = ((data.a + (data.size_a - 1))  - p_end) + 1;
        best_move->move= rev_rotate;
    }
    return (best_move);
}

#include <assert.h>

void display_range(int ranges[1024][2], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("range %d: [end]: %d [start] %d\n", i, ranges[i][1], ranges[i][0]);
        i++;
    }
}

int medium_rank(t_global_data *data)
{
    int ranges[LIMIT][2];
    //int i;
    int nb_range;

    nb_range = generate_range(ranges, data->size_a);
    if(nb_range == ERR)
        return (ERR);
    display_range(ranges, nb_range);

 

    // i = 0;
    // while (i < 1)
    // {
    //     int j;

    //     j = 0;
    //     t_best_move *best;
    //     ;
    //     while ((best = best_move(*data, ranges[i])) != NULL)
    //     {
    //         printf("range %d: [end]: %d [start] %d\n", i, ranges[i][1], ranges[i][0]);
    //         while (best->number > 0)
    //         {
    //             best->move(data, STACK_A, DISPLAY);
    //             push(data, STACK_A, STACK_B, DISPLAY);
    //             best->number--;
    //         }
    //     }
    //     i++;
    // }
    // display_stack(data, STACK_B);
    return (OK);
}