/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/19 19:14:14 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

void check_digit_assert(void)
{
    assert(check_digit("100") == OK);
    assert(check_digit("42") == OK);
    assert(check_digit("-42") == OK);
    assert(check_digit("0") == OK);
    assert(check_digit("+150") == OK);
    assert(check_digit("+1a50") == ERR);
    assert(check_digit("a50") == ERR);
    assert(check_digit("50a") == ERR);
}

int main(void)
{
    check_digit_assert();
    return (0);
}