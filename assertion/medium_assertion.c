/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_assertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:33:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 23:18:19 by cebouhad         ###   ########.fr       */
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

    char *s[] = {"8 4 2 1 7 14 5 0 11 10 3 19 15 13 20 17 6 18 16 12" , NULL};
    assert(init_global_data(s, &data) == OK);
    int place = place_int_stack(&data, STACK_A, *(data.a + 18));
    int range[LIMIT][2];
     generate_range(range, data.size_a);
    printf("value: %d la place %d in range %d to %d\n", *(data.a + 18), place , range[1][0], range[1][1]);
    assert(place == 16);
    

    assert( place >= range[1][0] && place <= range[1][1]);
    

    ASSERT_END(__func__);
}


void display_range(int ranges[1024][2], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("range %d: [end]: %d [start] %d\n", i, ranges[i][1], ranges[i][0]);
        i++;
    }
}

void display_best_move(t_best_move move, int range[2])
{
    printf("best move:");
    if(move.move == rev_rotate)
        printf("rev_rotate\n");
    if(move.move == rotate)
        printf("rotate\n");
    printf("value: %d\n", move.value);
    printf("cost: %d\n", move.number);
    printf("in range %d to %d\n", range[0], range[1]);
    NL;
}

void best_move_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    t_best_move *best;

    char *s[] = {"8 4 2 1 7 14 5 11 10 3 19 15 13 20 17 6 18 16 12 9" , NULL};
    assert(init_global_data(s, &data) == OK);
    int range[LIMIT][2];
    int i;
    int nb = generate_range(range, data.size_a);
    i = 0;
    display_range(range, nb);

    // best = best_move(&data, range[1]);
    // display_stack(&data, STACK_B);
    // move(&data, STACK_A,best->move,best->number);
    // push(&data, STACK_A, STACK_B, NO_DISPLAY);
    // display_stack(&data, STACK_B);
    // best = best_move(&data, range[1]);
    // printf(GREEN"svalue %d in range: %d to %d"RESET"\n", best->value ,range[1][1], range[1][0]);

    // assert(place_int_stack(&data, STACK_A, best->value) >= range[1][0] && place_int_stack(&data, STACK_A, best->value) <= range[1][1]);

    // best = best_move(&data, range[1]);

    while (i < nb)
    {
        best = best_move(&data, range[i]);
        while(best != NULL)
        {
            move(&data, STACK_A, best->move, best->number);
            push(&data, STACK_A, STACK_B, NO_DISPLAY);
            best = best_move(&data, range[i]);
        }
        
        five_values(&data, STACK_B);


        at_beginning(&data, STACK_A, immediat_superior(&data, STACK_A, data.b));
        
        while (data.b)
            push(&data, STACK_B, STACK_A, NO_DISPLAY);
        i++;
    }
    display_stack(&data, STACK_B);
    display_stack(&data, STACK_A);
    ASSERT_END(__func__);
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
    //five_value_in_full_stack();
    best_move_assert();
    
}