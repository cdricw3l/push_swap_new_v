/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:32:50 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 15:34:38 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>



int main(void)
{
    t_global_data data;
    char *arg[] = {"--simple -126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631", NULL};

    init_global_data(arg,&data);
    while (data.size_a != data.size_b)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);

    display_stack(&data, STACK_A);
    display_stack(&data, STACK_B);
    
    rotate(&data, STACK_A, DISPLAY);
    rotate(&data, STACK_B, DISPLAY);
    
    display_stack(&data, STACK_A);
    display_stack(&data, STACK_B);
    
    // rev_rotate(&data, STACK_A, DISPLAY);
    // rev_rotate(&data, STACK_B, DISPLAY);
    // rev_rotate(&data, STACK_A, DISPLAY);
    // display_stack(&data, STACK_A);
    // display_stack(&data, STACK_B);
    // rev_rotate(&data, STACK_B, DISPLAY);
    
    // display_stack(&data, STACK_A);
    //display_stack(&data, STACK_B);
    return (0);
}