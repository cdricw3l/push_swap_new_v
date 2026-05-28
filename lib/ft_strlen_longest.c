/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_longest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:30:43 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/20 09:33:11 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_longest(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	
	if (!s1 && !s2)
		return (0);
	if (s1 && !s2)
		return (ft_strlen(s2));
	if (!s1 && s2)
		return (ft_strlen(s1));
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (i > j)
		return (i);
	return (j);
}