/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 09:44:49 by mabrugge          #+#    #+#             */
/*   Updated: 2026/05/27 14:06:02 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int selection_sort(t_global_data *data)
{
    while(data->size_a > 3)
    {
        at_beginning(data, STACK_A, smalest_value);
        push(data, STACK_A, STACK_B, DISPLAY);
    }
    three_values(data, STACK_A);
    while(data->b)
        push(data, STACK_B, STACK_A, DISPLAY);
    return (OK);
}
