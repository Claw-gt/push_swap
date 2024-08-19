/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/08/19 18:17:13 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates(int *array, int arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < arguments - 1)
	{
		while (j < arguments)
		{
			if (array[i] == array[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	count_and_check(int num_args, char **argv)
{
	int		i;
	int		arguments;
	char	**temp;
	int		length;

	arguments = 0;
	i = 0;
	while (i++ < num_args)
	{
		length = 0;
		if (contains_num(argv[i]) == 1)
			return (-1);
		temp = ft_split(argv[i], ' ');
		while (temp[length] != NULL)
			length++;
		if (str_isdigit(temp, length) == -1)
		{
			free_array(temp, length);
			return (-1);
		}
		arguments += length;
		free_array (temp, length);
	}
	return (arguments);
}

int	split_and_store(char *string_argument, int **int_array, int pos)
{
	int		length;
	char	**temp;
	int		j;
	int		error_flag;

	length = 0;
	j = -1;
	error_flag = 0;
	temp = ft_split(string_argument, ' ');
	while (temp[length] != NULL)
		length++;
	while (j++ < (length - 1))
	{
		(*int_array)[pos] = ft_atoi_optim(temp[j], &error_flag);
		if (error_flag == -1)
		{
			free_array (temp, length);
			free (*int_array);
			return (-1);
		}
		pos++;
	}
	free_array(temp, length);
	return (length);
}

int	*parse_input(int arguments, int argc, char *argv[])
{
	int	i;
	int	*initial_array;
	int	pos;
	int	length;

	pos = 0;
	i = 1;
	initial_array = (int *)malloc(sizeof(int) * arguments);
	if (!initial_array)
		return (NULL);
	while (i < argc)
	{
		length = 0;
		length = split_and_store(argv[i], &initial_array, pos);
		if (length == -1)
			return (print_errors());
		pos += length;
		i++;
	}
	if (check_duplicates(initial_array, arguments) == -1)
	{
		free(initial_array);
		return (print_errors());
	}
	return (initial_array);
}

int	initial_check(int argc, char **argv)
{
	int	total_args;
	int	i;
	int	j;

	j = 0;
	i = 1;
	total_args = 0;
	while (i < argc)
	{
		if (argv[i][j] == '\0')
		{
			print_errors();
			return (-1);
		}
		i++;
	}
	total_args = count_and_check(argc - 1, argv);
	if (total_args == -1)
	{
		print_errors();
		return (-1);
	}
	return (total_args);
}
