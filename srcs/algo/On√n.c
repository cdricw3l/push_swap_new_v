/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   On√n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:17:06 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 17:43:36 by cebouhad         ###   ########.fr       */
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

// void middle_rank(t_global_data *data)
// {
//     int range_size;

//     range_size = 5;
// }