/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:05:07 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	leaks(void){
	system("leaks -q a.out");
}

t_stack *process_stack(t_stack **stack_a, int *initial_array, int arguments)
{
	int i;
	//t_stack *temp;

	i = 0;
	//temp = *stack_a;
	while (i < arguments)
	{
		ft_stckadd_back(stack_a, ft_stcknew(initial_array[i]));
		i++;
	}
	// while(temp)
	// {
	// 	printf("temp->content: %d\n", temp->content);
	// 	temp = temp->next;
	// }
	quick_sort(initial_array, 0, arguments - 1);
	stack_indexing(stack_a, initial_array);
	// t_stack *check = *stack_a;
	// while(check)
	// {
	// 	printf("check->content: %d\n", check->content);
	// 	printf("check->index: %d\n", check->index);
	// 	check = check->next;
	// }
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
	// int i = 0;
	// while (i < arguments)
	// {
	// 	printf("\ninitial_array[%d]: %d\n", i, initial_array[i]);
	// 	i++;
	// }
	stack_a = NULL;
	stack_a = process_stack(&stack_a, initial_array, arguments);
	free (initial_array);
	sort_stack(&stack_a);
	//test_sort(&stack_a);
	//test_sort_three(&stack_a);
	//test_operations(&stack_a);
	//atexit (leaks);
	return (0);
}
