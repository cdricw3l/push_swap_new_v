/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 09:51:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 10:16:38 by cebouhad         ###   ########.fr       */
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