# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:46:00 by nvaubien          #+#    #+#              #
#    Updated: 2023/02/27 12:52:28 by nvaubien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -g -fsanitize=address
#FLAGS		= -Wall -Werror -Wextra $(OS_FLAG)
FLAGS		= $(OS_FLAG)

### EXECUTABLE ###

NAME		= fractol

UNAME_S 	= $(shell uname -s)


ifeq ($(UNAME_S), Linux)
	LINUX_LIB = -lXext -lX11
	FRAMEWORK =
	LINUX_INCLUDE = -I/usr/include
	OS_FLAG = -D Linux
else 
	FRAMEWORK	= -framework OpenGL -framework AppKit
	LINUX_LIB	= 
	LINUX_INCLUDE	=
	OS_FLAG 	= -D OSX
endif

### INCLUDES ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
HEADERS		= incl

ifeq ($(UNAME_S), Darwin)
	MLX			= libmlx
	MLXNAME		= libmlx.dylib
else
	MLX	= mlx_linux
	MLXNAME = libmlx.a 
endif

MLX_INCLUDES	= -I./$(MLX)

### SOURCE FILE ###

SOURCES		=	main.c						\
				libft.c						\
				complex-numbers.c			\
				conversion-coordinates.c	\
				events.c					\
				events-man.c				\
				rendering.c					\
				utils.c						\
				fractals-algo.c				\
				color.c						\
				zoom.c						\
				info-parameters.c			\

### OBJETCTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

### RULES ###

LIBFT_DIRECTORY = ./libs/
LIBFTPRINTF		= $(LIBFTPRINTF_DIRECTORY)libftprintf.a
LIBFTPRINTF_DIRECTORY		= $(LIBFT_DIRECTORY)ftprintf/

all:		mlx tmp printf $(NAME)

$(NAME):	$(OBJ) $(OBJS)
			@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
			$(CC) $(OBJ) $(OBJS) $(FLAGS) -Llibs/ftprintf -lftprintf -L. -lm -lmlx $(FRAMEWORK) $(LINUX_LIB) $(MLX_INCLUDES) $(LINUX_INCLUDE) -o $(NAME)
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

mlx:
			make -C $(MLX)
			@cp $(MLX)/$(MLXNAME) .
			@echo "$(CYAN)######## LIBMLX.A Created ######## $(WHITE)"

printf:
			make -sC $(LIBFTPRINTF_DIRECTORY)
			cp $(LIBFTPRINTF) .
tmp:		
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) $(LINUX_INCLUDE) $(MLX_INCLUDES) -I$(MLX) -O2 -c $< -o $@

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			make clean -C $(MLX)
			make clean -C $(LIBFTPRINTF_DIRECTORY) 
			@rm -rf $(OBJS_PATH)


fclean:		clean
			@rm -rf libmlx.dylib
			@rm -rf $(NAME)
			@rm -f libmlx.a
			@rm -f libftprintf.a

re:			fclean all

.PHONY:		mlx clean, fclean, re, tmp
