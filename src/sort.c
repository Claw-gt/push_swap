/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:59:35 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/16 18:10:56 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int check_sorted(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
    {
        if (tmp->index > tmp->next->index)
            return (-1);
        tmp = tmp->next;
    }
    return (0);
}

void sort_stack(t_stack **stack_a)
{
	// t_stack	*tmp;

	// tmp = *stack_a;
	if (check_sorted(*stack_a) != 0)
	{
        if (ft_stcksize(*stack_a) == 2)
            sa(stack_a);
        else if (ft_stcksize(*stack_a) == 3)
            sort_three(stack_a);
        else
            sort_more(stack_a);    
        //else if (optimization(stack_a) == -1)
            //sort_more(stack_a);
 
    }
	// printf("Stack A\n");
	// tmp = *stack_a;
	// while (tmp)
    // {
    //     printf("%d\n", tmp->index);
    //     tmp = tmp->next;
    // }
	// printf("****************\n");
}