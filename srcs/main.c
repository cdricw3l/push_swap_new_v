/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:08:25 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/27 11:15:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_global_data data;
    (void)argc;
    if (init_global_data(&argv[1], &data) == ERR)
    {
        write(STDOUT_FILENO, "Error\n", 6);
        return (1);
    }
    if (data.size_a == 3)
        three_values(&data, STACK_A);
    else if (data.size_a == 5)
        five_values(&data, STACK_A, STACK_B);
    return (0);
}
