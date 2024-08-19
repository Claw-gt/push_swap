/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:53:48 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 18:17:22 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	str_isdigit(char **string, int arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arguments)
	{
		if ((string[i][j] == '-' || string[i][j] == '+') && \
		ft_isdigit(string[i][j + 1]) != 0)
			j++;
		while (string[i][j] != '\0')
		{
			if (ft_isdigit(string[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_atoi_optim(const char *nptr, int *error_flag)
{
	int			i;
	int			minus;
	long int	num;

	minus = 0;
	i = 0;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (minus)
		num *= -1;
	if (num > INT_MAX || num < INT_MIN)
		*error_flag = -1;
	return ((int)num);
}

int	contains_num(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] >= '0' && string[i] <= '9')
			return (0);
		i++;
	}
	return (1);
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
