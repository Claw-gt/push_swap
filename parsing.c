/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/17 16:52:57 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_optim(const char *nptr)
{
	int	i;
	int	minus;
	int	num;

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
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
    if (nptr[i] != ' ' && (nptr[i] < 9 || nptr[i] > 13) && nptr[i] != '\0')
	{
        return (-1);
	}
	if (minus)
		num *= -1;
	printf("num: %d\n", num);
	return (num);
}

void	*print_errors(void)
{
    //ft_printf("Error\n");
	//printf("Error\n");
	write(1, "Error\n", 6);
	return (NULL);
}

int	check_duplicates(int *array)
{
	/*Iterar por initial_array y comprobar que no haya ningún número duplicado*/
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (array[i] != '\0')
	{
		while (array[j] != '\0')
		{
			if (array[i] == array[j])
				return (-1);
			j++;
		}
		i++;
	}
    return (0);
}

int	*parse_input (int argc, char *argv[])
{
	int	i;
	int	*initial_array;
	int	pos;
	//t_list stack_a;
	
	pos = 0;
	i = 1;
	//stack_a = NULL;
    if (argc < 2)
        print_errors();
    else
	{
		/*Comprobar que los argumentos sean números enteros no mezclados con letras. Atoi optimizado*/
		//printf("num args: %d\n", argc);
		initial_array = (int*)malloc(sizeof(int) * argc);
		if (!initial_array)
			return (NULL);
		while (i < argc)
		{
			printf("args:%s\n",argv[i]);
			/*Comprobar primero que los argumentos solo incluyan '"' " " '-' '+' o números?*/
			initial_array[pos] = ft_atoi_optim(argv[i]);
			if (initial_array[pos] == -1)
			{
				free (initial_array);
				return (print_errors());
			}
			else
			{
				//chequea duplicados sin haber pasado todos los argumentos a número para mandar el Error cuanto antes
				if (check_duplicates(initial_array) == -1)
				{
					free (initial_array);
					return(print_errors());
				}	
			}
			i++;
			pos++;
		}
	}
	return (initial_array);
}