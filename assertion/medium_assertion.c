/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   On√n_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:33:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 19:54:11 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void place_in_stack_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int arr5[6] = {5 ,4 ,6, 3, 1, 2};
    
    data.a = &arr5[3];
    data.b = &arr5[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr5[0];
    data.end = &arr5[5];
    
    assert(place_int_stack(&data, STACK_A, *(data.a)) == 3);
    assert(place_int_stack(&data, STACK_A, *(data.a + 1)) == 1);
    assert(place_int_stack(&data, STACK_A, *(data.a + 2)) == 2);

    assert(place_int_stack(&data, STACK_B, *(data.b)) == 3);
    assert(place_int_stack(&data, STACK_B, *(data.b - 1)) == 1);
    assert(place_int_stack(&data, STACK_B, *(data.b - 2)) == 2);

    int arr6[9] = {50, 78, 7, -125 ,40 , -6, 310, 1, 2};
    data.a = &arr6[4];
    data.b = &arr6[3];
    data.size_a = 5;
    data.size_b = 4;
    data.start = &arr6[0];
    data.end = &arr6[8];
    assert(place_int_stack(&data, STACK_A, *(data.a)) == 4);
    assert(place_int_stack(&data, STACK_A, *(data.a + 1)) == 1);
    assert(place_int_stack(&data, STACK_A, *(data.a + 2)) == 5);
    assert(place_int_stack(&data, STACK_A, *(data.a + 3)) == 2);
    assert(place_int_stack(&data, STACK_A, *(data.a + 4)) == 3);

    assert(place_int_stack(&data, STACK_B, *(data.b)) == 1);
    assert(place_int_stack(&data, STACK_B, *(data.b - 1)) == 2);
    assert(place_int_stack(&data, STACK_B, *(data.b - 2)) == 4);
    assert(place_int_stack(&data, STACK_B, *(data.b - 3)) == 3);

    ASSERT_END(__func__);
}


void best_move_assert(void)
{
    t_best_move best;
    t_global_data data;
    int range[2];
    int nb_range;
    
    /*                6   7  4    1   5     2   8    3  4*/
    char *arr6[] = {"50, 78, 7, -125 ,40 , -6, 310,  1, 2", NULL};
    
    assert(init_global_data(arr6, &data) == OK);

    nb_range = data.size_a / RANGE_SIZE;
    range[1] = (RANGE_SIZE * nb_range);
    range[0] =  (range[1] - RANGE_SIZE) + 1;
    best = best_move(data, range);
    assert(range[0] == 6 && range[1] == 10);
    assert(best.number == 6);
    assert(best.number == 0);
    

}

void five_value_in_full_stack(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    char *str[] = {"1 2 3 4 5 10 9 8 7 6",NULL};

    assert(init_global_data(str, &data) == OK);
    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    display_stack(&data, STACK_B);
    five_values(&data, STACK_B);
    display_stack(&data, STACK_B);
    ASSERT_END(__func__);

}

void middle_algo_assert(void)
{
    //place_in_stack_assert();
    five_value_in_full_stack();
    
}