# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:23:32 by clagarci          #+#    #+#              #
#    Updated: 2024/08/16 14:43:14 by clagarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = -lft #for the name of the *.a file. Here the "lib" prefix and ".a" extension is not mentioned
LIBDIR = libft/

MY_SOURCES = src/push_swap.c src/parsing.c src/operations/push.c src/operations/swap.c src/operations/rotate.c src/operations/reverse_rotate.c \
			src/linked_stacks.c src/indexing.c src/sorting/sort_three.c src/sorting/sort_more.c src/sorting/sort.c src/positioning.c src/count_moves.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror #-fsanitize=address
#CFLAGS += -I./libft #for specifying the directory of *.h header file
LDFLAGS = -L ./libft #for specifying the directory to be used for -l

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		make -C $(LIBDIR)
		make bonus -C $(LIBDIR)
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(LDFLAGS) $(LIBS)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"

#$(LIBDIR)/libft.a:
#		make -C $(LIBDIR) --no-print-directory
#		@echo "\n Compilation of $(LIBDIR): SUCCESS!"

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(MY_OBJECTS)
	@echo "\nObjects files of push_swap deleted!"
	@make clean -C libft --no-print-directory
	@echo "\nObjects files of libft deleted!"

fclean: clean
	rm -f $(NAME)
	@echo "\n$(NAME) deleted!"
	@make fclean -C libft --no-print-directory

re: fclean all

.PHONY: all clean fclean re