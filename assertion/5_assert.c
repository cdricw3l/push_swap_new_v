/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_assert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:39:26 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/28 07:39:49 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void five_value_assert()
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    //char *l1[] = {"10 5 -2 4001 311", NULL};
    char *l2[] = {"10 5 -2 4001 311", NULL};
    // assert(init_global_data(l1, &data) == OK);
    // five_values(&data, STACK_A);
    // assert(ft_is_sort(&data, STACK_A));
    
    assert(init_global_data(l2, &data) == OK);
    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    display_stack(&data, STACK_B);
    five_values(&data, STACK_B);
    display_stack(&data, STACK_B);
    assert(ft_is_sort(&data, STACK_B));
    ASSERT_END(__func__);
}