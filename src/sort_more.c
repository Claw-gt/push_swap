/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/16 18:11:04 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//NO OPTIMIZA
int optimization(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = *stack;
	last = ft_stcklast(*stack);
	while (tmp->next && tmp->next != last)
    {
        if (tmp->index > tmp->next->index)
            return (-1);
        tmp = tmp->next;
    }
	if (last->index == 1)
		rra(stack);
	return (0);	
}

void optimize_rotations(int rotations, t_stack **stack)
{
	while (rotations != 0)
	{
		if (rotations < 0)
		{
			rotations++;
			rra(stack);
		}
		if (rotations > 0)
		{
			rotations--;
			ra(stack);
		}
	}
}

int	find_midpoint(int size_stack)
{
	int	midpoint;

	midpoint = 0;
	midpoint = size_stack / 2 + 1;
	return (midpoint);
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

void push_until_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;
	int		midpoint;

	midpoint = 0;
	tmp = *stack_a;
	midpoint = find_midpoint(size);
	while (tmp && lower_half(*stack_a, midpoint) != -1 && ft_stcksize(*stack_a) > 3) //iterar por los nodos mientras haya alguno que cumpla la condición
	{
		if (tmp->index <= midpoint && tmp->index <= (size - 3))
			pb(stack_a, stack_b);	
		else
			ra(stack_a);
		tmp = *stack_a;
	}
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
	//t_stack	*tmp;
	t_stack	*optim_node;
	int		total_args;
	int		initial_position;
	int		target_position;

	stack_b = NULL;
	total_args = 0;
	initial_position = 0;
	target_position = 0;
	total_args = ft_stcksize(*stack_a);
	push_until_three(stack_a, &stack_b, total_args);
	sort_three(stack_a);
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
	while (stack_b)
	{
		optim_node = find_optim(initial_position, target_position, &stack_b, stack_a);
		moves(optim_node, stack_a, &stack_b);
		// printf("Stack A\n");
		// tmp = *stack_a;
		// while (tmp)
		// {
		// 	printf("%d pos: %d\n", tmp->index, stack_position(stack_a, tmp->index));
		// 	tmp = tmp->next;
		// }
		// tmp = stack_b;
		// printf("Stack B\n");
		// while (tmp)
		// {
		// 	printf("%d pos: %d\n", tmp->index, stack_position(&stack_b, tmp->index));
		// 	tmp = tmp->next;
		// }
		// printf("****************\n");
	}

	// NO OPTIMIZA
	// if (check_sorted(*stack_a) != 0)
	// {
	// 	if (stack_position(stack_a, 1) <= ft_stcksize(*stack_a) / 2)
	// 	{
	// 		while ((*stack_a)->index != 1)
	// 			ra(stack_a);
	// 	}
	// 	else
	// 	{
	// 		while ((*stack_a)->index != 1)
	// 			rra(stack_a);
	// 	}
	// }
	//if (check_sorted(*stack_a) != 0)
	if ((*stack_a)->index != 1)
		optimize_rotations(count_moves(stack_position(stack_a, 1), ft_stcksize(*stack_a)), stack_a);
	// while (check_sorted(*stack_a) != 0)
	// 	rra(stack_a);
}


