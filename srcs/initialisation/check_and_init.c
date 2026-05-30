/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:34:24 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/30 10:22:36 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_digit(char *str)
{
	char	*ptr;

	ptr = str;
	if (!ptr || !*ptr)
		return (ERR);
	if (*ptr == MINUS || *ptr == PLUS)
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
			return (ERR);
		ptr++;
	}
	return (OK);
}

int	check_args(char **argv, t_global_data *data)
{
	size_t	i;
	size_t	j;
	char	**split;
	int		count;

	if (!argv)
		return (ERR);
	i = 0;
	count = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], SPACE);
		if (!split)
			return (ERR);
		j = 0;
		if (i == 0)
			data->algo = get_complexity(split[0]);
		if (i == 0 && data->algo != NONE)
			j++;
		while (split[j])
		{
			if (check_digit(split[j]) == ERR
				|| ft_atoi_long_long(split[j]) > INT_MAX
				|| ft_atoi_long_long(split[j]) < INT_MIN)
			{
				data->algo = NONE;
				ft_split_clean(&split);
				write(STDOUT_FILENO, "Error size value\n", 17);
				return (ERR);
			}
			j++;
			count++;
		}
		ft_split_clean(&split);
		i++;
	}
	data->size_a = count;
	data->size_b = 0;
	return (OK);
}

int	create_stack(char **argv, t_global_data *data)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**split;

	k = 0;
	j = 0;
	while (argv[k])
	{
		split = ft_split(argv[k], SPACE);
		if (!split)
			return (ERR);
		i = 0;
		if (k == 0 && data->algo != NONE)
			i++;
		while (split[i])
			data->stack[j++] = ft_atoi_long_long(split[i++]);
		ft_split_clean(&split);
		k++;
	}
	data->a = data->stack;
	data->start = data->stack;
	data->end = &data->stack[data->size_a - 1];
	data->b = NULL;
	return (OK);
}

int	check_duplicate(t_global_data *data)
{
	int	i;
	int	j;
	char *value;

	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->stack[i] == data->stack[j])
			{
				value = ft_itoa(data->stack[i]);
				write(STDOUT_FILENO, "Error dupplicate value: ", 23);
				ft_putendl_fd(STDOUT_FILENO, value);
				free(value);
				return (ERR);
			}
			j++;
		}
		i++;
	}
	return (OK);
}

int	init_global_data(char **argv, t_global_data *data)
{
	if (!argv || !*argv)
		return (ERR);
	if (check_args(argv, data) == ERR)
	{
		write(STDOUT_FILENO, "Error check arg\n", 16);
		return (ERR);
	}
	if (create_stack(argv, data) == ERR)
	{
		write(STDOUT_FILENO, "Error stack creation\n", 21);
		return (ERR);
	}
	if (check_duplicate(data) == ERR)
	{
		write(STDOUT_FILENO, "Error dupplicate value\n", 23);
		return (ERR);
	}
	data->disorder = compute_disorder(data);
	return (OK);
}
