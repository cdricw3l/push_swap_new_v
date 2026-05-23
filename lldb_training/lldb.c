/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:32:50 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/23 13:10:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	float_precision_ajustement(int n)
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
    ft_putnbr_fd(ipart,STDOUT_FILENO);
    write(STDOUT_FILENO, ".", 1);
    ft_putnbr_fd(f_adjusted,STDOUT_FILENO);
}

int main(int argc, char **argv)
{

    (void)argc;
    (void)argv;

    put_float(8.57);
    
    return (0);
}