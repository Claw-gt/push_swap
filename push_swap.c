/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 16:11:30 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *process_stack(t_stack **stack_a, int *initial_array, int arguments)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = *stack_a;
	while (i < arguments)
	{
		ft_stckadd_back(stack_a, ft_stcknew(initial_array[i]));
		//ft_lstadd_back(stack_a, ft_lstnew(&initial_array[i]));
		i++;
	}
	//(*stack_a)->next = NULL;
	while(temp)
	{
		//printf("temp->content: %d\n", *(int *)temp->content);
		printf("temp->content: %d\n", temp->content);
		temp = temp->next;
	}
	quick_sort(initial_array, 0, arguments - 1);
	stack_indexing(stack_a, initial_array);
	//(*stack_a)->size = arguments;
	//printf("midpoint = %d\n", check_midpoint((*stack_a)->size));
	t_stack *check = *stack_a;
	while(check)
	{
		printf("check->content: %d\n", check->content);
		printf("check->index: %d\n", check->index);
		check = check->next;
	}
	return (*stack_a);
}

int	initial_check(int argc, char **argv)
{
	int	total_args;

	total_args = 0;
	total_args = count_and_check(argc - 1, argv);
	if (argc < 2 || total_args == -1)
	{	
		print_errors();
		return (-1);
	}
	return (total_args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		arguments;
	int		*initial_array;

	arguments = initial_check(argc, argv);
	if (arguments == -1)
		return (1);
	initial_array = parse_input(arguments, argc, argv);
	if (initial_array == NULL)
		return (1);
	int i = 0;
	while (i < arguments)
	{
		printf("\ninitial_array[%d]: %d\n", i, initial_array[i]);
		i++;
	}
	stack_a = NULL; //importante para evitar error con fsanitize
	stack_a = process_stack(&stack_a, initial_array, arguments);
	free (initial_array);
	sort_stack(&stack_a);
	//test_sort(&stack_a);
	//test_sort_three(&stack_a);
	//test_operations(&stack_a);
	return (0);
}
