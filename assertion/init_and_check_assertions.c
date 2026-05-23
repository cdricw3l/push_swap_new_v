/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check_assertions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:09:57 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/23 13:12:44 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void check_digit_assert(void)
{
    ASSERT_START(__func__, __LINE__);
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
    ASSERT_START(__func__, __LINE__);
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
    ASSERT_START(__func__, __LINE__);
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
    ASSERT_START(__func__, __LINE__);
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
    ASSERT_START(__func__, __LINE__);
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
    ASSERT_START(__func__, __LINE__);
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
    assert(check_duplicate(&data) == ERR);
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
    assert(check_duplicate(&data) == OK);
    ASSERT_END(__func__);
}

void init_data_assert(char **argv)
{
    ASSERT_START(__func__, __LINE__);
    t_data data;
    //int split_len;

    assert(init_data(argv, &data) == OK);
    assert(data.a == data.stack);
    assert(data.b == NULL);
    assert(data.size_b == 0);

    printf("voici disorder %f\n", data.disorder * 100);
    put_float(data.disorder * 100);
    NL;
    ASSERT_END(__func__);
}

int init_and_check_assert(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    check_digit_assert();
    get_complexity_assert();
    atoi_long_long_assert();
    check_arg_assert();
    init_stack_assert();
    check_dupplicate_assert();
    init_data_assert(argv);
    
    
    return (0);
}