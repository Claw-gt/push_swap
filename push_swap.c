/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:10:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/18 15:33:05 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *process_stack(t_stack **stack_a, int *initial_array, int argc)
{
	int i;

	i = 0;
	while (i < (argc - 1))
	{
		ft_stckadd_back(stack_a, ft_stcknew(initial_array[i]));
		//ft_lstadd_back(stack_a, ft_lstnew(&initial_array[i]));
		i++;
	}
	//(*stack_a)->next = NULL;
	t_stack *temp = *stack_a;
	while(temp)
	{
		//printf("temp->content: %d\n", *(int *)temp->content);
		printf("temp->content: %d\n", temp->content);
		temp = temp->next;
	}
	quick_sort(initial_array, 0, argc - 2);
	return (*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*initial_array;

	initial_array = parse_input(argc,argv);
	if (initial_array == NULL)
		return (1);
	int i = 0;
	while (i < (argc - 1))
	{
		printf("initial_array[%d]: %d\n", i, initial_array[i]);
		i++;
	}
	//stack_a = (t_stack **)malloc(sizeof(t_stack*));
	//if (!stack_a)
	//	return (1);
	stack_a = NULL; //importante para evitar error con fsanitize
	stack_a = process_stack(&stack_a, initial_array, argc);
	t_stack *temp = stack_a;
	while(temp)
	{
		//printf("temp->content: %d\n", *(int *)temp->content);
		printf("temp->content: %d\n", temp->content);
		temp = temp->next;
	}
	free (initial_array);
	return (0);
}
