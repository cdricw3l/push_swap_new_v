/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_range_assert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:51:09 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/28 10:40:00 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"



int check_range_assert(int ranges[1024][2], int values, int size)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    while (i < size)
    {
        count += (ranges[i][1] - ranges[i][0]) + 1;
        i++;
    }
    assert(count == values);
    return (OK);
}



void generate_range_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    int ranges[1024][2];
    int ranges_size;
    int total_value;

    total_value = 100;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 103;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 104;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 105;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 65;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 4;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 2;
    ranges_size = generate_range(ranges, total_value);
    check_range_assert(ranges, total_value, ranges_size);
    
    total_value = 1;
    ranges_size = generate_range(ranges, total_value);
    assert(ranges_size == ERR);
    
    total_value = 0;
    ranges_size = generate_range(ranges, total_value);
    assert(ranges_size == ERR);
    ASSERT_END(__func__);
}