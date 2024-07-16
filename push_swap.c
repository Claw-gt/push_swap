/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/16 19:40:12 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void process_stack(t_stack **stack_a, int *initial_array)
{
	int i;

	i = 0;
	while (initial_array[i] != '\0')
	{
		ft_lstadd_back(stack_a, ft_lstnew(initial_array[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	int		*initial_array;

	initial_array = parse_input(argc,argv);
	if (initial_array == NULL)
		return (1);
	process_stack(stack_a, initial_array);
	return (0);
}
