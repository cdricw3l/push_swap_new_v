/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:32:50 by cebouhad          #+#    #+#             */
/*   Updated: 2026/05/25 10:16:17 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

// void radix_sort(int arr[10], int len)
// {
    
// }

int ft_is_sort(int arr[10], int len)
{
    int i;

    i = 0;
    while (i < len - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void jump_sort(int arr[10], int len)
{
    int i;
    int j;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] > arr[j])
            {
                ft_swap(&arr[i], &arr[j]);
                j = i + 1;
            }
            j++;
        }
        i++;
    }
    

}

void bubble_sort(int arr[10], int len)
{
    int i;

    i = 0;
    while (i < len - 1)
    {
        if(arr[i] > arr[i + 1])
            ft_swap(&arr[i], &arr[i + 1]);
        i++;
        if (i == len - 1)
        {
            i = 0;
            len--;
        }
    }
}

void print_arr(int arr[10], int len)
{
    int i;

    i = 0;
    while (i < len)
        printf("%d ", arr[i++]);
}

int main(int argc, char **argv)
{

    (void)argc;
    (void)argv;
    
    int arr[] = {280, 54, -90, 40, 8, -27, 33, 68, -5, 17000, -1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    assert(!ft_is_sort(arr, n));
    bubble_sort(arr, n);
    print_arr(arr, n);
    assert(ft_is_sort(arr, n));
    
    return (0);
}