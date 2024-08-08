/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/08 16:08:58 by clagarci         ###   ########.fr       */
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
	while (tmp && lower_half(*stack_a, midpoint) != -1 && ft_stcksize(*stack_a) >= 3) //iterar por los nodos mientras haya alguno que cumpla la condición
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

// void push_tophalf(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	t_stack	*tmp;

// 	tmp = *stack_a;
// 	while (tmp && ft_stcksize(*stack_a) > 3)
// 	{
// 		if (tmp->index <= (size - 3))
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		tmp = *stack_a;
// 	}
// }

void sort_more(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		total_args;

	stack_b = NULL;
	total_args = 0;
	total_args = ft_stcksize(*stack_a);
	push_until_three(stack_a, &stack_b, total_args);
	sort_three(stack_a);
	printf("Stack A\n");
	tmp = *stack_a;
	while (tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
	tmp = stack_b;
	printf("Stack B\n");
	while (tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
	printf("****************\n");
}


