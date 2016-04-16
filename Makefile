# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/29 14:04:21 by jle-quer          #+#    #+#              #
#    Updated: 2016/04/16 16:18:10 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	add_files.c \
			date.c \
			display.c \
			error.c \
			print_size.c \
			read_path.c \
			recursive.c \
			size_info.c \
			sort_elem.c \
			main.c

NAME = ft_ls

FLAGS = -Wall -Werror -Wextra

LIB = ./Libft/libft.a

OBJET = $(SRC_NAME:.c=.o)

all: $(NAME)
	@echo "Make In Progress"
	@echo "Make Done."

$(NAME): $(LIB) $(OBJET)
	@gcc $(FLAGS) $(OBJET) -L./Libft/ -lft -o $(NAME)

$(LIB):
	make -C ./Libft/

%.o: %.c
	@gcc $(FLAGS) -I./Libft/INCLUDES -c $<

clean:
	@echo "Clean In Progress"
	@rm -f $(OBJET)
	@echo "Clean Done."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

proper:
	@make
	@make clean -C ./Libft/
	@make clean
