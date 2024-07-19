/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:25:33 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/19 18:24:09 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test(t_stack **stack)
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
    //printf("B: %d", stack_b->index);
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
    printf("****************\n");
}