/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/30 07:53:18 by cdric.b          ###   ########.fr       */
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
    if (data.size_a == 3 && data.algo == NONE)
        three_values(&data, STACK_A);
    else if(data.size_a == 5 && data.algo == NONE)
      five_values(&data, STACK_A);
    else if (data.algo == SIMPLE)
        selection_sort(&data);
    else if (data.algo == MEDIUM)
        medium_rank(&data);
    return (0);
}
