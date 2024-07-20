/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:25:57 by clagarci          #+#    #+#             */
/*   Updated: 2024/07/20 21:14:45 by clagarci         ###   ########.fr       */
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

long int	ft_atoi_optim(const char *nptr)
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
	return (num);
}

void	*print_errors(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

int	check_duplicates(int *array, int argc)
{
	/*Iterar por initial_array y comprobar que no haya ningún número duplicado*/
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < (argc - 2))
	{
		while (j < (argc - 1))
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

// int	*to_number(char **array, int arguments)
// {
// 	int	i;

// 	i = -1;
// 	while(i++ < arguments)
// 	{
		
// 	}
// }

int	*parse_input (int argc, char *argv[])
{
	int	i;
	int	*initial_array;
	//char *char_array;
	int	arguments;
	//int	pos;
	char	**temp;
	int	length;
	//int	j;

	//pos = 0;
	i = 1;
	arguments = 0;
	//j = -1;
    if (argc < 2)
        return(print_errors());
    else
	{	
		//Hacer ft_split para casos "1  2". Esto debe ser considerado como dos argumentos separados (1 y 2).
		/*Comprobar que los argumentos sean números enteros no mezclados con letras. Atoi optimizado*/
		initial_array = (int*)malloc(sizeof(int) * argc); //argc puede no ser el nº de argummentos totales
		if (!initial_array)
			return (NULL);
		while (i < argc)
		{
			length = 0;
			printf("args:%s\n",argv[i]);
			temp = ft_split(argv[i], ' ');
			//TODO: Contar argumentos de temp y free (temp)
			while (temp[length] != NULL)
				length++;
			printf("length: %d", length);
			/*Comprobar que los argumentos entran dentro de los límites INT_MIN-INT_MAX */
			/*Comprobar primero que los argumentos solo incluyan '"' " " '-' '+' o números?*/
			if (str_isdigit(temp, length) == -1)
			{
				free_array(temp, length);
				//free(initial_array);
				return (print_errors());
			}
			arguments += length;
			printf("arguments: %d", arguments);
			// while (j++ < length)
			// {
			// 	printf("\ntemp:%s", temp[j]);
			// 	initial_array[pos] = ft_atoi_optim(temp[j]);
			// 	if (initial_array[pos] == -1)
			// 	{
			// 		free_array (temp, length);
			// 		free (initial_array);
			// 		return (print_errors());
			// 	}
			// 	pos++;
			// }
			//free_array(temp,length);
			// initial_array[pos] = ft_atoi_optim(argv[i]);
			// if (initial_array[pos] == -1)
			// {
			// 	printf("entra");
			// 	free (initial_array);
			// 	return (print_errors());
			// }
			i++;
			//pos++;
		}
	}
	//chequear dspués de guardar todos los números en el array de enteros?
	// if (check_duplicates(initial_array, argc) == -1)
	// {
	// 	write(1, "adios", 5);
	//  	free (initial_array);
	//  	return(print_errors());
	// }
	return (initial_array);
	//return (temp);
}