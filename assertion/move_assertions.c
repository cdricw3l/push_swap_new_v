/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_assertions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:07:31 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/28 07:48:34 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void push_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    char *str[] = {"10 12 88 74 7 9 77", NULL};
    assert(init_global_data((char **)str, &data) == OK);
    int status;
    
    while (data.size_a > 0)
    {
        status = push(&data, STACK_A, STACK_B, NO_DISPLAY);
        display_stack(&data, STACK_B);
        display_stack(&data, STACK_A);
        printf("voici status: %d\n", status);
        assert(status == OK);
        NL;
    }
    status = push(&data, STACK_A, STACK_B, NO_DISPLAY);
    assert(status == NO_MOVE);
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY)  == NO_MOVE);   
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY)  == NO_MOVE);   
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY)  == NO_MOVE);
    while (data.size_b > 0)
    {
        
        status = push(&data, STACK_B, STACK_A, NO_DISPLAY);
        display_stack(&data, STACK_B);
        display_stack(&data, STACK_A);
        assert(status == OK);
        NL;
    }
    status = push(&data, STACK_B, STACK_A, NO_DISPLAY);
    assert(status == NO_MOVE);
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY)  == NO_MOVE);   
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY)  == NO_MOVE);   
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY)  == NO_MOVE); 
    
    ASSERT_END(__func__);
}

void swap_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    char *str[] = {"10 12 88 74 7 9 77", NULL};
    
    assert(init_global_data((char **)str, &data) == OK);
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY) == OK);
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY) == OK);
    assert(push(&data, STACK_A, STACK_B, NO_DISPLAY) == OK);
    assert(swap(&data, STACK_A, NO_DISPLAY) == OK);
    assert(*data.a == 7);
    assert(*(data.a + 1) == 74);
    assert(swap(&data, STACK_B, NO_DISPLAY) == OK);
    assert(*data.b == 12);
    assert(*(data.b - 1) == 88);
    assert(swap(&data, STACK_A, NO_DISPLAY) == OK);
    assert(swap(&data, STACK_B, NO_DISPLAY) == OK);
    assert(swap(NULL, STACK_A, NO_DISPLAY) == NO_MOVE);
    assert(swap(NULL, STACK_B, NO_DISPLAY) == NO_MOVE);
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY) == OK);
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY) == OK);
    assert(push(&data, STACK_B, STACK_A, NO_DISPLAY) == OK);
    assert(data.size_b == 0);
    assert(*(data.a) == 10);
    assert(swap(&data, STACK_B, NO_DISPLAY) ==  NO_MOVE);
    ASSERT_END(__func__);
}

void rotate_short_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    
    t_global_data data;
    int i;
    int tmp;
    int arr[] = {10, 22, 1101, 7, 12, 32};

    data.a = &arr[3];
    data.b = &arr[2];
    data.start = &arr[0];
    data.end = &arr[5];
    data.size_a = 3;
    data.size_b = 3;

    i = 0;
    NL;
    display_stack(&data, STACK_A);
    display_stack(&data, STACK_B);
    NL;
    while (i < data.size_a)
    {
        tmp = *data.a;
        assert(rotate(&data, STACK_A, NO_DISPLAY) == OK);
        display_stack(&data, STACK_A);
        assert(*(data.a + (data.size_a - 1)) == tmp);
        i++;
    }
    NL;
    assert(*data.a == 7 && *(data.a + 1) == 12 && *(data.a + 2) == 32);
    i = 0;
    assert(data.size_b == 3);
    while (i < data.size_b)
    {
        tmp = *data.b;
        assert(rotate(&data, STACK_B, NO_DISPLAY) == OK);
        display_stack(&data, STACK_B);
        assert(*(data.b - (data.size_b - 1)) == tmp);
        i++;
    }
    assert(*data.b == 1101 && *(data.b - 1) == 22 && *(data.b - 2) == 10);
    NL;
    display_stack(&data, STACK_A);
    display_stack(&data, STACK_B);
    NL;
    ASSERT_END(__func__);
    
}


void rev_rotate_short_assert(void)
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int arr[] = {10, 22, 1101, 7, 12, 32};
    int i;
    int tmp;

    data.a = &arr[3];
    data.b = &arr[2];
    data.start = &arr[0];
    data.end = &arr[5];
    data.size_a = 3;
    data.size_b = 3;

    i = 0;
    while (i < data.size_a)
    {
        tmp = *(data.a);
        rev_rotate(&data,  STACK_A, NO_DISPLAY);
        assert(*(data.a +  1) == tmp);
        i++;
    }
    assert(*data.a == 7 && *(data.a + 1) == 12 && *(data.a + 2) == 32);
    i = 0;
    while (i < data.size_b)
    {
        tmp = *(data.b);
        rev_rotate(&data,  STACK_B, NO_DISPLAY);
        assert(*(data.b - 1) == tmp);
        i++;
    }
    assert(*data.b == 1101 && *(data.b - 1) == 22 && *(data.b - 2) == 10);
    ASSERT_END(__func__);
}


void rotate_push_rotate_push_assert()
{
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int i;
    int last_value;
    int first_value;
    int size_a;

    char *arg[] = {"--simple -126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631", NULL};
    assert(init_global_data(arg, &data) == OK);
    assert(data.b  == NULL);
    size_a = data.size_a;
    first_value = *(data.a);
    last_value = *(data.a + (data.size_a - 1));
    /*
        check rotation in big list for stack a 
    */
    i = 0;
    while (i < data.size_a)
    {
        rotate(&data, STACK_A, NO_DISPLAY);
        i++;
    }
    assert(*(data.a) == first_value);
    /* 
        check rev_rotation in big list for stack a
    */
    i = 0;
    while (i < data.size_a)
    {
        rev_rotate(&data, STACK_A, NO_DISPLAY);
        i++;
    }
    assert(*(data.a) == first_value);
    
    /* push everything in b */
    
    i = OK;
    while (i == OK)
        i = push(&data, STACK_A, STACK_B, NO_DISPLAY);
    
    /* 
        ensure list a is empty and data.a == NULL
    */
    assert(data.a == NULL);
    /*
        ensure the first value of stack b is the last value of stack a after pushing everything
    */
    assert(size_a == data.size_b);
    assert(*data.b == last_value);
    /*
        pour avoir le dernier element de la list b, la liaste etant inverse, il faut recuperer la valeur a data.b - (data.size_b - 1);
    */
    assert(*(data.b - (data.size_b - 1)) == first_value);
    
    /*
        check rev_rotation in big list for stack b
    */
    i = 0;
    NL;
    while (i < data.size_b)
    {
        rev_rotate(&data, STACK_B, NO_DISPLAY);
        i++;
    }
    assert(*(data.b) == last_value);
    i = 0;
    /*
        check rev_rotation in big list for stack b
    */
    while (i < data.size_b)
    {
        rotate(&data, STACK_B, NO_DISPLAY);
        i++;
    }
    assert(*(data.b) == last_value);
    ASSERT_END(__func__);
}

void double_rotation_assert(void)
{
    
    ASSERT_START(__func__, __LINE__);
    t_global_data data;
    int first_el_a;
    int first_el_b;
    int i;
    char *arg[] = {"--simple -126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631", NULL};
    assert(init_global_data(arg, &data) == OK);
    /* check if we can split the list value int two equal stack*/
    if(data.size_a % 2 != 0)
    {
        printf(RED"please create an even list of number"RESET"\n");

    }
    /* split in two equal stack */
    while (data.size_b != data.size_a)
        assert(push(&data, STACK_A, STACK_B, NO_DISPLAY) == OK);
    assert(data.size_a == data.size_b);    
    first_el_a = *(data.a);
    first_el_b = *(data.b);

    /* check for an invalide rotation */
    assert(double_rotation(&data,P, NO_DISPLAY) == NO_MOVE);
    
    /* check for single rotation */
    assert(double_rotation(&data, RR, NO_DISPLAY) == OK);
    assert(*(data.a + (data.size_a - 1)) == first_el_a);
    assert(*(data.b - (data.size_b - 1)) == first_el_b);
    /* check for single rev_rotation */
    assert(double_rotation(&data, RRR, NO_DISPLAY) == OK);
    assert(*(data.a) == first_el_a);
    assert(*(data.b) == first_el_b);
    
    i = data.size_a - 1;
    while (i >= 0)
    {
        /* check for a rotation of all the stack */
        double_rotation(&data, RR, NO_DISPLAY);
        i--;
    }
    /* is the list back at is start point */
    assert(*(data.a) == first_el_a);
    assert(*(data.b) == first_el_b);
    i = data.size_a - 1;
    while (i >= 0)
    {
        /* check for a rev_rotation of all the stack */
        double_rotation(&data, RRR, NO_DISPLAY);
        i--;
    }
    /* is the list back at is start point */
    assert(*(data.a) == first_el_a);
    assert(*(data.b) == first_el_b);
    
    ASSERT_END(__func__);
}

/*

    rotate -> the last become the first
    rev_rotate <- the first become the last
*/


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
    assert(at_beginning(&data, STACK_B, bigest_value) == OK);
    assert(at_beginning(&data, STACK_B, bigest_value) == NO_MOVE);
    while (data.b)
    {
        biggest = *bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, bigest_value);
        assert(biggest == *data.b);
        push(&data,STACK_B, STACK_A, NO_DISPLAY);
    }
    assert(ft_is_sort(&data, STACK_A));
    
    assert(init_global_data(l2, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value);
    assert(biggest == *(data.a));
    
    assert(init_global_data(l3, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value);
    assert(biggest == *data.a);

    assert(init_global_data(l4, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value);
    assert(biggest == *data.a);
    
    assert(init_global_data(l5, &data) == OK);
    biggest = *bigest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, bigest_value);
    assert(biggest == *data.a);


    char *l6[] = {"10 -1 32 45 7 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        biggest = *bigest_value(&data, STACK_A);
        at_beginning(&data, STACK_A, bigest_value);
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(biggest == *data.b);
    }
    while (data.b)
    {
        biggest = *bigest_value(&data, STACK_B);
        at_beginning(&data, STACK_B, bigest_value);
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
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *data.a);
    
    assert(at_beginning(&data, STACK_A, smalest_value) == NO_MOVE);
    assert(smallest == *data.a);
    
    assert(init_global_data(l2, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *(data.a));
    
    assert(init_global_data(l3, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *data.a);
    assert(init_global_data(l5, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *data.a);

    assert(init_global_data(l4, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *data.a);
    
    assert(init_global_data(l5, &data) == OK);
    smallest = *smalest_value(&data, STACK_A);
    at_beginning(&data, STACK_A, smalest_value);
    assert(smallest == *data.a);


    char *l6[] = {"10 -1 32 45 7 -788", NULL};
    assert(init_global_data(l6, &data) == OK);
    while (data.a)
    {
        smallest = *smalest_value(&data, STACK_A);
        at_beginning(&data, STACK_A, smalest_value);
        push(&data, STACK_A, STACK_B, NO_DISPLAY);
        assert(smallest == *data.b);
    }
    while (data.b)
    {
        smallest = *smalest_value(&data, STACK_B);
        printf("voici smalest %d\n", smallest);
        display_stack(&data, STACK_B);
        at_beginning(&data, STACK_B, smalest_value);
        display_stack(&data, STACK_B);
        push(&data, STACK_B, STACK_A, NO_DISPLAY);
        printf("voici %d\n", *data.a);
        assert(smallest == *data.a);
    }
    ASSERT_END(__func__);
}

void move_assertions(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    push_assert();
    swap_assert();
    rotate_short_assert();
    rev_rotate_short_assert();
    rotate_push_rotate_push_assert();
    double_rotation_assert();
    min_at_beg_asser();
    max_at_beg_asser();
}