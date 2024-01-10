# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:16:50 by vsanz-su          #+#    #+#              #
#    Updated: 2024/01/10 13:47:45 by vsanz-su         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME		= push_swap

#INSTRUCTIONS
CC			= gcc -I $(INCLUDE) -MMD -g
RM 			= rm -rf

#FOLDERS
INCLUDE = ./includes/
SRC_DIR = src
OBJ_DIR = obj

#FILES
SRC_FILES		= $(SRC_DIR)/main.c

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEP_FILES = $(addsuffix .d, $(basename $(SRC_FILES)))

#DEPENDENCIES
LIBFT_SRC = $(INCLUDE)libft
FT_LINK = -L$(LIBFT_SRC) -lft

#RULES
all:
	$(MAKE) -C $(LIBFT_SRC)
	$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
				mkdir -p $(dir $@)
				$(CC) -c $< -o $@

-include $(DEP_FILES)

$(NAME): $(OBJ_FILES)
		$(CC) $(OBJ_FILES) $(FT_LINK) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES) $(DEP_FILES)
	$(RM) ./$(OBJ_DIR)
	$(MAKE) -C $(LIBFT_SRC) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_SRC) fclean

re: fclean all

.PHONY: all clean fclean re
