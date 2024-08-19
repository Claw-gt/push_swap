/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:02:13 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:07:26 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*free_array(char **arr, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}
