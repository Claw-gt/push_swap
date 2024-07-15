/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:45:17 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/15 18:57:19 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pa
void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}
//pb
void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}