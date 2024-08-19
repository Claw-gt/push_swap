/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:58:33 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	optim_rotations(int rotations, t_stack **stack)
{
	while (rotations != 0)
	{
		if (rotations < 0)
		{
			rotations++;
			rra(stack, 0);
		}
		if (rotations > 0)
		{
			rotations--;
			ra(stack, 0);
		}
	}
}

int	lower_half(t_stack *stack, int middle)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index <= middle)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

void	push_until_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		midpoint;

	midpoint = 0;
	tmp = *stack_a;
	midpoint = size / 2 + 1;
	while (tmp && lower_half(*stack_a, midpoint) != -1 && \
	ft_stcksize(*stack_a) > 3)
	{
		if (tmp->index <= midpoint && tmp->index <= (size - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 0);
		tmp = *stack_a;
	}
	while (tmp && ft_stcksize(*stack_a) > 3)
	{
		if (tmp->index <= (size - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 0);
		tmp = *stack_a;
	}
}

void	sort_more(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*optim_node;
	int		size;
	int		initial;
	int		target;

	stack_b = NULL;
	initial = 0;
	target = 0;
	size = ft_stcksize(*stack_a);
	push_until_three(stack_a, &stack_b, size);
	sort_three(stack_a);
	while (stack_b)
	{
		initial = stack_position(&stack_b, stack_b->index);
		target = target_position(stack_a, stack_b->index);
		optim_node = find_optim(initial, target, &stack_b, stack_a);
		moves(optim_node, stack_a, &stack_b);
	}
	//if (check_sorted(*stack_a) != 0)
	size = ft_stcksize(*stack_a);
	if ((*stack_a)->index != 1)
		optim_rotations(count_moves(stack_position(stack_a, 1), size), stack_a);
}
