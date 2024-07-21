/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/21 12:58:46 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	str_isdigit(char **string, int arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arguments)
	{
		printf("argument check: %s", string[i]);
		//string = ft_split(string[i], ' '); //para casos donde se mezclan "" con " " e.g "2     "
		while(string[i][j] != '\0')
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

int	ft_atoi_optim(const char *nptr)
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
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	if (minus)
		num *= -1;
	if (num > INT_MAX || num < INT_MIN)
		return (-1);
	printf("num: %ld\n", num);
	return ((int)num);
}

void	*print_errors(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

int	check_duplicates(int *array, int arguments)
{
	/*Iterar por initial_array y comprobar que no haya ningún número duplicado*/
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
int	count_arguments(int num_args, char **argv)
{
	int		i;
	int		arguments;
	char	**temp;
	int 	length;

	arguments = 0;
	i = 0;
	while (i++ < num_args)
	{
		length = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[length] != NULL)
			length++;
		arguments += length;
		free_array (temp, length);
	}
	return (arguments);
}
int	to_number(char **split_array, int num_args, int **int_array, int position) //paso por parámetro mi array
{
	int	i;

	i = -1;
	while(i++ < num_args)
	{
		*int_array[position] = ft_atoi_optim(split_array[i]);
		if (*int_array[position] == -1)
			return (-1);
		position++;
	}
	return (0);
}

// int	*parse_input (int argc, char *argv[])
// {
// 	int	i;
// 	int arguments;
// 	int	*initial_array;
// 	//char *char_array;
// 	int	pos;
// 	char	**temp;
// 	int	length;
// 	int	j;

// 	pos = 0;
// 	i = 1;
// 	arguments = 0;
//     if (argc < 2)
//         return(print_errors());
//     else
// 	{	
// 		arguments = count_arguments(argc - 1, argv);
// 		printf("\nTotal arguments: %d\n", arguments);
// 		//Hacer ft_split para casos "1  2". Esto debe ser considerado como dos argumentos separados (1 y 2).
// 		/*Comprobar que los argumentos sean números enteros no mezclados con letras. Atoi optimizado*/
// 		initial_array = (int*)malloc(sizeof(int) * arguments); //argc puede no ser el nº de argumentos totales, por eso uso arguments
// 		if (!initial_array)
// 			return (NULL);
// 		while (i < argc)
// 		{
// 			length = 0;
// 			j = -1;
// 			printf("args:%s\n",argv[i]);
// 			temp = ft_split(argv[i], ' ');
// 			//TODO: Contar argumentos de temp y free (temp)
// 			while (temp[length] != NULL)
// 				length++;
// 			/*Comprobar que los argumentos entran dentro de los límites INT_MIN-INT_MAX */
// 			/*Comprobar primero que los argumentos solo incluyan '"' " " '-' '+' o números?*/
// 			if (str_isdigit(temp, length) == -1)
// 			{
// 				free_array(temp, length);
// 				free(initial_array);
// 				return (print_errors());
// 			}
// 			// if (to_number(temp, length, &initial_array, pos) == -1)
// 			// {
// 			// 	free_array (temp, length);
// 			// 	free (initial_array);
// 			// 	return (print_errors());
// 			// }
// 			// free_array(temp, length);
// 			while (j++ < length - 1)
// 			{
// 				initial_array[pos] = ft_atoi_optim(temp[j]);
// 				if (initial_array[pos] == -1)
// 				{
// 					free_array (temp, length);
// 					free (initial_array);
// 					return (print_errors());
// 				}
// 				printf("\ninitial array[%d]: %d\n", pos, initial_array[pos]);
// 				pos++;
// 			}
// 			free_array(temp,length);
// 			// initial_array[pos] = ft_atoi_optim(argv[i]);
// 			// if (initial_array[pos] == -1)
// 			// {
// 			// 	printf("entra");
// 			// 	free (initial_array);
// 			// 	return (print_errors());
// 			// }
// 			i++;
// 			//pos += length;
// 		}
// 	}
// 	//chequear dspués de guardar todos los números en el array de enteros?
// 	if (check_duplicates(initial_array, arguments) == -1)
// 	{
// 	 	free (initial_array);
// 	 	return(print_errors());
// 	}
// 	return (initial_array);
// 	//return (temp);
// }

int	*parse_input (int arguments, int argc, char *argv[])
{
	int	i;
	int	*initial_array;
	int	pos;
	char	**temp;
	int	length;
	int	j;

	pos = 0;
	i = 1;
	initial_array = (int*)malloc(sizeof(int) * arguments);
	if (!initial_array)
		return (NULL);
	while (i < argc)
	{
		length = 0;
		j = -1;
		printf("args:%s\n",argv[i]);
		temp = ft_split(argv[i], ' ');
		while (temp[length] != NULL)
			length++;
		if (str_isdigit(temp, length) == -1)
		{
			free_array(temp, length);
			free(initial_array);
			return (print_errors());
		}
		while (j++ < length - 1)
		{
			initial_array[pos] = ft_atoi_optim(temp[j]);
			if (initial_array[pos] == -1)
			{
				free_array (temp, length);
				free (initial_array);
				return (print_errors());
			}
			printf("\ninitial array[%d]: %d\n", pos, initial_array[pos]);
			pos++;
		}
		free_array(temp,length);
		i++;

	}
	if (check_duplicates(initial_array, arguments) == -1)
	{
	 	free (initial_array);
	 	return(print_errors());
	}
	return (initial_array);
}