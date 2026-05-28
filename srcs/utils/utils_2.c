/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 09:51:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 16:18:40 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int generate_range(int ranges[1024][2], int total_size)
{
    int base;
    int range_start;
    int range_end;
    int i;

    if (total_size > LIMIT || total_size < 2)
        return (ERR);
    range_start = (total_size - RANGE_SIZE) + 1;
    range_end = total_size;
    base = total_size / RANGE_SIZE;
    if (total_size % RANGE_SIZE)
        base += 1;
    i = 0;
    while (i < base)
    {
        ranges[i][0] = range_start;
        ranges[i][1] = range_end;
        range_start -= RANGE_SIZE;
        range_end -= RANGE_SIZE;
        if(i == base - 1 && ranges[i][0] <= 0)
            ranges[i][0] = 1;
        i++;
    }
    return (i);
}

int *bigest_value(t_global_data *data, int stack)
{
	int *arr;
	int *p1;
	int i = INT_MIN;

	p1 = &i;
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if(*arr > *p1)
				p1 = arr;
			arr++;
		}
	}
	else if(stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if(*arr > *p1)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}

int *smalest_value(t_global_data *data, int stack)
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


int *immediat_superior(t_global_data *data, int stack, int *value)
{
	int *arr;
	int *p1;
	int i = INT_MAX;

	p1 = &i;
	if (bigest_value(data, stack) == value)
		return (value);
	if (stack == STACK_A)
	{
		arr = data->a;
		while (arr <= data->end)
		{
			if(*arr < *p1 && *arr > *value)
				p1 = arr;
			arr++;
		}
	}
	else if(stack == STACK_B)
	{
		arr = data->b;
		while (arr >= data->start)
		{
			if(*arr < *p1 && *arr > *value)
				p1 = arr;
			arr--;
		}
	}
	return (p1);
}