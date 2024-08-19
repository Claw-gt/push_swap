/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:04:45 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 16:14:34 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// int find_max(int num1, int num2, int num3)
// {
//     if (num1 > num2 && num1 > num3)
//         return (num1);
//     else if (num2 > num1 && num2 > num3)
//         return (num2);
//     else
//         return (num3);
// }

// int find_min(int num1, int num2, int num3)
// {
//     if (num1 < num2 && num1 < num3)
//         return (num1);
//     else if (num2 < num1 && num2 < num3)
//         return (num2);
//     else
//         return (num3);
// }
int find_min(t_stack *stack)
{
    int min;

    min = stack->index;
    while(stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}

int find_max(t_stack *stack)
{
    int max;

    max = stack->index;
    while(stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

void sort_three(t_stack **stack_a)
{
    int max;
    //int min;

    max = 0;
    //min = 0;
    //max = find_max((*stack_a)->index, (*stack_a)->next->index, (*stack_a)->next->next->index);
    max = find_max(*stack_a);
    //min = find_min((*stack_a)->index, (*stack_a)->next->index, (*stack_a)->next->next->index);
    if (check_sorted(*stack_a) == 0)
        return ;
    if (max == (*stack_a)->index)
    {
        ra(stack_a, 0);
        if (check_sorted(*stack_a) == -1)
            sa(stack_a);
    }
    else if (max == (*stack_a)->next->index)
    {
        rra(stack_a, 0);
        if (check_sorted(*stack_a) == -1)
            sa(stack_a);
    }
    else if (max == (*stack_a)->next->next->index)
        sa(stack_a);
}
