/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:32:29 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/26 15:03:48 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_complexity(char *arg)
{
	if (ft_strncmp(arg, "--simple",
			ft_strlen_longest("--simple", arg)) == OK)
		return (SIMPLE);
	else if (ft_strncmp(arg, "--medium",
			ft_strlen_longest("--medium", arg)) == OK)
		return (MEDIUM);
	else if (ft_strncmp(arg, "--complex",
			ft_strlen_longest("--complex", arg)) == OK)
		return (COMPLEX);
	else if (ft_strncmp(arg, "--adaptive",
			ft_strlen_longest("--adaptive", arg)) == OK)
		return (ADAPTATIVE);
	return (NONE);
}

void	ft_swap(int *p1, int *p2)
{
	int	tmp;

	if (!p1 || !p2)
		return ;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

float	compute_disorder(t_global_data *data)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			total_pairs++;
			if (data->stack[i] > data->stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
#include <assert.h>

int ft_is_sort(t_global_data *data, int stack)
{
	int				i;
	t_stack_data	stk;
	
	if(get_stack_data(*data, stack, &stk) == ERR)
		return (-1);
	i = 0;
	while (i < stk.len - 1)
	{
		if(stack == STACK_A)
		{
			if(*(stk.arr) > *(stk.arr + 1))
				return (0);
			stk.arr++;
		}
		else if (stack == STACK_B)
		{
			if(*(stk.arr) > *(stk.arr - 1))
				return (0);
			stk.arr--;
		}
		i++;
	}
	return (1);
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

int get_stack_data(t_global_data data, int stack, t_stack_data *stk)
{
	if(stack == STACK_A)
	{
		stk->arr = data.a;
		stk->len = data.size_a;
	}
	else if(stack == STACK_B)
	{
		stk->arr = data.b;
		stk->len = data.size_b;
	}
	else
		return (ERR);
	return (OK);
}

/*

    rotate -> the last become the first
    rev_rotate <- the first become the last
*/
int	min_at_beginning(t_global_data *data, int stack)
{
	long	left;
	long	right;
	int		*smalest;

	smalest = get_smalest_value(data, stack);
	if (stack == STACK_A)
	{
		left = (((long)data->a - (long)smalest) / 4);
		right = (((long)(data->a + (data->size_a - 1)) - (long)smalest) / sizeof(int)) + 1;
		if (smalest == data->b)
			return(NO_MOVE);
	}
	else if (stack == STACK_B)
	{
		left = (((long)data->b - (long)smalest) / 4);
		right = (((long)(data->b - (data->size_b - 1)) - (long)smalest) / sizeof(int)) + 1;
		if (smalest == data->b)
			return(NO_MOVE);
	}
	else
		return (NO_MOVE);
	if (left < 0)
		left = left *-1;
	if (right < 0)
		right = right *-1;
	if (left > right || left == right)
		while (right > 0)
		{
			rotate(data, stack, DISPLAY);
			right--;
		}
	else if(right > left)
		while (left > 0)
		{
			rev_rotate(data, stack, DISPLAY);
			left--;
		}
	return (OK);
}
