/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:37:01 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/20 17:27:33 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	write(1, "*********\n", 10);
	write(1, "Stack A\n", 8);
	while (tmp)
	{
		ft_putnbr_fd(tmp->content, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "*********\n", 10);
}
