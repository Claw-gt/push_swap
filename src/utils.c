/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:53:48 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 17:57:54 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	leaks(void)
{
	system("leaks -q a.out");
}

int	abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

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

void	*print_errors(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}