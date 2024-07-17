/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/17 16:59:14 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list **process_stack(t_list **stack_a, int *initial_array)
{
	int i;

	i = 0;
	while (initial_array[i] != '\0')
	{
		ft_lstadd_back(stack_a, ft_lstnew(&initial_array[i]));
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	int		*initial_array;

	initial_array = parse_input(argc,argv);
	if (initial_array == NULL)
		return (1);
	stack_a = NULL;
	stack_a = process_stack(stack_a, initial_array);
	return (0);
}
