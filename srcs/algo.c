/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 09:07:16 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 15:35:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
    case 0: 3 4 5; 
    case 1: 3 5 4; 
    case 2: 4 3 5;

    case 3: 4 5 3;
    case 4: 5 3 4; 
    case 5: 5 4 3
*/

int tree_values(t_global_data *data, int stack)
{
    t_stack_data stk;
    int a;
    int b;
    int c;

    if(ft_is_sort(data, stack))
        return(NO_MOVE);
    if (get_stack_data(*data,stack, &stk) == ERR)
        return (NO_MOVE);
    if (stack == STACK_A)
    {
        a = *(data->a);
        b = *(data->a + 1);
        c = *(data->a + 2);
    }
    else if (stack == STACK_B)
    {
        a = *(data->b);
        b = *(data->b - 1);
        c = *(data->b - 2);
    }
    else
        return (NO_MOVE);
    if (a < b && a < c)                         /* case 1 */
    {
        swap(data, stack, DISPLAY);
        rev_rotate(data, stack, DISPLAY);
    }
    else if (a > b &&  b > c)               /* case 5 */
    {
        swap(data, stack, DISPLAY);
        rotate(data, stack, DISPLAY);
    }
    else if (a > b && a < c)                    /* case 2 */
        swap(data, stack, DISPLAY);
    else if (a < b && b > c)                /* case 3 */
        rotate(data, stack, DISPLAY);
    else if (a > b &&  a > c)               /* case 4 */
        rev_rotate(data, stack, DISPLAY);
    return (OK);
}

void five_values(t_global_data *data, int stk_src, int stk_dst)
{
    if(ft_is_sort(data, stk_src))
        return ;
    min_at_beginning(data, stk_src);
    push(data, stk_src, stk_dst, DISPLAY);
    min_at_beginning(data, stk_src);
    push(data, stk_src, stk_dst, DISPLAY);
    tree_values(data, stk_src);
    push(data, stk_dst, stk_src, DISPLAY);
    push(data, stk_dst, stk_src, DISPLAY);
}
