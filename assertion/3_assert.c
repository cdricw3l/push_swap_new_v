/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_assert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 07:37:55 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/28 07:38:44 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void three_value_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    /* case 0 */
    int arr0[6] = {1, 2, 3, 4, 5, 6};
    
    data.a = &arr0[3];
    data.b = &arr0[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr0[0];
    data.end = &arr0[5];
    
    assert(three_values(&data, STACK_A) == NO_MOVE);
    assert(three_values(&data, STACK_B) == NO_MOVE);
    
    int arr1[6] = {2, 1, 3, 6, 5, 4};

    data.a = &arr1[3];
    data.b = &arr1[2];
    data.start = &arr1[0];
    data.end = &arr1[5];

    display_stack(&data, STACK_A);
    assert(three_values(&data, STACK_A) == OK);
    assert(three_values(&data, STACK_B) == OK);
    display_stack(&data, STACK_A);
    
    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    /* case 1 */
    int arr2[6] = {5 ,6 ,4, 1, 3, 2};
    data.a = &arr2[3];
    data.b = &arr2[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr2[0];
    data.end = &arr2[5];

    assert(three_values(&data, STACK_A) == OK);
    assert(three_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    NL;
   
    // /* case 2 */
    int arr3[6] = {6 ,4 ,5, 2, 1, 3};
    data.a = &arr3[3];
    data.b = &arr3[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr3[0];
    data.end = &arr3[5];

    assert(three_values(&data, STACK_A) == OK);

    assert(three_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));

    NL;
    
    /* case 3 */
    int arr4[6] = {4 ,6 ,5, 2, 3, 1};
    data.a = &arr4[3];
    data.b = &arr4[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr4[0];
    data.end = &arr4[5];

    assert(three_values(&data, STACK_A) == OK);
    display_stack(&data, STACK_B);
    three_values(&data, STACK_B);
    display_stack(&data, STACK_B);
    //assert(three_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    NL;

    /* case 4 */
    int arr5[6] = {5 ,4 ,6, 3, 1, 2};
    data.a = &arr5[3];
    data.b = &arr5[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr5[0];
    data.end = &arr5[5];

    assert(three_values(&data, STACK_A) == OK);
    assert(three_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    NL;
    
    /* case 5 */
    int arr6[6] = {4 ,5 ,6, 3, 2, 1};
    data.a = &arr6[3];
    data.b = &arr6[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr6[0];
    data.end = &arr6[5];

    assert(three_values(&data, STACK_A) == OK);
    assert(three_values(&data, STACK_B) == NO_MOVE);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    ASSERT_END(__func__);
}