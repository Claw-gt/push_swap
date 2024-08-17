/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:04:53 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/07 15:55:54 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stcklast(t_stack *stck)
{
	if (stck == NULL)
		return (NULL);
	while (stck->next != NULL)
		stck = stck->next;
	return (stck);
}

void	ft_stckclear(t_stack **stck)
{
	t_stack	*current;
	t_stack	*temp;

	if (stck != NULL)
	{
		current = *stck;
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free (temp);
		}
		free (current);
		*stck = NULL;
	}
}

t_stack	*ft_stcknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_stckadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*temp;

	if (!stck || !new)
		return ;
	if (*stck == NULL)
		*stck = new;
	else
	{
		temp = *stck;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int	ft_stcksize(t_stack *stck)
{
	int	length;

	length = 0;
	while (stck != NULL)
	{
		length++;
		stck = stck->next;
	}
	return (length);
}