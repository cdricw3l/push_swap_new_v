/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:17:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/29 01:00:28 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int place_int_stack(t_global_data *data, int value)
{
    int             count;
    int             *p_start;

    p_start = data->start;
    count = 1;
    while (p_start <= data->end)
    {
        if(*p_start < value)
            count++;
        p_start++;
    }
    return(count);
}

t_best_move *best_move(t_global_data *data, int range[2])
{
    t_best_move *best_move;
    int *p_start;
    int *p_end;
    int place;
    
    p_start = data->a;
    p_end = data->a + (data->size_a - 1);
    
    while (p_start < p_end)
    {
        place = place_int_stack(data, *p_start);
        if(place >= range[0] && place <= range[1])
            break;
        p_start++;
    }
    while (p_end >= data->a)
    {
        place = place_int_stack(data, *p_end);
        if(place >= range[0] && place <= range[1])
            break;
        p_end--;
    }
    if (p_start > p_end)
        return (NULL);
    best_move = malloc(sizeof(t_best_move));
    if(!best_move)
        return (NULL);
    if(p_start - data->a < (data->a + (data->size_a - 1)  - p_end) + 1 || p_end == p_start)
    {
        best_move->value = *p_start;
        best_move->number = p_start - data->a;
        best_move->move= rotate;
    }
    else
    {
        best_move->value = *p_end;
        best_move->number = ((data->a + (data->size_a - 1))  - p_end) + 1;
        best_move->move= rev_rotate;
    }
    return (best_move);
}

int check_if_range_is_sorted(t_global_data *data, int range[2])
{
    int i;
    int *start;
    int *end;

    start = data->a;
    end = data->a + (data->size_a - 1);
    while (start < end)
    {
        if (place_int_stack(data, *start) == range[0])
        {
            i = 0;
            while (start + i < end && i < RANGE_SIZE)
            {
                if(start + i > start + (i + 1))
                    return(0);
                i++;
            }
            return(1);
        }
        start++;
    }
    
}

int medium_rank(t_global_data *data)
{
    int i;
    int nb_range;
    int ranges[LIMIT][2];
    t_best_move *best;
    
    nb_range = generate_range(ranges, data->size_a);
    if(nb_range == ERR)
        return (ERR);
    i = 0;
    while (i < nb_range)
    {
        best = best_move(data, ranges[i]);
        while(best != NULL)
        {
            move(data, STACK_A, best->move, best->number);
            free(best);
            push(data, STACK_A, STACK_B, DISPLAY);
            best = best_move(data, ranges[i]);
        }
        five_values(data, STACK_B);
        at_beginning(data, STACK_A, immediat_superior(data, STACK_A, data->b));
        while (data->b)
            push(data, STACK_B, STACK_A, DISPLAY);
        i++;
    }
    return (OK);
}
