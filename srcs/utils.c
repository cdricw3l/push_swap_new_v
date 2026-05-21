/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:32:29 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/21 19:14:51 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_swap(int *p1, int *p2)
{
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int compute_disorder(t_data *data)
{
    int mistakes;
    int total_pairs;
    int i;
    int j;

    i = 0;
    mistakes = 0;
    total_pairs = data->size_a;
    while (i < data->size_a)
    {
        j = i + 1;
        while (j < data->size_a)
        {
            if (data->stack[i] > data->stack[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return (mistakes / total_pairs);
}