/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:45:17 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/25 18:33:04 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
//pa
void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	// tmp = *stack_b;
	// *stack_b = tmp->next;
	// if (*stack_a == NULL)
	// {
	// 	*stack_a = tmp;
	// 	tmp->next = NULL;
	// 	write(1, "pa\n", 3);
	// 	return ;
	// }
	// tmp->next = *stack_a;
	// *stack_a = tmp;
	write(1, "pa\n", 3);
}
//pb
void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	// tmp = *stack_a;
	// *stack_a = tmp->next;
	// if (*stack_b == NULL)
	// {
	// 	*stack_b = tmp;
	// 	tmp->next = NULL;
	// 	write(1, "pb\n", 3);
	// 	return ;
	// }
	// tmp->next = *stack_b;
	// *stack_b = tmp;
	write(1, "pb\n", 3);
}