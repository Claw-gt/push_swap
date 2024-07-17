/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:46:00 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/17 16:31:40 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//sa
void sa(t_list **stack_a)
{
	t_list *tmp1;
	t_list *tmp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	write(1, "sa\n", 3);
}
//sb
void sb(t_list **stack_b)
{
	t_list *tmp1;
	t_list *tmp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp1 = *stack_b;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	write(1, "sb\n", 3);
}
//ss
void ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}