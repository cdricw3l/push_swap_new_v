/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/21 14:46:34 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int check_args(char **argv, t_data *data);
int check_digit(char *str);
int get_complexity(char *arg);
int check_args(char **argv, t_data *data);
int create_stack(char **argv, t_data *data);
int check_duplicate(t_data data);
int init_data(char **argv, t_data *data);
void display_data(t_data data);
int push(t_data *data, int src, int dst);
int swap(t_data *data, int stack);
void display_stack(t_data *data, int stack);

void check_digit_assert(void)
{
    ASSERT_START(__func__);
    assert(check_digit("100") == OK);
    assert(check_digit("42") == OK);
    assert(check_digit("-42") == OK);
    assert(check_digit("0") == OK);
    assert(check_digit("+150") == OK);
    assert(check_digit("+1a50") == ERR);
    assert(check_digit("a50") == ERR);
    assert(check_digit("50a") == ERR);
    assert(check_digit("") == ERR);
    ASSERT_END(__func__);
}

void get_complexity_assert(void)
{
    ASSERT_START(__func__);
    assert(get_complexity("--medium") == MEDIUM);
    assert(get_complexity("--simple") == SIMPLE);
    assert(get_complexity("--simple10") == NONE);
    assert(get_complexity("--complex") == COMPLEX);
    assert(get_complexity("--adaptive") == ADAPTATIVE);
    assert(get_complexity("--") == NONE);
    assert(get_complexity("--hello") == NONE);
    assert(get_complexity("") == NONE);
    assert(get_complexity("hello berlin") == NONE);
    ASSERT_END(__func__);
}

void atoi_long_long_assert(void)
{
    ASSERT_START(__func__);
    assert(ft_atoi_long_long("0") == 0);
    assert(ft_atoi_long_long("2147483647") == INT_MAX);
    assert(ft_atoi_long_long("2147483648") == 2147483648);
    assert(ft_atoi_long_long("-2147483648") == INT_MIN);
    assert(ft_atoi_long_long("-9223372036854775808") == LLONG_MIN);
    assert(ft_atoi_long_long("9223372036854775807") == LLONG_MAX);
    assert(ft_atoi_long_long("922337203s6854775807") == 922337203);
    assert(ft_atoi_long_long("s9223372036854775807") == 0);
    assert(ft_atoi_long_long("9223372036854775807a") == LLONG_MAX);
    assert(ft_atoi_long_long("922337203685477580a7") == 922337203685477580);
    ASSERT_END(__func__);
}

void check_arg_assert(void)
{
    ASSERT_START(__func__);
    char **split;
    t_data data;
    int i;
    split = malloc(sizeof(char *) * 6);
    assert(split);

    split[0] = ft_strdup("--simple");
    split[1] = ft_strdup("10 32 21 12 7 0 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("10 32 21 12 7 0 -10");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10 -2147483648 2147483647 0");
    split[5] = NULL;
    assert(check_args(split, &data) == OK);
    assert(data.algo == SIMPLE);
    assert(data.size_a == 25);
    i = 0;
    while (split[i])
        free(split[i++]);
    split[0] = ft_strdup("--simple");
    split[1] = ft_strdup("10 32 21 12 7 0 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("10 32 21 12 7 0 -10");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10 -2147483649 2147483647 0");
    split[5] = NULL;
    assert(check_args(split, &data) == ERR && data.algo == NONE);
    i = 0;
    while (split[i])
        free(split[i++]);
    split[0] = ft_strdup("10");
    split[1] = ft_strdup("10 32 21 12 7 0 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("10 32 21 12 7 0 -10");
    split[3] = ft_strdup("--simple");
    split[4] = ft_strdup("-10 -2147483649 2147483647 0");
    split[5] = NULL;
    assert(check_args(split, &data) == ERR && data.algo == NONE);
    i = 0;
    while (split[i])
        free(split[i++]);
    split[0] = ft_strdup("10");
    split[1] = ft_strdup("10");
    split[2] = ft_strdup("10");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10");
    split[5] = NULL;
    i = 0;
    while (split[i])
        free(split[i++]);
    split[0] = ft_strdup("--complex");
    split[1] = ft_strdup("10");
    split[2] = ft_strdup("10 100 12 13");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10");
    split[5] = NULL;
    assert(check_args(split, &data) == OK && data.algo == COMPLEX && data.size_a == 7);
    ft_split_clean(&split);
    ASSERT_END(__func__);
}

void init_stack_assert(void)
{
    ASSERT_START(__func__);
    char **split;
    t_data data;

    split = malloc(sizeof(char *) * 6);
    assert(split);
    split[0] = ft_strdup("--simple");
    split[1] = ft_strdup("10 32 21 12 7 0 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("10 32 21 12 7 0 -10");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10 -2147483648 2147483647 0");
    split[5] = NULL;
    assert(check_args(split, &data) == OK);
    assert(data.size_a !=  ERR);
    assert(create_stack(&split[0], &data) == OK);
    assert(data.stack);
    data.a = data.stack;
    data.b = NULL;
    assert(*(data.a) == 10);
    assert(data.stack[data.size_a - 1] == 0);
    assert(data.stack[data.size_a - 2] == INT_MAX);
    assert(data.stack[data.size_a - 3] == INT_MIN);
    ft_split_clean(&split);
    assert(data.algo == SIMPLE);
    ASSERT_END(__func__);
}

void check_dupplicate_assert(void)
{
    ASSERT_START(__func__);
    char **split;
    t_data data;

    /*
        check whith dupplicate value
    */

    split = malloc(sizeof(char *) * 6);
    assert(split);
    split[0] = ft_strdup("100");
    split[1] = ft_strdup("10 320 21 12 7 0 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("10 32 21 12 7 0 -10");
    split[3] = ft_strdup("10");
    split[4] = ft_strdup("-10 -2147483648 2147483647 0");
    split[5] = NULL;
    assert(check_args(split, &data) == OK);
    /* check size stack a*/
    assert(data.size_a !=  ERR && data.algo == NONE);
    assert(data.size_a == 26);
    /* if first arg is algo type, send argv[1](argv[2] initialement) else argv[0](argv[1] initialement) */
    if(data.algo == NONE)
        assert(create_stack(&split[0], &data) == OK);
    else
        assert(create_stack(&split[1], &data) == OK);
    data.a = data.stack;
    data.b = NULL;
    /* check value copy in stack.data */
    assert(*(data.a + 1) == 10);
    assert(data.stack[data.size_a - 1] == 0);
    assert(data.stack[data.size_a - 2] == INT_MAX);
    assert(data.stack[data.size_a - 3] == INT_MIN);
    ft_split_clean(&split);
    
    /* 
        check duplicate value in stack.data
    */
    assert(check_duplicate(data) == ERR);
    /* check whitout dupplicate value */
    split = malloc(sizeof(char *) * 6);
    assert(split);
    split[0] = ft_strdup("100");
    split[1] = ft_strdup("30 320 210 120 70 1110 -10 35 21 16 55 78 65");
    split[2] = ft_strdup("20 32 19 12 7 0 -1000");
    split[3] = ft_strdup("1005");
    split[4] = ft_strdup("-2556 -2147483648 2147483647 64");
    split[5] = NULL;
    assert(check_args(split, &data) == OK);
    /* check size stack a*/
    assert(data.size_a !=  ERR && data.algo == NONE);
    assert(data.size_a == 26);
    /* if first arg is algo type, send argv[1](argv[2] initialement) else argv[0](argv[1] initialement) */
    if(data.algo == NONE)
        assert(create_stack(&split[0], &data) == OK);
    else
        assert(create_stack(&split[1], &data) == OK);
    data.a = data.stack;
    data.b = NULL;
    /* check value copy in stack.data */
    assert(*(data.a + 1) == 30);
    assert(data.stack[data.size_a - 1] == 64);
    assert(data.stack[data.size_a - 2] == INT_MAX);
    assert(data.stack[data.size_a - 3] == INT_MIN);
    ft_split_clean(&split);
    /* check duplicate value in stack.data */
    assert(check_duplicate(data) == OK);
    ASSERT_END(__func__);
}

void init_data_assert(char **argv)
{
    ASSERT_START(__func__);
    t_data data;
    char **split;
    int split_len;
    
    split  = ft_split(argv[0], SPACE);
    assert(init_data(argv, &data) == OK);
    assert(data.a == data.stack);
    assert(data.b == NULL);
    if(data.algo == NONE)
        split_len = (int)ft_split_len(split);
    else
        split_len = (int)ft_split_len(split) - 1;
    assert(data.size_a == split_len);
    assert(data.size_b == 0);
    ft_split_clean(&split);
    ASSERT_END(__func__);
}

void push_assert(void)
{
    ASSERT_START(__func__);
    t_data data;
    char *str[] = {"10 12 88 74 7 9 77", NULL};
    assert(init_data((char **)str, &data) == OK);
    int status;
    
    while (data.size_a > 0)
    {
        status = push(&data, STACK_A, STACK_B);
        display_stack(&data, STACK_B);
        display_stack(&data, STACK_A);
        assert(status == OK);
        NL;
    }
    status = push(&data, STACK_A, STACK_B);
    assert(status == NO_MOVE);
    assert(push(&data, STACK_A, STACK_B)  == NO_MOVE);   
    assert(push(&data, STACK_A, STACK_B)  == NO_MOVE);   
    assert(push(&data, STACK_A, STACK_B)  == NO_MOVE);
    while (data.size_b > 0)
    {
        
        status = push(&data, STACK_B, STACK_A);
        display_stack(&data, STACK_B);
        display_stack(&data, STACK_A);
        assert(status == OK);
        NL;
    }
    status = push(&data, STACK_B, STACK_A);
    assert(status == NO_MOVE);
    assert(push(&data, STACK_B, STACK_A)  == NO_MOVE);   
    assert(push(&data, STACK_B, STACK_A)  == NO_MOVE);   
    assert(push(&data, STACK_B, STACK_A)  == NO_MOVE); 
    
    ASSERT_END(__func__);
}

void swap_assert(void)
{
    ASSERT_START(__func__);
    t_data data;
    char *str[] = {"10 12 88 74 7 9 77", NULL};
    
    assert(init_data((char **)str, &data) == OK);
    assert(push(&data, STACK_A, STACK_B) == OK);
    assert(push(&data, STACK_A, STACK_B) == OK);
    assert(push(&data, STACK_A, STACK_B) == OK);
    assert(swap(&data, STACK_A) == OK);
    assert(*data.a == 7);
    assert(*(data.a + 1) == 74);
    assert(swap(&data, STACK_B) == OK);
    assert(*data.b == 12);
    assert(*(data.b - 1) == 88);
    assert(swap(&data, STACK_A) == OK);
    assert(swap(&data, STACK_B) == OK);
    assert(swap(NULL, STACK_A) == NO_MOVE);
    assert(swap(NULL, STACK_B) == NO_MOVE);
    assert(push(&data, STACK_B, STACK_A) == OK);
    assert(push(&data, STACK_B, STACK_A) == OK);
    assert(push(&data, STACK_B, STACK_A) == OK);
    assert(data.size_b == 0);
    assert(*(data.a) == 10);
    assert(swap(&data, STACK_B) ==  NO_MOVE);
    ASSERT_END(__func__);
}

void rr_assert(void)
{
    t_data data;
    int arr[] = {10, 22, 1101, 7, 12, 32};

    data.a = &arr[3];
    data.b = &arr[2];
    data.size_a = 3;
    data.size_b = 3;

    display_stack(&data, STACK_A);
    display_stack(&data, STACK_B);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    check_digit_assert();
    get_complexity_assert();
    atoi_long_long_assert();
    check_arg_assert();
    init_stack_assert();
    check_dupplicate_assert();
    init_data_assert(&argv[1]);
    push_assert();
    swap_assert();
    return (0);
}