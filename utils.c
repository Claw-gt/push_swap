/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:12:25 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/28 16:19:55 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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