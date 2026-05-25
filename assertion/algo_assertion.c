/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:25:58 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 12:41:31 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void tree_value_assert(void)
{
    t_data data;

    int arr1[3] = {1,2,3};
    int arr2[3] = {1,3,2};
    int arr3[3] = {2,1,3};
    int arr4[3] = {2,3,1};
    int arr5[3] = {3,1,2};
    int arr6[3] = {3,2,1};
    
    data.a = arr1;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr2;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr3;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr4;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr5;
    tree_values(&data);
    assert(ft_is_sort(&data));
    data.a = arr6;
    tree_values(&data);
    assert(ft_is_sort(&data));
}


void algo_assert(char **argv)
{
    (void)argv;
    tree_value_assert();
}   