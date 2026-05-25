/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 09:07:16 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 20:59:44 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_buble_sort_push(t_global_data *data)
{
    int count;

    count = 0;
    display_stack(data, STACK_A);
    
    rev_rotate(data, STACK_A, DISPLAY);
    display_stack(data, STACK_A);
    return (count);
}

/*
    case 0: 3 4 5; 

    case 1: 3 5 4; 

    case 2: 4 3 5;

    case 3: 4 5 3;

    case 4: 5 3 4; 

    case 5: 5 4 3
*/

void tree_values(t_global_data *data)
{
    // if (ft_is_sort(data))
    //     return ;
    
    /* case 1 */
    if (*(data->a) < (*(data->a + 1) && *(data->a + 1) > *(data->a + 2)))
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
    // /* case 2 */
    else if (*(data->a) > (*(data->a + 1) && *(data->a) < *(data->a + 2)))
        swap(data, STACK_A, DISPLAY);
    /* case 3 */
    else if (*(data->a) < (*(data->a + 1) && *(data->a) > *(data->a + 2)))
        rotate(data, STACK_A, DISPLAY);
    /* case 4 */
    else if (*(data->a) > (*(data->a + 1) && *(data->a + 1) < *(data->a + 2)))
        rev_rotate(data, STACK_A, DISPLAY);
     /* case 5 */    
    else if (*(data->a) > *(data->a + 1) &&  *(data->a + 1) > *(data->a + 2))
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
    
}

void five_values(t_global_data *data)
{
    min_at_beginning(data, STACK_A);
    push(data, STACK_A,STACK_B, DISPLAY);
    min_at_beginning(data, STACK_A);
    push(data, STACK_A,STACK_B, DISPLAY);
    display_stack(data, STACK_A);
    tree_values(data);
    display_stack(data, STACK_A);
    push(data, STACK_B,STACK_A, DISPLAY);
    push(data, STACK_B,STACK_A, DISPLAY);
}
