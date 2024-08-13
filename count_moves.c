/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/13 14:52:35 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void join_moves(t_stack **stack_a, t_stack **stack_b, int moves_a, int moves_b)
{
	if ((*moves_a > 0 && *moves_b > 0))
		rr(stack_a, stack_b);
	else if (((*moves_a < 0 && *moves_b < 0)))
		rrr(stack_a, stack_b);
}

int count_moves_(t_stack **stack)
{
    int 	moves;
	t_stack	*tmp;
	int		size;

	tmp = *stack;
    moves = 0;
	size =  ft_stcksize(*stack);
	while (tmp)
	{
		if (tmp->position <= (size / 2))
			moves = position; //moves es positivo -> rotate
		else
			moves = size - position; //moves es negativo -> reverse rotate
		tmp = tmp->next;
	}
    return (moves);
}

int	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	i
}

int find_optim(t_stack **stack_b)
{
    t_stack *tmp;
    int     cheapest;
	int		min;

    tmp = *stack_b;
    cheapest = (*stack_b)->index;
	min = count_moves(stack_b);
	printf("moves %d", min);
    while (tmp)
    {
        if (count_moves(stack_b, tmp->index) < min)
			cheapest = tmp->index;
        tmp = tmp->next;
    }
	return (cheapest);
}