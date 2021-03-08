# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 12:28:00 by fballest          #+#    #+#              #
#    Updated: 2021/01/05 09:31:15 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIB_DIR     =   libft/
OBJ_DIR     =   obj/
SRC_DIR     =   src/
SRC_FILES = ft_printf.c ft_checkflags.c ft_checktype.c ft_checktype2.c ft_checktype3.c\
			ft_setprint.c ft_setprint2.c ft_setprint3.c ft_utils.c
SRC = $(SRC_FILES:%=$(SRC_DIR)%)
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LFLAGS = -I includes/
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib
all:    $(OBJ_DIR) $(NAME)
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: ft_printf Object directory
$(NAME):    $(OBJ)
			@echo Loading libft
			@make -C $(LIB_DIR)
			@cp $(LIB_DIR)$(LIBFT) ./$(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo =====DONE=====
$(OBJ): $(SRC)
		@$(MAKE) $(OBJ_FILES)
$(OBJ_FILES):
		@$(CC) $(FLAGS) $(LFLAGS) -c -o $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
clean:
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJS)
		@make -C $(LIB_DIR) clean
fclean: clean
		@$(RM) $(NAME)
		@make -C $(LIB_DIR) fclean
re: fclean all
.PHONY: all clean fclean re
