/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:32:49 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 16:46:40 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	five_values(t_global_data *data, int stk_src, int stk_dst)
{
	if (ft_is_sort(data, stk_src))
		return ;
	min_at_beginning(data, stk_src);
	push(data, stk_src, stk_dst, DISPLAY);
	min_at_beginning(data, stk_src);
	push(data, stk_src, stk_dst, DISPLAY);
	three_values(data, stk_src);
	push(data, stk_dst, stk_src, DISPLAY);
	push(data, stk_dst, stk_src, DISPLAY);
}
