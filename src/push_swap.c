/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/20 14:58:53 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*print_errors(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

t_stack	*process_stack(t_stack **stack_a, int *initial_array, int arguments)
{
	int	i;

	i = 0;
	while (i < arguments)
	{
		ft_stckadd_back(stack_a, ft_stcknew(initial_array[i]));
		i++;
	}
	quick_sort(initial_array, 0, arguments - 1);
	stack_indexing(stack_a, initial_array);
	return (*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		arguments;
	int		*initial_array;

	if (argc < 2)
		return (0);
	arguments = initial_check(argc, argv);
	if (arguments == -1)
		return (1);
	initial_array = parse_input(arguments, argc, argv);
	if (initial_array == NULL)
		return (1);
	stack_a = NULL;
	stack_a = process_stack(&stack_a, initial_array, arguments);
	free (initial_array);
	sort_stack(&stack_a);
	return (0);
}
