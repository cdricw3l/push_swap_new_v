/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:34:24 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/19 21:46:20 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <assert.h>

int get_complexity(char *arg)
{
    if(ft_strncmp(arg, "--simple", ft_strlen_longest("--simple", arg)) == OK)
        return (SIMPLE);
    else if (ft_strncmp(arg, "--medium", ft_strlen_longest("--medium", arg)) == OK)
        return (MEDIUM);
    else if (ft_strncmp(arg, "--complex", ft_strlen_longest("--complex", arg)) == OK)
        return (COMPLEX);
    else if (ft_strncmp(arg, "--adaptive", ft_strlen_longest("--adaptive", arg)) == OK)
        return (ADAPTATIVE);
    return (NONE);
}

int check_digit(char *str)
{
    char *ptr;

    ptr = str;
    if (*ptr == MINUS || *ptr == PLUS)
        ptr++;
    while (*ptr)
    {
        if (!ft_isdigit(*ptr))
            return (ERR);
        ptr++;
    }
    return (OK);
}

// int check_args(char **argv, t_data *data)
// {
//     size_t  i;
//     size_t  j;
//     char **split;

//     i = 0;
//     data->algo = get_complexity(argv[0]);
//     if(data->algo != NONE)
//         i++;
//     while (argv[i])
//     {
//         split = ft_split(argv[i], SPACE);
//         if(!split)
//             return (ERR);
//         j = 0;
//         while (split[j])
//         {
//             /* code */
//         }
        
//     }
    
// }
