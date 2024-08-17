/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:46:34 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/20 17:44:55 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//ra
void ra(t_stack **stack_a)
{
    t_stack *tmp;
    t_stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    tmp = *stack_a;
    *stack_a = tmp->next;
    tmp->next = NULL;
    last = ft_stcklast(*stack_a);
    last->next = tmp;
    write(1, "ra\n", 3);
}
//rb
void rb(t_stack **stack_b)
{
    t_stack *tmp;
    t_stack *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    tmp = *stack_b;
    *stack_b = tmp->next;
    tmp->next = NULL;
    last = ft_stcklast(*stack_b);
    last->next = tmp;
    write(1, "rb\n", 3);
}
//rr
void rr(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}