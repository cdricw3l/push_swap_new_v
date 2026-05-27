/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabrugge <mabrugge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/27 11:08:34 by mabrugge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

int main(int argc, char **argv)
{
    t_global_data data;

    (void)argc;
    if(init_global_data(&argv[1], &data) == ERR)
        return (1);
    if (data.size_a == 3)
      three_values(&data, STACK_A);
    else if(data.size_a == 5)
      five_values(&data, STACK_A, STACK_B);
    else
      selection_sort(&data);
    display_stack(&data, STACK_A);
    return (0);
}
