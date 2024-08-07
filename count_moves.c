/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 17:13:54 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_moves(t_stack **stack_b, int number)
{
    int 	moves;
	t_stack	*tmp;

	tmp = *stack_b;
    moves = 0;
	while (tmp->index != number)
	{
		tmp = tmp->next;
	}
	if (number > 0)
		write(1, "hello", 5);
    return (moves);
}

int find_optim(t_stack **stack_b)
{
    t_stack *tmp;
    int     cheapest;
	int		min;

    tmp = *stack_b;
    cheapest = (*stack_b)->index;
	min = count_moves(stack_b, (*stack_b)->index);
	printf("moves %d", min);
    while (tmp)
    {
        if (count_moves(stack_b, tmp->index) < min)
			cheapest = tmp->index;
        tmp = tmp->next;
    }
	return (cheapest);
}