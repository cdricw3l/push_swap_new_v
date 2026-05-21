/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 09:01:59 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/21 11:33:09 by cebouhad         ###   ########.fr       */
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

int push(t_data *data, int src, int dst)
{
    if (!data)
        return (NO_MOVE);
    if(src == STACK_A && dst == STACK_B && data->size_a)
    {
        data->b = data->a;
        data->size_b++;
        data->a++;
        data->size_a--;
        if (data->size_a == 0)
            data->a = NULL;
        return (OK);
    }
    if (src == STACK_B && dst == STACK_A && data->size_b)
    {
        data->a = data->b;
        data->size_a++;
        data->b--;
        data->size_b--;
        if (data->size_b == 0)
            data->b = NULL;
        return (OK);
    }
    return (NO_MOVE);
}
