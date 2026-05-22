/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/22 14:11:28 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(int argc, char **argv)
{

    //init_and_check_assert(argc, &argv[1]);
    move_assertions(argc, argv);
    
    return (0);
}