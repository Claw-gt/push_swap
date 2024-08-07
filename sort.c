/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 13:34:35 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpoint(int size_stack)
{
	int	midpoint;

	midpoint = 0;
	midpoint = size_stack/2;
	if (midpoint % 2 == 0)
		return (++midpoint);
	return (midpoint);
}

void push_to_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		midpoint;

	midpoint = 0;
	stack_b = NULL;
	tmp = *stack_a;
	midpoint = find_midpoint((*stack_a)->size);
	while (tmp)
	{
		if (tmp->index < midpoint)
			pb(stack_a, &stack_b);
		else
			ra(stack_a);
		tmp = tmp->next;
	}
}