/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:32:29 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/25 17:21:33 by cebouhad         ###   ########.fr       */
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
int ft_is_sort(t_global_data *data)
{
	int i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if(data->stack[i] > data->stack[i + 1])
			return (0);
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


int  synchronise_list(t_global_data *data, int stack)
{
	int 			*smalest;
	t_stack_data	stk;

	if(get_stack_data(*data, stack, &stk) == ERR)
		return (ERR);
	smalest = get_smalest_value(data, STACK_A);
	printf("borne - : %p borne + : %p smalest: %p", data->start, data->end, smalest);
	return (OK);
}
