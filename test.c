/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:25:33 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 13:08:31 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_operations(t_stack **stack)
{
    t_stack *stack_b;
    t_stack *tmp;
    //t_stack *tmp2;

    stack_b = NULL;
    printf("\n****************\nBefore operation\n");
    tmp = *stack;
    //tmp2 = stack_b;
    while (tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
    pb(stack, &stack_b);
    pb(stack, &stack_b);
    sa(stack);
    printf("Size of B: %d", calculate_size(stack_b));
    printf("After operation\n");
    tmp = *stack;
    while (tmp)
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }
    printf("Stack B\n");
    while (stack_b)
    {
        printf("%d\n", stack_b->index);
        stack_b = stack_b->next;
    }
    ft_stckclear(&stack_b);
    printf("****************\n");
}

void test_sort_three(t_stack **stack)
{
    t_stack *tmp;

    printf("\n****************\nBefore operation\n");
    tmp = *stack;
    while (tmp)
    {
        printf("%d %d\n", tmp->index, tmp->content);
        tmp = tmp->next;
    }
    sort_three(stack);
    printf("After operation\n");
    tmp = *stack;
    while (tmp)
    {
        printf("%d %d\n", tmp->index, tmp->content);
        tmp = tmp->next;
    }
    printf("****************\n");
}