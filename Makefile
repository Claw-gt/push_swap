# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:23:32 by clagarci          #+#    #+#              #
#    Updated: 2024/06/18 20:56:21 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MY_SOURCES = 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"
clean:
	rm -f $(MY_OBJECTS)
	@echo "\nObjects files deleted!"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(NAME) deleted!"

re: fclean all

.PHONY: all clean fclean re