# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:49:02 by tparratt          #+#    #+#              #
#    Updated: 2024/05/02 12:05:20 by tparratt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo

SRC         = philo.c check_args.c actions.c utils.c thread_functions.c mutexes.c
OBJ         = $(SRC:.c=.o)

CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 
# -fsanitize=thread -pthread

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
