/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:32:29 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/23 13:10:48 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

    if (!data || (stack != STACK_A && stack != STACK_B))
        return ;
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

void ft_swap(int *p1, int *p2)
{
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

float compute_disorder(t_data *data)
{
    int i;
    int j;
    float mistakes;
    float total_pairs;

    i = 0;
    mistakes = 0;
    total_pairs = 0;
    while (i < data->size_a)
    {
        j = i + 1;
        while (j < data->size_a)
        {
            total_pairs++;
            if (data->stack[i] > data->stack[j])
                mistakes++;
            j++;
        }
        i++;
    }
    return (mistakes / total_pairs);
}

void print_move(int move, int stack)
{
    if(move == S && stack == STACK_A)
        write(STDOUT_FILENO, "sa\n", 3);
    if(move == S && stack == STACK_B)
        write(STDOUT_FILENO, "sb\n", 3);
    if(move == P && stack == STACK_A)
        write(STDOUT_FILENO, "pa\n", 3);
    if(move == P && stack == STACK_B)
        write(STDOUT_FILENO, "pb\n", 3);
    if(move == R && stack == STACK_A)
        write(STDOUT_FILENO, "ra\n", 3);
    if(move == R && stack == STACK_B)
        write(STDOUT_FILENO, "rb\n", 3);
    if(move == RV && stack == STACK_A)
        write(STDOUT_FILENO, "rra\n", 4);
    if(move == RV && stack == STACK_B)
        write(STDOUT_FILENO, "rrb\n", 4);
    if(move == RR && stack == A_AND_B)
        write(STDOUT_FILENO, "rr\n", 3);
    if(move == RRR && stack == A_AND_B)
        write(STDOUT_FILENO, "rrr\n", 4);
    
}


/* display float value for benchmark */

static int	float_precision_ajustement(int n)
{    
    if(n % 10 > 5)
    {
        while (n % 10 != 0)
            n++;
    }
    return (n);
}


void put_float(float nb)
{
    int ipart;
    int f_adjusted;
    float fpart;

    ipart = (int)nb;
    fpart = nb - (float)ipart;
    f_adjusted = float_precision_ajustement((int)(fpart * 1000)) / 10;
    ft_putnbr_fd(ipart, STDOUT_FILENO);
    write(STDOUT_FILENO, ".", 1);
    ft_putnbr_fd(f_adjusted, STDOUT_FILENO);
}