/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:16:28 by clagarci          #+#    #+#             */
/*   Updated: 2024/02/04 12:44:40 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	leaks(void){
	system("leaks -q a.out");
}

void	del(void *content)
{
	free(content);
}

void	print(void *content)
{
	printf("printin:");
	printf("%s\n", (char *)content);
}

void	*to_upper(void *content)
{
	char	*ptr;

	ptr = (char *)content;
	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;
		ptr++;
	}
	return (content);
}

int	main(void)
{
	atexit(leaks);
	/*t_list	*node;
	char	str[] = "hello";
	
	node = ft_lstnew(str);
	printf("%s\n", node->content);
	free (node);*/
	//////////////////////////
	t_list	*begin;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*new_one;
	
	begin = NULL; //no elements
	char *str = ft_strdup("hello"); //allocate dinamic memory to be able to free it
	node1 = ft_lstnew(str);
	char *str2 = ft_strdup("World"); //allocate dinamic memory to be able to free it
	node2 = ft_lstnew(str2);
	//node2 = ft_lstnew("World"); //cannot be freed because it is not allocated dinamically
	char *str3 = ft_strdup("hola"); //allocate dinamic memory to be able to free it
	node3 = ft_lstnew(str3); 
	ft_lstadd_back(&begin, node1);
	ft_lstadd_back(&begin, node2);
	ft_lstadd_back(&begin, node3);
	//ft_lstadd_front(&begin, node1);
	//ft_lstadd_front(&begin, node2);
	printf("length:%d\n", ft_lstsize(begin));
	printf("%s\n", (char *)node3->content);
	//printf("%s\n", ft_lstlast(begin)->content);

	ft_lstiter(begin, print);
	new_one = ft_lstmap(begin, &to_upper, free);
	//ft_lstclear(&new_one,free);
	ft_lstiter(new_one, print);
	
	/*while (new_one != NULL)
	{
		printf("%s\n", (char *)new_one->content);
		new_one =  new_one->next;
	}*/
	//ft_lstdelone(node3, del);
	//printf("%s\n", (char *)node3->content); Segmentation fault since memory has been freed
	//ft_lstclear(&new_one, free);
	free(node3);
	free(str3);
	free (node1);
	free (node2);
	free (str); //free porqu han sido creadas con ft_strdup
	free (str2);
	//no hace falta free(str3) pues ya o hace internament ft_lstdelone(node3)
	//ft_lstclear(&begin, del); //free all the memory allocated for the list
	//printf("length:%d\n", ft_lstsize(begin));
	//ft_lstclear(&new_one, del);
}
