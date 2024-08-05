/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/28 16:27:09 by clagarci         ###   ########.fr       */
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

int	count_and_check(int num_args, char **argv)
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

/*Initial check*/

/*Store and transform to numbers if checks OK*/
int split_and_store(char *string_argument, int **int_array, int pos)
{
	int 	length;
	char	**temp;
	int		j;

	length = 0;
	j = -1;
	temp = ft_split(string_argument, ' ');
	while (temp[length] != NULL)
		length++;
	while (j++ < length - 1)
	{
		(*int_array)[pos] = ft_atoi_optim(temp[j]);
		if ((*int_array)[pos] == -1)
		{
			free_array (temp, length);
			free (*int_array);
			return (-1);
		}	
		pos++;
	}
	free_array(temp,length);
	return (length);
}

int	*parse_input(int arguments, int argc, char *argv[])
{
	int	i;
	int	*initial_array;
	int	pos;
	//char	**temp;
	int	length;
	//int	j;

	pos = 0;
	i = 1;
	initial_array = (int*)malloc(sizeof(int) * arguments);
	if (!initial_array)
		return (NULL);
	while (i < argc)
	{
		length = 0;
		// j = -1;
		// printf("args:%s\n",argv[i]);
		// temp = ft_split(argv[i], ' ');
		// while (temp[length] != NULL)
		// 	length++;
		// if (str_isdigit(temp, length) == -1)
		// {
		// 	free_array(temp, length);
		// 	free(initial_array);
		// 	return (print_errors());
		// }
		//////////////////////////////
		/*Store as numbers if check OK*/

		// while (j++ < length - 1)
		// {
		// 	initial_array[pos] = ft_atoi_optim(temp[j]);
		// 	if (initial_array[pos] == -1)
		// 	{
		// 		free_array (temp, length);
		// 		free (initial_array);
		// 		return (print_errors());
		// 	}
		// 	printf("\ninitial array[%d]: %d\n", pos, initial_array[pos]);
		// 	pos++;
		// }
		// free_array(temp,length);
		length = split_and_store(argv[i], &initial_array, pos);
		if (length == -1)
			return (print_errors());
		//printf("\ninitial array[%d]: %d\n", pos, initial_array[pos]);
		pos += length;
		i++;

	}
	if (check_duplicates(initial_array, arguments) == -1)
	{
	 	free (initial_array);
	 	return(print_errors());
	}
	return (initial_array);
}
