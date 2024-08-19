/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:04:45 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:38:03 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **stack_a)
{
	int	max;

	max = find_max(*stack_a);
	if (check_sorted(*stack_a) == 0)
		return ;
	if (max == (*stack_a)->index)
	{
		ra(stack_a, 0);
		if (check_sorted(*stack_a) == -1)
			sa(stack_a, 0);
	}
	else if (max == (*stack_a)->next->index)
	{
		rra(stack_a, 0);
		if (check_sorted(*stack_a) == -1)
			sa(stack_a, 0);
	}
	else if (max == (*stack_a)->next->next->index)
		sa(stack_a, 0);
}
