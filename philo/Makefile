# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rocky <rocky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 23:53:26 by rocky             #+#    #+#              #
#    Updated: 2022/12/17 00:17:07 by rocky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
CFLAGS = -Wall -Wextra -Werror
SRCS = ./a_eat_enough.c ./dup_info.c ./e_philo_alive.c ./eat.c ./ft_atoi.c ./ft_calloc.c ./get_time_now.c ./init_monitor.c ./main.c ./ph_input_err_handler.c ./philo_destroy.c ./philo_game.c ./philo_life.c ./philo.c ./print.c ./spend_time.c ./str_is_int.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJS);

fclean : clean
	rm -rf $(NAME);

re :
	make fclean
	make all

.PHONY: all clean fclean re