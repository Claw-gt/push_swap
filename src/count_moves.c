/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/16 17:10:16 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void join_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b)
// {
// 	if ((*moves_a > 0 && *moves_b > 0))
// 		rr(stack_a, stack_b);
// 	else if (((*moves_a < 0 && *moves_b < 0)))
// 		rrr(stack_a, stack_b);
// }

int count_moves(int position, int size_stack)
{
    int 	moves;

    moves = 0;
	if (position <= (size_stack / 2))
		moves = position; //moves es positivo -> rotate
	else
		moves = position - size_stack; //moves es negativo -> reverse rotate
    return (moves);
}

int abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

// int	costs_node_b(int initial_position, int target_position, int size_b, int size_a)
// {
// 	int moves_b;
// 	int	moves_a;

// 	moves_b = count_moves(initial_position, size_b);
// 	moves_a = count_moves(target_position, size_a);
// 	return (absolute_value(moves_b) + absolute_value(moves_a));
// }

t_stack	*find_optim(int initial, int target, t_stack **stack_b, t_stack **stack_a)
{
	t_stack     *cheapest;
	int			lower_costs;
	t_stack		*tmp_b;

	tmp_b = *stack_b;
	cheapest = *stack_b;
	(*stack_b)->moves_b = count_moves(initial, ft_stcksize(*stack_b));
	(*stack_b)->moves_a = count_moves(target, ft_stcksize(*stack_a));
	lower_costs = abs((*stack_b)->moves_b) + abs((*stack_b)->moves_a);
	while (tmp_b)
	{
		initial = stack_position(stack_b, tmp_b->index);
		target = target_position(stack_a, tmp_b->index);
		tmp_b->moves_b = count_moves(initial, ft_stcksize(*stack_b));
		tmp_b->moves_a = count_moves(target, ft_stcksize(*stack_a));
		//printf("Moves in B: %d Moves in A: %d", tmp_b->moves_b, tmp_b->moves_a);
		//printf("   The total costs are %d\n", abs(tmp_b->moves_b) + abs(tmp_b->moves_a));
		if (abs(tmp_b->moves_b) + abs(tmp_b->moves_a) < lower_costs)
		{
			lower_costs = abs(tmp_b->moves_b) + abs(tmp_b->moves_a);
			cheapest = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	//printf("\nThe optim node is %d\n", cheapest->index);
	//return (abs(moves_b) + abs(moves_a));
	return (cheapest);
}

// t_stack *find_optim(t_stack **stack_b, int size_a, int size_b)
// {
//     t_stack 	*tmp_b;
//     t_stack     *cheapest;
// 	int			total_moves;
// 	int			lower_costs;
// 	int			initial_position;
// 	int			target_position;
	
//     tmp_b = *stack_b;
//     cheapest = *stack_b;
// 	total_moves = 0;
// 	lower_costs = 1;
// 	//lower_costs = costs_node_b(stack_position(stack_b, tmp_b->index), target_position(stack_a, tmp_b->index), ft_stcksize(stack_b), ft_stcksize(stack_a));
// 	while (tmp_b)
// 	{
// 		//debe devolver los moves en valor absoluto
// 		//(*stack_b)->moves_b = count_moves(stack_position(stack_b, tmp_b->index), size_b);
// 		total_moves = costs_node_b(stack_position(stack_b, tmp_b->index), target_position(stack_a, tmp_b->index), size_b, size_a);
// 		if (total_moves < lower_costs)
// 		{
// 			lower_costs = total_moves;
// 			cheapest = tmp_b;
// 		}
// 		tmp_b = tmp_b->next;
// 	}
// 	return (cheapest);
// }

//TO DO: contar movimientos teniendo en cuenta que se pueden reducir con rr y rrr
void moves(t_stack *optim_node, t_stack **stack_a, t_stack **stack_b)
{
	while (optim_node->moves_b != 0 || optim_node->moves_a != 0)
	{
		if (optim_node->moves_b > 0 && optim_node->moves_a > 0)
		{
			rr(stack_a, stack_b);
			optim_node->moves_b--;
			optim_node->moves_a--;
		}	
		else if (optim_node->moves_b < 0 && optim_node->moves_a < 0)
		{
			rrr(stack_a, stack_b);
			optim_node->moves_b++;
			optim_node->moves_a++;
		}	
		else if (optim_node->moves_b > 0)
		{
			rb(stack_b);
			optim_node->moves_b--;
		}
		else if (optim_node->moves_a > 0)
		{
			ra(stack_a);
			optim_node->moves_a--;
		}
		else if (optim_node->moves_a < 0)
		{
			rra(stack_a);
			optim_node->moves_a++;
		}
		else if (optim_node->moves_b < 0)
		{
			rrb(stack_b);
			optim_node->moves_b++;
		}
	}
	pa(stack_a, stack_b);
}
