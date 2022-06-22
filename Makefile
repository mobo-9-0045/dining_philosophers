# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 23:55:07 by aomman            #+#    #+#              #
#    Updated: 2022/06/04 23:55:09 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = philosophers.c philo_utils.c thread_stuff.c philo_death.c

NAME = philo

all : ${NAME}

${NAME} :
		gcc -Wall -Wextra -Werror -fsanitize=thread ${SRCS} -o ${NAME}

clean :
	rm -f ${NAME}

flcean : clean
re : flcean all
