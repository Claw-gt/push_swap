/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/13 17:41:25 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		moves = size_stack - position; //moves es negativo -> reverse rotate
    return (moves);
}

int absolute_value(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	costs_node_b(int initial_position, int target_position, int size_b, int size_a)
{
	int moves_b;
	int	moves_a;

	moves_b = count_moves(initial_position, size_b);
	moves_a = count_moves(target_position, size_a);
	if ((moves_a > 0 && moves_b > 0) || (moves_a < 0 && moves_b < 0))
	{
		absolute_value(moves_a)--;
		absolute_value(moves_b)--;
	}
	
	//else if ()
}

// int find_optim(t_stack **stack_b)
// {
//     t_stack *tmp;
//     int     cheapest;
// 	int		min;

//     tmp = *stack_b;
//     cheapest = (*stack_b)->index;
// 	min = count_moves(stack_b);
// 	printf("moves %d", min);
//     while (tmp)
//     {
//         if (count_moves(stack_b, tmp->index) < min)
// 			cheapest = tmp->index;
//         tmp = tmp->next;
//     }
// 	return (cheapest);
// }