/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 09:07:16 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 12:30:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
    case 0: 1 2 3; case 1: 1 3 2; case 2: 2 1 3; case 3: 2 3 1; case 4: 3 1 2; case 5: 3 2 1
*/

void tree_values(t_data *data)
{
    if (ft_is_sort(data))
        return ;
    /* case 5 */    
    if (*(data->a) > *(data->a + 1) &&  *(data->a + 1) > *(data->a + 2))
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
    /* case 4 */
    if (*(data->a) > (*(data->a + 1) && *(data->a + 1) < *(data->a + 2)))
        rotate(data, STACK_A, DISPLAY);
    /* case 3 */
    if (*(data->a) < (*(data->a + 1) && *(data->a) > *(data->a + 2)))
        rev_rotate(data, STACK_A, DISPLAY);
    // /* case 2 */
    if (*(data->a) > (*(data->a + 1) && *(data->a) < *(data->a + 2)))
        swap(data, STACK_A, DISPLAY);
    /* case 1 */
    if (*(data->a) < (*(data->a + 1) && *(data->a + 1) > *(data->a + 2)))
    {
        swap(data, STACK_A, DISPLAY);
        rotate(data, STACK_A, DISPLAY);
    }
}
