/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/27 09:55:04 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int         place_int_stack(t_global_data *data, int stack, int value);
t_best_move best_move(t_global_data data, int range[2]);
/*

    rotate -> the last become the first
    rev_rotate <- the first become the last
*/

/*
    case 0: 3 4 5; 
    case 1: 3 5 4; 
    case 2: 4 3 5;

    case 3: 4 5 3;
    case 4: 5 3 4; 
    case 5: 5 4 3
*/

void three_value_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    /* case 0 */
    int arr1[6] = {3, 2, 1, 4, 5, 6};
    
    data.a = &arr1[3];
    data.b = &arr1[2];
    data.size_a = 3;
    data.size_b = 3;
    data.start = &arr1[0];
    data.end = &arr1[5];
    
    assert(three_values(&data, STACK_A) == NO_MOVE);
    assert(three_values(&data, STACK_B) == NO_MOVE);

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
    assert(three_values(&data, STACK_B) == OK);

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
    assert(three_values(&data, STACK_B) == OK);

    assert(ft_is_sort(&data, STACK_A));
    assert(ft_is_sort(&data, STACK_B));
    
    ASSERT_END(__func__);
}

void five_value_assert(char **argv)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;

    assert(argv[1]);
    assert(init_global_data(&argv[1], &data) == OK);
    if(data.size_a != 5)
    {
        printf(RED"ERREUR: la liste a une taille differente de 5"RESET"\n");
        return ;
    }
    five_values(&data, STACK_A, STACK_B);
    assert(ft_is_sort(&data, STACK_A));
    ASSERT_END(__func__);
}

void max_at_beg_asser(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int biggest;
    char *l1[] = {"10 5 -2 4001 311", NULL};
    char *l2[] = {"1 -5 20 40 3", NULL};
    char *l3[] = {"1 -5 20 40 3", NULL};
    char *l4[] = {"1 5 -20 40 3 0 78 44 58", NULL};
    char *l5[] = {"1 5 -20 -40 3 220 31 7 88 22", NULL};

    assert(init_global_data(l1, &data) == OK);
    while (data.a)
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
    assert(data.size_a == 0);
    display_stack(&data, STACK_B);
    assert(at_beginning(&data, STACK_B, get_bigest_value) == OK);
    assert(at_beginning(&data, STACK_B, get_bigest_value) == NO_MOVE);
    while (data.b)
    {
        biggest = *get_bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, get_bigest_value);
        assert(biggest == *data.b);
        push(&data,STACK_B, STACK_A, NO_DISPLAY);
    }
    assert(ft_is_sort(&data, STACK_A));
    free(data.stack);
    
    assert(init_global_data(l2, &data) == OK);
    biggest = *get_bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_B, get_bigest_value);
    assert(biggest == *(data.a));
    free(data.stack);
    
    assert(init_global_data(l3, &data) == OK);
    biggest = *get_bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_B, get_bigest_value);
    assert(biggest == *data.a);
    free(data.stack);

    assert(init_global_data(l4, &data) == OK);
    biggest = *get_bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_B, get_bigest_value);
    assert(biggest == *data.a);
    free(data.stack);
    
    assert(init_global_data(l5, &data) == OK);
    biggest = *get_bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_B, get_bigest_value);
    assert(biggest == *data.a);
    free(data.stack);


    char *l6[] = {"10 -1 32 45 7 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        biggest = *get_bigest_value(&data, STACK_A);
        at_beginning(&data, STACK_B, get_bigest_value);
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(biggest == *data.b);
    }
    while (data.b)
    {
        biggest = *get_bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, get_bigest_value);
        push(&data, STACK_B, STACK_A, NO_DISPLAY);
        assert(biggest == *data.a);
    }
    ASSERT_END(__func__);
}
void min_at_beg_asser(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int smallest;
    char *l1[] = {"1 -5 2 4 3", NULL};
    char *l2[] = {"1 -5 20 40 3", NULL};
    char *l3[] = {"1 -5 20 40 3", NULL};
    char *l4[] = {"1 5 -20 40 3 0 78 44 58", NULL};
    char *l5[] = {"1 5 -20 -40 3 220 31 7 88 22", NULL};

    assert(init_global_data(l1, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *data.a);
    free(data.stack);
    
    assert(at_beginning(&data, STACK_A, get_smalest_value) == NO_MOVE);
    assert(smallest == *data.a);
    
    assert(init_global_data(l2, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *(data.a));
    free(data.stack);
    
    assert(init_global_data(l3, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *data.a);
    free(data.stack);assert(init_global_data(l5, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *data.a);
    free(data.stack);

    assert(init_global_data(l4, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *data.a);
    free(data.stack);
    
    assert(init_global_data(l5, &data) == OK);
    smallest = *get_smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, get_smalest_value);
    assert(smallest == *data.a);
    free(data.stack);


    char *l6[] = {"10 -1 32 45 7 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        smallest = *get_smalest_value(&data, STACK_A);
        at_beginning(&data, STACK_A, get_smalest_value);
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(smallest == *data.b);
    }
    while (data.b)
    {
        smallest = *get_smalest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, get_smalest_value);
        push(&data, STACK_B, STACK_A, NO_DISPLAY);
        assert(smallest == *data.a);
    }
    ASSERT_END(__func__);
}

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



void find_best_value_of_range_assert(void)
{
    int range[2];
    t_global_data data;
    t_best_move best;
    
    //range 1 > 2 6 10 12 20
    //range 2 > 22 31 54 132 558
    char *s[] = {"132 12 10 22  31 558 54 6 78 -5", NULL};
    assert(init_global_data(s, &data) == OK);
    range[0] = 1;
    range[1] = 5;
    
    display_stack(&data, STACK_A);
    while (data.a)
    {
        best = best_move(data, range);
        while (best.number > 0)
        {
            best.move(&data, STACK_A, DISPLAY);
            best.number--;
        }
        push(&data, STACK_A, STACK_B, DISPLAY);
        if(data.size_b == range[1])
        {
            five_values(&data, STACK_B, STACK_A);
            range[0] += 5;
            range[1] += 5;
        }
    }
    display_stack(&data, STACK_B);
}

void algo_assert(char **argv)
{
    (void)argv;
    min_at_beg_asser();
    //max_at_beg_asser();
    // three_value_assert();
    // five_value_assert(argv);
    // place_in_stack_assert();
    //find_best_value_of_range_assert();
}   