# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 13:42:41 by aandric           #+#    #+#              #
#    Updated: 2022/09/28 15:29:07 by aandric          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = 			philo

SRC_FILES =  	main.c \
				check_input.c \
				data.c \
				utils.c \
				philo.c \
				check_routine.c \
				routine.c \

SRC = 			${addprefix src/, ${SRC_FILES}}
OBJS = 			${SRC:.c=.o}
HEADERS = 		includes/philo.h

CMD = 			gcc
FLAGS = 		-Wall -Werror -Wextra

%.o: 			%.c $(HEADERS)
				$(CMD) $(FLAGS) -c $< -o $@
all:			${NAME}

$(NAME): 		$(OBJS) Makefile
				$(CMD) ${FLAGS} -o ${NAME} ${OBJS}

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean all re fclean