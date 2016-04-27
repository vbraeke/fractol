# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 17:41:41 by vbraeke           #+#    #+#              #
#    Updated: 2016/04/26 17:41:44 by vbraeke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS =	-lmlx -framework OpenGl -framework AppKit

SRC = main.c libft/libft.a julia.c init.c mandle.c

$(NAME):
	@make -C libft/
	@echo Libft created ! 1/5
	@gcc -o $(NAME) $(FLAGS) $(SRC)
	@echo Compiled ! 2/5
	
clean:	
	@make -C libft/ fclean
	@echo Cleaned ! 3/5

fclean: clean
	@rm -f $(NAME)
	@echo Fcleaned ! 4/5

re : fclean $(NAME)
	@echo  On recommance tout ma biche !  5/5

.PHONY: all clean fclean re
