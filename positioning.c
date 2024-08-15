/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positioning.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:41:28 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/13 17:01:00 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_position(t_stack **stack, int number)
{
    int     pos;
    t_stack *tmp;

    tmp = *stack;
    pos = 0;
    while (tmp)
    {
        //tmp->position = pos;
        if (tmp->index == number)
            return (pos);
        pos++;
        tmp = tmp->next;
    }
    return (-1);
}

int target_position(t_stack **stack_a, int stack_b_index)
{
    int     closest_num;
    t_stack *tmp_a;
    int     target_pos;

    target_pos = 0;
    tmp_a = *stack_a;
    closest_num = find_max(stack_a);
    while (tmp_a)
    {
        if (stack_b_index < tmp_a->index && closest_num > tmp_a->index)
        {
            closest_num = tmp_a->index;
            target_pos = stack_position(stack_a, tmp_a->index);
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}