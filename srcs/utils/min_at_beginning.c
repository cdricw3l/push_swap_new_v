/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_at_beginning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:27:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 16:48:04 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int get_born(long born[2], t_global_data *data, int stack)
{
	int		*smalest;

	smalest = get_smalest_value(data, stack);
	if (!smalest || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if (stack == STACK_A)
	{
		born[LEFT] = (((long)data->a - (long)smalest) / 4);
		born[RIGHT] = (((long)(data->a + (data->size_a - 1)) - (long)smalest) / sizeof(int)) + 1;
		if (smalest == data->a)
			return(NO_MOVE);
	}
	else if (stack == STACK_B)
	{
		born[LEFT]  = (((long)data->b - (long)smalest) / 4);
		born[RIGHT]  = (((long)(data->b - (data->size_b - 1)) - (long)smalest) / sizeof(int)) + 1;
		if (smalest == data->b)
			return(NO_MOVE);
	}
	return (OK);
}

int	min_at_beginning(t_global_data *data, int stack)
{
	long 	born[2];
	int 	status;

	status = get_born(born, data, stack);
	if(status == ERR)
		return (ERR);
	else if(status == NO_MOVE)
		return (NO_MOVE);
	if (born[LEFT] < 0)
		born[LEFT] = born[LEFT] *-1;
	if (born[RIGHT] < 0)
		born[RIGHT] = born[RIGHT] *-1;
	if (born[LEFT] > born[RIGHT] || born[LEFT] == born[RIGHT])
		while (born[RIGHT] > 0)
		{
			rotate(data, stack, DISPLAY);
			born[RIGHT]--;
		}
	else if(born[RIGHT] > born[LEFT])
		while (born[LEFT] > 0)
		{
			rev_rotate(data, stack, DISPLAY);
			born[LEFT]--;
		}
	return (OK);
}

int *get_smalest_value(t_global_data *data, int stack)
{
	int *arr;
	int *p1;
	int i = INT_MAX;

	p1 = &i;
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if(*arr < *p1)
				p1 = arr;
			arr++;
		}
	}
	else if(stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if(*arr < *p1)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}


