/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:32:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 13:55:24 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	five_values(t_global_data *data, int stack)
{
	if (ft_is_sort(data, stack))
		return ;
	if(stack == STACK_A)
	{
		at_beginning(data, stack, smalest_value);
		push(data, stack, STACK_B, DISPLAY);
		at_beginning(data, stack, smalest_value);
		push(data, stack, STACK_B, DISPLAY);
		three_values(data, stack);
		push(data, STACK_B, stack, DISPLAY);
		push(data, STACK_B, stack, DISPLAY);

	}
	else if (stack == STACK_B)
	{
		at_beginning(data, stack, bigest_value);
		push(data, stack, STACK_A, DISPLAY);
		at_beginning(data, stack, bigest_value);
		push(data, stack, STACK_A, DISPLAY);
		three_values(data, stack);
		push(data, STACK_A, STACK_B, DISPLAY);
		push(data, STACK_A, STACK_B, DISPLAY);
	}
}
