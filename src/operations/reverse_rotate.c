/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:47:06 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/20 17:44:18 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//rra
void rra(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    last = ft_stcklast(*stack_a);
    tmp = *stack_a;
    while (tmp->next != last)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    write(1, "rra\n", 4);
}
//rrb
void rrb(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    last = ft_stcklast(*stack_b);
    tmp = *stack_b;
    while (tmp->next != last)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    write(1, "rrb\n", 4);
}
//rrr
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}