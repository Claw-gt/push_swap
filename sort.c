/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:46:55 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 16:14:51 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpoint(int size_stack)
{
	int	midpoint;

	midpoint = 0;
	midpoint = size_stack/2;
	if (midpoint % 2 == 0)
		return (++midpoint);
	return (midpoint);
}

int	lower_half(t_stack *stack, int middle)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index < middle)
			return (0);
		tmp = tmp->next;
	}
	return (-1);
}

void push_lowerhalf(t_stack **stack_a, t_stack **stack_b, int size)
{
	//t_stack	*stack_b;
	t_stack	*tmp;
	int		midpoint;

	midpoint = 0;
	//stack_b = NULL;
	tmp = *stack_a;
	midpoint = find_midpoint(size);
	while (tmp && lower_half(*stack_a, midpoint) != -1 && ft_stcksize(*stack_a) > 3) //iterar por los nodos mientras haya alguno que umpla la condición
	{
		if (tmp->index < midpoint && tmp->index <= (size - 3))
			pb(stack_a, stack_b);	
		else
			ra(stack_a);
		tmp = *stack_a;
	}
}

void push_tophalf(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp && ft_stcksize(*stack_a) > 3)
	{
		if (tmp->index <= (size - 3))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		tmp = *stack_a;
	}
}

void push_to_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		total_args;

	stack_b = NULL;
	total_args = 0;
	total_args = ft_stcksize(*stack_a);
	push_lowerhalf(stack_a, &stack_b, total_args);
	push_tophalf(stack_a, &stack_b, total_args);
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

void sort_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (check_sorted(*stack_a) == 0)
		return ;
	else
	{
		if (ft_stcksize(*stack_a) == 3)
			sort_three(stack_a);
		else
		{
			push_to_b(stack_a);
			sort_three(stack_a);
		}
	}
		printf("Stack A\n");
	tmp = *stack_a;
	while (tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
	printf("****************\n");
}
