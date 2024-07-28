/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:04:45 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/28 16:19:11 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(int num1, int num2, int num3)
{
    if (num1 > num2 && num1 > num3)
        return (num1);
    else if (num2 > num1 && num2 > num3)
        return (num2);
    else
        return (num3);
}

int find_min(int num1, int num2, int num3)
{
    if (num1 < num2 && num1 < num3)
        return (num1);
    else if (num2 < num1 && num2 < num3)
        return (num2);
    else
        return (num3);
}

void sort_three(t_stack **stack_a)
{
    int max;
    //int min;

    max = 0;
    //min = 0;
    max = find_max((*stack_a)->index, (*stack_a)->next->index, (*stack_a)->next->next->index);
    //min = find_min((*stack_a)->index, (*stack_a)->next->index, (*stack_a)->next->next->index);
    if (check_sorted(*stack_a) == 0)
        return ;
    if (max == (*stack_a)->index)
    {
        ra(stack_a);
        if (check_sorted(*stack_a) == -1)
            sa(stack_a);
    }
    else if (max == (*stack_a)->next->index)
    {
        rra(stack_a);
        if (check_sorted(*stack_a) == -1)
            sa(stack_a);
    }
    else if (max == (*stack_a)->next->next->index)
    {
        //if (check_sorted(*stack_a) == -1)
        sa(stack_a);
    }
}