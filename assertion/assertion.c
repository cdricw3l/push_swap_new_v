/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:03:17 by cdric.b           #+#    #+#             */
/*   Updated: 2026/05/25 13:27:06 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assertion.h"

int main(int argc, char **argv)
{
    (void)argc;
    char buffer[3];
    char intro[] = "Witch test yould you want to launch:\n["GREEN"0"RESET"] = init_and_check_assertion\n["GREEN"1"RESET"] = move_assertion\n["GREEN"2"RESET"] = algo_assertion\ninput: ";
    int b_read;

    write(STDOUT_FILENO, intro, ft_strlen(intro));
    b_read = read(STDIN_FILENO, buffer, 3);
    if (b_read < 0 || b_read > 2)
        return (1);
    buffer[b_read - 1] = '\0';
    if(!ft_strncmp("0", buffer, 2))
    {
        printf("Here");
        init_and_check_assert(argc, &argv[1]);
    }
    else if(!ft_strncmp("1", buffer, 2))
        move_assertions(argc, argv);
    else if(!ft_strncmp("2", buffer, 2))
        algo_assert(argv);

    return (0);
}