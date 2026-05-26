/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   On√n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:17:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 19:16:51 by cebouhad         ###   ########.fr       */
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


int *find_best_value(t_global_data data, int range[2])
{
    int *p_start;
    int *p_end;
    int place;
    
    p_start = data.a;
    p_end = data.a + (data.size_a - 1);
    
    while (p_start < (data.a + (data.size_a - 1)))
    {
        place = place_int_stack(&data, STACK_A ,*p_start);
        if(place >= range[0] && place <= range[1])
        {
            break;
        }
        p_start++;
    }
    while (p_end > data.a)
    {
        place = place_int_stack(&data, STACK_A ,*p_end);
        if(place >= range[0] && place <= range[1])
            break;
        p_end--;
    }

    printf("p1 %ld et p2 %ld\n", (p_start - data.a ), (data.a + (data.size_a - 1)  - p_end) + 1);
    if(p_start - data.a < (data.a + (data.size_a - 1)  - p_end) + 1)
        return (p_start);
    
    return (p_end);
}

void middle_rank(t_global_data *data)
{
    int range[2];

    range[0] = 1;
    range[1] = 5;
    find_best_value(*data, range);
    
}