/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/14 13:20:21 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpoint(int size_stack)
{
	int	midpoint;

	midpoint = 0;
	midpoint = size_stack / 2 + 1;
	// if (midpoint % 2 == 0)
	// 	return (++midpoint);
	return (midpoint);
}

// TO DO: Comprobar si debería ser "<" o "<="

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

void push_until_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		midpoint;

	midpoint = 0;
	tmp = *stack_a;
	midpoint = find_midpoint(size);
	// push_lowerhalf;
	while (tmp && lower_half(*stack_a, midpoint) != -1 && ft_stcksize(*stack_a) > 3) //iterar por los nodos mientras haya alguno que cumpla la condición
	{
		if (tmp->index < midpoint) //&& tmp->index <= (size - 3))
			pb(stack_a, stack_b);	
		else
			ra(stack_a);
		tmp = *stack_a;
	}
	// push_tophalf;
	while (tmp && ft_stcksize(*stack_a) > 3)
	{
		if (tmp->index <= (size - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		tmp = *stack_a;
	}
	
}

void sort_more(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp_b;
	t_stack	*optim_node;
	int		total_args;
	int		initial_position;
	int		target_position;
	int		moves_a;
	int		moves_b;
	//int		total_moves;
	//int		lower_costs;

	stack_b = NULL;
	total_args = 0;
	initial_position = 0;
	target_position = 0;
	moves_a = 0;
	moves_b = 0;
	//total_moves = 0;
	//lower_costs = 0;
	total_args = ft_stcksize(*stack_a);
	push_until_three(stack_a, &stack_b, total_args);
	sort_three(stack_a);
	tmp_b = stack_b;
	while (tmp_b)
	{
		//tiene que estar dentro de otro bucle que recorra todos los nodos de stack_b
		//funcion assign_position que asigne la posicióna todos los nodos de B y que llame a stack y target position
		// initial_position = stack_position(&stack_b, tmp_b->index);
		// target_position = target_position(stack_a, tmp_b->index);
		// moves_b = count_moves(initial_position, size_b);
		// moves_a = count_moves(target_position, size_a);
		optim_node = find_optim(&initial_position, &target_position, &stack_b, stack_a);
		// optim_node = find_optim(&stack_b, );
		//moves (optim_node, moves_a, moves_b)
	}
	// printf("Stack A\n");
	// tmp = *stack_a;
	// while (tmp)
    // {
		
    //     printf("%d pos: %d\n", tmp->index, stack_position(stack_a, tmp->index));
    //     tmp = tmp->next;
    // }
	// tmp = stack_b;
	// printf("Stack B\n");
	// while (tmp)
    // {
    //     printf("%d pos: %d\n", tmp->index, stack_position(&stack_b, tmp->index));
    //     tmp = tmp->next;
    // }
	// printf("****************\n");
	
	// tmp_b = stack_b;
	// optim_node = stack_b;
	// lower_costs = costs_node_b(stack_position(stack_b, tmp_b->index), target_position(stack_a, tmp_b->index), ft_stcksize(stack_b), ft_stcksize(stack_a));
	// while (tmp_b)
	// {
	// 	//debe devolver los moves en valor absoluto
	// 	total_moves = costs_node_b(stack_position(stack_b, tmp_b->index), target_position(stack_a, tmp_b->index), ft_stcksize(stack_b), ft_stcksize(stack_a));
	// 	if (total_moves < lower_costs)
	// 	{
	// 		lower_costs = total_moves;
	// 		optim_node = tmp_b;
	// 	}
	// 	tmp_b = tmp_b->next;
	// }
}


