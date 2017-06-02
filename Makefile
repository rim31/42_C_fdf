# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 10:22:04 by oseng             #+#    #+#              #
#    Updated: 2016/02/12 20:21:07 by oseng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GC = gcc

FLAG = -I $(INCLUDE) -lmlx -framework OpenGl -framework AppKit

SRCS =	ft_linehoriz.c\
		ft_parse.c\
		get_next_line.c\
		ft_lineverti.c\
		ft_strnbr.c\
		ft_draw.c\
		ft_mapping.c\
		ft_xyz.c\
		mlx_pixel_put_to_image.c\
		ft_inival.c\
		ft_mlx_line.c\
		ft_zrot.c\
		my_key_function.c\
		main.c\

LIBFT_PATH = ./libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INCLUDE = fdf.h

NAME = fdf

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		@echo "\033[92mCompiling"
		@make re -C $(LIBFT_PATH)
		@$(GC) -o $(NAME) -Wall -Wextra -Werror $(SRCS) $(FLAG) $(LIBFT)
		@echo "\033[96mDone"
		@make fclean -C $(LIBFT_PATH)

clean:
		@echo "\033[92mDeleting"
		@rm -f $(OBJ)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mClean done"


fclean: clean
		@echo "\033[92mDeleting"
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mFclean Done"

re: fclean all

.PHONY: all clean fclean re
