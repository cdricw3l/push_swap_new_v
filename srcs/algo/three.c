/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:31:22 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 15:45:52 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
	case 0: 3 4 5; 
	case 1: 3 5 4; 
	case 2: 4 3 5;

	case 3: 4 5 3;
	case 4: 5 3 4; 
	case 5: 5 4 3
*/

static int	three_value_data(t_global_data *data, int stack, int idx[3])
{
	if (stack != STACK_A && stack != STACK_B)
		return (ERR);
	if (stack == STACK_A)
	{
		idx[0] = *(data->a);
		idx[1] = *(data->a + 1);
		idx[2] = *(data->a + 2);
	}
	else if (stack == STACK_B)
	{
		idx[0] = *(data->b);
		idx[1] = *(data->b - 1);
		idx[2] = *(data->b - 2);
	}
	return (OK);
}

static int	three_values_stack_A(t_global_data *data, int stack)
{
	int	idx[3];

	if (three_value_data(data, stack, idx) == ERR)
		return (ERR);
	if (idx[0] < idx[1] && idx[0] < idx[2])
	{
		swap(data, stack, DISPLAY);
		rotate(data, stack, DISPLAY);
	}
	else if (idx[0] > idx[1] && idx[1] > idx[2])
	{
		swap(data, stack, DISPLAY);
		rev_rotate(data, stack, DISPLAY);
	}
	else if (idx[0] > idx[1] && idx[0] < idx[2])
		swap(data, stack, DISPLAY);
	else if (idx[0] < idx[1] && idx[1] > idx[2])
		rev_rotate(data, stack, DISPLAY);
	else if (idx[0] > idx[1] && idx[0] > idx[2])
		rotate(data, stack, DISPLAY);
	return (OK);
}
static int	three_values_stack_B(t_global_data *data, int stack)
{
	int	idx[3];

	if (three_value_data(data, stack, idx) == ERR)
		return (ERR);
	if (idx[0] < idx[1] && idx[1] < idx[2])
	{
		swap(data, stack, DISPLAY);
		rev_rotate(data, stack, DISPLAY);
	}
	else if (idx[0] > idx[1] && idx[0] > idx[2])
	{
		swap(data, stack, DISPLAY);
		rotate(data, stack, DISPLAY);
	}
	else if (idx[0] < idx[1] && idx[0] < idx[2])
		rotate(data, stack, DISPLAY);
	else if (idx[0] > idx[1] && idx[1] < idx[2])
		rev_rotate(data, stack, DISPLAY);
	else if (idx[0] < idx[1] && idx[1] > idx[2])
		swap(data, stack, DISPLAY);
	return (OK);
}

int	three_values(t_global_data *data, int stack)
{
	if (ft_is_sort(data, stack))
		return (NO_MOVE);
	if (stack == STACK_A)
		return (three_values_stack_A(data, stack));
	if (stack == STACK_B)
		return (three_values_stack_B(data, stack));
	return (ERR);
}