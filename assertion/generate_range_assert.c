/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_range_assert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 08:51:09 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/28 09:05:30 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int generate_range(int list_size)
{
    int base;
    int reminder;
    int **ranges;
    int *arr;
    int range_start;
    int range_end;
    base = list_size / RANGE_SIZE;
    reminder = list_size % RANGE_SIZE;

    ranges = malloc(sizeof(int *) * (reminder + base + 1));
    if(!ranges)
        return (NULL);
    range_start = list_size - RANGE_SIZE;
    range_end = list_size;
    while (base > 0)
    {
        arr = malloc(sizeof(int) * 2);
        if (!arr)
    }
    



}

void generate_range_assert(void)
{
    int list_size;

    list_size = 24;

    printf("voici la base %d\n", list_size / 5);
    printf("voici le reste %d\n", list_size % 5);
}