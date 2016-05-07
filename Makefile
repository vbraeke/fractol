# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikus <mikus@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 17:41:41 by vbraeke           #+#    #+#              #
#    Updated: 2016/05/07 15:37:36 by vbraeke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGSMLX = -lmlx  -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -O3 

SRC = main.c libft/libft.a julia.c init.c mandle.c burn.c mix.c event.c

$(NAME):
	@make -C libft/
	@echo Libft created ! 1/5
	@gcc $(FLAGS) -o $(NAME) $(FLAGSMLX) $(SRC)
	@echo Compiled ! 2/5
	
clean:	
	@make -C libft/ fclean
	@echo Cleaned ! 3/5

fclean: clean
	@rm -f $(NAME)
	@echo Fcleaned ! 4/5

re : fclean $(NAME)
	@echo  SUCCESS !  5/5

.PHONY: all clean fclean re
