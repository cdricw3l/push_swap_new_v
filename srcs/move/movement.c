/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:01:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 15:34:54 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int push(t_global_data *data, int src, int dst, int mode)
{
	if (!data)
		return (NO_MOVE);
	if(src == STACK_A && dst == STACK_B && data->size_a)
	{
		data->b = data->a;
		data->size_b++;
		data->a++;
		data->size_a--;
		if (data->size_a == 0)
			data->a = NULL;
		if (mode == DISPLAY)
			print_move(P, dst);
		return (OK);
	}
	if (src == STACK_B && dst == STACK_A && data->size_b)
	{
		data->a = data->b;
		data->size_a++;
		data->b--;
		data->size_b--;
		if (data->size_b == 0)
			data->b = NULL;
		if (mode == DISPLAY)
			print_move(P, dst);
		return (OK);
	}
	return (NO_MOVE);
}

int swap(t_global_data *data, int stack, int mode)
{
	t_stack_data stk;

	if (!data || get_stack_data(*data, stack, &stk) == ERR)
		return (NO_MOVE);
	if (!stk.arr && stk.len < 1)
		return (NO_MOVE);
	if (stack == STACK_A)
		ft_swap(stk.arr, stk.arr + 1);
	else if(stack == STACK_B)
		ft_swap(stk.arr, stk.arr - 1);
	if (mode == DISPLAY)
		print_move(S, stack);
	return (OK);
}

int rotate(t_global_data *data, int stack, int mode)
{
	int tmp;

	if (!data || (stack != STACK_A && stack != STACK_B))
		return (NO_MOVE);
	if (stack == STACK_A && data->a)
	{
		tmp = *(data->a);
		ft_memmove(data->a, data->a + 1, (data->size_a - 1) * sizeof(int));
		*(data->a + (data->size_a - 1)) = tmp;
	}
	else if (stack == STACK_B && data->b)
	{
		tmp = *(data->b);
		ft_memmove(data->b - (data->size_b - 2), data->b - (data->size_b - 1), (data->size_b - 1) * sizeof(int));
		*(data->b - (data->size_b  - 1)) = tmp;
	}
	
	if(mode == DISPLAY)
		print_move(R, stack);
	return (OK);    
}

int rev_rotate(t_global_data *data, int stack, int mode)
{
	int tmp;

	if (!data || (stack != STACK_A && stack != STACK_B))
		return (NO_MOVE);
	if (stack == STACK_A && data->a)
	{
		tmp = *(data->a + data->size_a - 1);
		ft_memmove(data->a + 1, data->a, (data->size_a  - 1) * sizeof(int));
		*(data->a) = tmp;
	}
	else if (stack == STACK_B && data->b)
	{
		tmp = *(data->b - (data->size_b - 1));
		ft_memmove(data->b - (data->size_b - 1), data->b - (data->size_b - 2), (data->size_b - 1) * sizeof(int));
		*(data->b) = tmp;
	}
	
	if(mode == DISPLAY)
		print_move(RV, stack);
	return (OK);    
}

int double_rotation(t_global_data *data, int move, int mode)
{
	if (move != RR && move != RRR)
		return (NO_MOVE);
	if (move == RR)
	{
		rotate(data, STACK_A, NO_DISPLAY);
		rotate(data, STACK_B, NO_DISPLAY);
		if (mode == DISPLAY)
			print_move(RR, A_AND_B);
	}
	else if (move == RRR)
	{
		rev_rotate(data, STACK_A, NO_DISPLAY);
		rev_rotate(data, STACK_B, NO_DISPLAY);
		if (mode == DISPLAY)
			print_move(RRR, A_AND_B);
	}
	return (OK);
}

