/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optim_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:55:39 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/20 13:04:16 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	count_moves(int position, int size_stack)
{
	int	moves;

	moves = 0;
	if ((position) <= (size_stack / 2))
		moves = position;
	else
		moves = position - size_stack;
	return (moves);
}

int	count_optim_moves(int moves_b, int moves_a)
{
	int	rot_a;
	int	rot_b;
	int	total_moves;

	total_moves = 0;
	rot_a = abs(moves_a);
	rot_b = abs(moves_b);
	if ((moves_b > 0 && moves_a > 0) || (moves_b < 0 && moves_a < 0))
	{
		if (rot_b >= rot_a)
			total_moves = rot_b;
		else
			total_moves = rot_a;
	}
	else
		total_moves = rot_a + rot_b;
	return (total_moves);
}

t_stack	*find_optim(int init, int target, t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*cheapest;
	int		lower_costs;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	cheapest = *stack_b;
	(*stack_b)->moves_b = count_moves(init, ft_stcksize(*stack_b));
	(*stack_b)->moves_a = count_moves(target, ft_stcksize(*stack_a));
	lower_costs = count_optim_moves((*stack_b)->moves_b, (*stack_b)->moves_a);
	while (tmp_b)
	{
		init = stack_position(stack_b, tmp_b->index);
		target = target_position(stack_a, tmp_b->index);
		tmp_b->moves_b = count_moves(init, ft_stcksize(*stack_b));
		tmp_b->moves_a = count_moves(target, ft_stcksize(*stack_a));
		if (count_optim_moves(tmp_b->moves_b, tmp_b->moves_a) < lower_costs)
		{
			lower_costs = count_optim_moves(tmp_b->moves_b, tmp_b->moves_a);
			cheapest = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}
