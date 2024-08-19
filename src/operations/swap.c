/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:46:00 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:32:40 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack **stack_a, int duplicate)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	if (duplicate == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int duplicate)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp1 = *stack_b;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	if (duplicate == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL || \
	*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}
