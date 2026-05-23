/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/23 13:14:17 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(int argc, char **argv)
{

    init_and_check_assert(argc, &argv[1]);
    move_assertions(argc, argv);
    
    return (0);
}