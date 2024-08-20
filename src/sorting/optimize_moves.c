/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/20 13:03:24 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	joined_moves(t_stack **stack_a, t_stack **stack_b, int *ma, int *mb)
{
	if (*mb > 0 && *ma > 0)
	{
		rr(stack_a, stack_b);
		(*mb)--;
		(*ma)--;
	}
	else if (*mb < 0 && *ma < 0)
	{
		rrr(stack_a, stack_b);
		(*mb)++;
		(*ma)++;
	}
}

void	simple_moves(t_stack **stack_a, t_stack **stack_b, int *ma, int *mb)
{
	if (*mb > 0)
	{
		rb(stack_b, 0);
		(*mb)--;
	}
	else if (*ma > 0)
	{
		ra(stack_a, 0);
		(*ma)--;
	}
	else if (*ma < 0)
	{
		rra(stack_a, 0);
		(*ma)++;
	}
	else if (*mb < 0)
	{
		rrb(stack_b, 0);
		(*mb)++;
	}
}

void	moves(t_stack *optim_node, t_stack **stack_a, t_stack **stack_b)
{
	int	mb;
	int	ma;

	mb = optim_node->moves_b;
	ma = optim_node->moves_a;
	while (mb != 0 || ma != 0)
	{
		if ((mb > 0 && ma > 0) || (mb < 0 && ma < 0))
			joined_moves(stack_a, stack_b, &ma, &mb);
		else
			simple_moves(stack_a, stack_b, &ma, &mb);
	}
	pa(stack_a, stack_b);
}
