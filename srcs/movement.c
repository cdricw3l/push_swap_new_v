/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:01:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/21 14:47:24 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

void display_data(t_data data)
{  
    if(data.algo == NONE)
        printf("aldo type: %s\n", "none");
    else if (data.algo == SIMPLE)
        printf("aldo type: %s\n", "simple");
    else if (data.algo == MEDIUM)
        printf("aldo type: %s\n", "medium");
    else if (data.algo == COMPLEX)
        printf("aldo type: %s\n", "complex");
    else if (data.algo == ADAPTATIVE)
        printf("aldo type: %s\n", "adaptative");
    printf("address stack A: %p\n", data.a);
    printf("size stack a: %d\n", data.size_a);
    printf("address stack B: %p\n", data.b);
    printf("size stack b: %d\n", data.size_b);
}

void display_stack(t_data *data, int stack)
{
    int *arr;
    int *ptr;

    if (stack == STACK_A)
    {
        arr = data->a;
        ptr = data->a;
        printf("stack A: ");
    }
    else if (stack == STACK_B)
    {
        arr = data->b;
        ptr = data->b;
        printf("stack B: ");
    }
    else
        arr = NULL;
    if (arr && stack == STACK_A)
        while(ptr <= data->end)
        {
            printf("%d ", *ptr);
            ptr++;
        }
    else if (arr && stack == STACK_B)
        while(ptr >= data->start)
        {
            printf("%d ", *ptr);
            ptr--;
        }
    NL;
}

int push(t_data *data, int src, int dst)
{
    /* security check for data */
    if (!data)
        return (NO_MOVE);
    /* ensure before pushing that stack A is not empty */
    if(src == STACK_A && dst == STACK_B && data->size_a)
    {
        data->b = data->a;
        data->size_b++;
        data->a++;
        data->size_a--;
        /* if the size of stack A is 0 pointer B == NULL */
        if (data->size_a == 0)
            data->a = NULL;
        return (OK);
    }
    /* ensure before pushing that stack B is not empty */
    if (src == STACK_B && dst == STACK_A && data->size_b)
    {
        data->a = data->b;
        data->size_a++;
        data->b--;
        /* if the size of stack B is 0 pointer B == NULL */
        data->size_b--;
        if (data->size_b == 0)
            data->b = NULL;
        return (OK);
    }
    return (NO_MOVE);
}

int swap(t_data *data, int stack)
{
    int *arr;
    int len;

    if (!data)
        return (NO_MOVE);
    /* this else else if else define with wich array we work */
    if (stack == STACK_A)
    {
        arr = data->a;
        len = data->size_a;
    }
    else if (stack == STACK_B)
    {
        arr = data->b;
        len = data->size_b;
    }
    else
        return (NO_MOVE);
    /* swap only if target arr len > 2 */
    if (arr && len > 1)
    {
        /* 
            if stack_A swap pointer a and a + 1  
            if stack B swap pointer b and b - 1
        */
        if (stack == STACK_A)
            ft_swap(data->a, data->a + 1);
        else if(stack == STACK_B)
            ft_swap(data->b, data->b - 1);
    }
    else
        return (NO_MOVE);
    return (OK);
}

int rr(t_data *data, int stack)
{
    int *arr;
    int len;
    int tmp;

    (void)arr;
    (void)len;
    if (stack == STACK_A)
    {
        arr = data->a;
        len = data->size_a;
        tmp = *(data->a);
        ft_memmove(data->a + 1, data->a, data->size_a - 1);
        *(data->a) = tmp;

    }
    else if (stack == STACK_B)
    {
        arr = data->b;
        len = data->size_b;
        tmp = *(data->b - data->size_b);
        ft_memmove(data->b - 1, data->b, data->size_b - 1);
        *(data->b) = tmp;
    }
    else
        return (NO_MOVE);
    return (OK);    
}

