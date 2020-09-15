# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpace <bpace@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 18:41:43 by bpace             #+#    #+#              #
#    Updated: 2019/10/23 23:28:44 by bpace            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCC = srcs/* \

NAME = lem_in

all: $(NAME)

$(NAME):
		@make -C libft re
		@gcc -g -Wall -Werror -Wextra $(SRCC) libft/libft.a -o lem_in

clean:
			@make -C libft clean

fclean:
			@make -C libft fclean
			@/bin/rm -f $(NAME)

re: fclean all
