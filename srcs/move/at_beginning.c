/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_beginning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:27:23 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 15:48:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long ABS(long value)
{
	if(value < 0)
		return (value * -1);
	return (value);
}


#include <assert.h>

/**
 * @brief return if the movement is cheepest to the left or to the right.
 * @param born Le premier entier.
 * @param data Le deuxième entier.
 * @param stack stack to process
 * @return OK, NO_MOVE or ERR.
 */


int get_born(long born[2], t_global_data *data, int stack, int *value)
{

	if (!value || (stack != STACK_A && stack != STACK_B))
		return (ERR);
	if (stack == STACK_A)
	{
		born[LEFT] = (((long)value - (long)data->a) / 4);
		born[RIGHT] = ABS((long)value - ((long)(data->a + (data->size_a - 1)))) / sizeof(int) + 1;
		if (value == data->a)
			return(NO_MOVE);
	}
	else if (stack == STACK_B)
	{
		born[LEFT]  = ABS(((long)value - (long) data->b) / 4);
		born[RIGHT]  = (((long)value - ((long) (data->b - (data->size_b - 1)))) / sizeof(int)) + 1;
		if (value == data->b)
			return(NO_MOVE);
	}
	return (OK);
}

int	at_beginning(t_global_data *data, int stack, int *value)
{
	long 	born[2];
	int 	status;

	status = get_born(born, data, stack, value);
	if(status == ERR)
		return (ERR);
	else if(status == NO_MOVE)
		return (NO_MOVE);
	if (born[LEFT] > born[RIGHT] || born[LEFT] == born[RIGHT])
		while (born[RIGHT] > 0)
		{
			rev_rotate(data, stack, DISPLAY);
			born[RIGHT]--;
		}
	else if(born[RIGHT] > born[LEFT])
		while (born[LEFT] > 0)
		{
			rotate(data, stack, DISPLAY);
			born[LEFT]--;
		}
	return (OK);
}


int move(t_global_data *data, int stack, int (f)(t_global_data *, int, int), int counter)
{
	int i;

	i = 0;
	if((stack != STACK_A && stack != STACK_B) || !data || !f)
		return (ERR);
	while (i < counter)
	{
		f(data, stack, DISPLAY);
		i++;
	}
	return (OK);
}