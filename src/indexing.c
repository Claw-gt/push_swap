/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:30:53 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/05 13:02:12 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//implementar QuickSort
int partition(int *array, int low, int high)
{
    int pivot;
    int i;
    int j;
    int tmp;

    pivot = array[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (array[j] <= pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        j++;
    }
    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    return (i + 1);
}

void quick_sort(int *array, int low, int high)
{
    int pi;

    pi = 0;
    if (low < high)
    {
        pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

int find_number(int *array, int number)
{
	int i;

	i = 0;
	while (array[i] != number)
		i++;
	return (++i);
}

void stack_indexing(t_stack **stack, int *array)
{
    t_stack *tmp;

    tmp = *stack;
    while (tmp)
    {
		tmp->index = find_number(array, tmp->content);
        tmp = tmp->next;
    }
}