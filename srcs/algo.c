/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 09:07:16 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 22:32:54 by cdric.b          ###   ########.fr       */
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
#include <assert.h>

void tree_values(t_global_data *data)
{
    int a;
    int b;
    int c;

    a = *(data->a);
    b = *(data->a + 1);
    c = *(data->a + 2);
    
    if (a < b && b > c)
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
    else if (a > b && b < c)
        swap(data, STACK_A, DISPLAY);
    else if (a < b && b > c)
        rotate(data, STACK_A, DISPLAY);
    else if (a > b && b < c)
        rev_rotate(data, STACK_A, DISPLAY);
    else if ((a > b) &&  (b > c))
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
}

void five_values(t_global_data *data)
{
    if(ft_is_sort(data))
        return ;
    min_at_beginning(data, STACK_A);
    push(data, STACK_A,STACK_B, DISPLAY);
    min_at_beginning(data, STACK_A);
    push(data, STACK_A,STACK_B, DISPLAY);
    tree_values(data);
    push(data, STACK_B,STACK_A, DISPLAY);
    push(data, STACK_B,STACK_A, DISPLAY);
    display_stack(data, STACK_A);
}
