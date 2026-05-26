/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbuging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:47:10 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 16:53:02 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* just for debbuging. Delete this file for the render */

void display_data(t_global_data data)
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
/* just for debbuging. Delete this file for the render */

void display_stack(t_global_data *data, int stack)
{
    int *ptr;

    if (!data || (stack != STACK_A && stack != STACK_B))
        return ;
    if (stack == STACK_A)
    {
        ptr = data->a;
        printf("stack A: ");
    }
    else if (stack == STACK_B)
    {
        ptr = data->b;
        printf("stack B: ");
    }
    else
        return ;
    if (ptr && stack == STACK_A)
        while(ptr <= data->end)
        {
            printf("%d ", *ptr);
            ptr++;
        }
    else if (ptr && stack == STACK_B)
        while(ptr >= data->start)
        {
            printf("%d ", *ptr);
            ptr--;
        }
    NL;
}
