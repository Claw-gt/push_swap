/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:46:34 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:29:18 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stack **stack_a, int duplicate)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	last = ft_stcklast(*stack_a);
	last->next = tmp;
	if (duplicate == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int duplicate)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	last = ft_stcklast(*stack_b);
	last->next = tmp;
	if (duplicate == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL || \
	*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}
