/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:39:03 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/26 16:52:39 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* float precision ajustement. Work with put_float */
static int	float_precision_ajustement(int n)
{
	if (n % 10 > 5)
		while (n % 10 != 0)
			n++;
	return (n);
}

/* display float value for benchmark */
void	put_float(float nb)
{
	int		ipart;
	int		f_adjusted;
	float	fpart;

	/* get int value part */
	ipart = (int)nb;
	/* get float part */
	fpart = nb - (float)ipart;
	/* check if third number is greater than 5. Exemple: 0.586 -> 0.59 */
	f_adjusted = float_precision_ajustement((int)(fpart * 1000)) / 10;
	/* write integer part */
	ft_putnbr_fd(ipart, STDOUT_FILENO);
	/* write '.' */
	write(STDOUT_FILENO, ".", 1);
	/* write float part */
	ft_putnbr_fd(f_adjusted, STDOUT_FILENO);
}

/* display the move in STDOUT */
void	print_move(int move, int stack)
{
	if (move == S && stack == STACK_A)
		write(STDOUT_FILENO, "sa\n", 3);
	if (move == S && stack == STACK_B)
		write(STDOUT_FILENO, "sb\n", 3);
	if (move == P && stack == STACK_A)
		write(STDOUT_FILENO, "pa\n", 3);
	if (move == P && stack == STACK_B)
		write(STDOUT_FILENO, "pb\n", 3);
	if (move == R && stack == STACK_A)
		write(STDOUT_FILENO, "ra\n", 3);
	if (move == R && stack == STACK_B)
		write(STDOUT_FILENO, "rb\n", 3);
	if (move == RV && stack == STACK_A)
		write(STDOUT_FILENO, "rra\n", 4);
	if (move == RV && stack == STACK_B)
		write(STDOUT_FILENO, "rrb\n", 4);
	if (move == RR && stack == A_AND_B)
		write(STDOUT_FILENO, "rr\n", 3);
	if (move == RRR && stack == A_AND_B)
		write(STDOUT_FILENO, "rrr\n", 4);
}
