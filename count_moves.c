/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:11:42 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 16:48:32 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_moves(int number)
{
    int moves;

    moves = 0;

    return (moves);
}

void find_optim(t_stack **stack_b)
{
    t_stack *tmp;
    int     cheapest;
	int		min;

    tmp = *stack_b;
    cheapest = (*stack_b)->index;
	min = count_moves(*stack_b)->index;
    while (tmp)
    {
        if (count_moves(tmp->index) < min)
			cheapest = tmp->index;
        tmp = tmp->next;
    }
}