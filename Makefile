# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:16:50 by vsanz-su          #+#    #+#              #
#    Updated: 2024/01/18 15:26:43 by vsanz-su         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME		= push_swap
NAME_BONUS = checker

#INSTRUCTIONS
CC			= gcc -Wall -Wextra -Werror -MMD -g -I$(INCLUDE) 
RM 			= rm -rf

#FOLDERS
INCLUDE = ./includes/
SRC_DIR = src
OBJ_DIR = obj

#FILES
SRC_FILES		= $(SRC_DIR)/main.c \
	$(SRC_DIR)/moves/push.c \
	$(SRC_DIR)/moves/rev_rotate.c \
	$(SRC_DIR)/moves/rotate.c \
	$(SRC_DIR)/moves/swap.c \
	$(SRC_DIR)/args.c \
	$(SRC_DIR)/count_steps.c \
	$(SRC_DIR)/print.c \
	$(SRC_DIR)/sort_reverse.c \
	$(SRC_DIR)/sort_utils.c \
	$(SRC_DIR)/sort.c \
	$(SRC_DIR)/utils_ft_list.c \
	$(SRC_DIR)/utils_get.c \
	$(SRC_DIR)/utils.c \

SRC_FILES_BONUS = $(SRC_DIR)/checker_bonus.c \
	$(SRC_DIR)/moves/push.c \
	$(SRC_DIR)/moves/rev_rotate.c \
	$(SRC_DIR)/moves/rotate.c \
	$(SRC_DIR)/moves/swap.c \
	$(SRC_DIR)/args.c \
	$(SRC_DIR)/count_steps.c \
	$(SRC_DIR)/print.c \
	$(SRC_DIR)/sort_reverse.c \
	$(SRC_DIR)/sort_utils.c \
	$(SRC_DIR)/sort.c \
	$(SRC_DIR)/utils_ft_list.c \
	$(SRC_DIR)/utils_get.c \
	$(SRC_DIR)/utils.c \

OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
BONUS_OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC_FILES_BONUS))
DEP = $(addsuffix .d, $(basename $(SRC_FILES)))
BONUS_DEP = $(addsuffix .d, $(basename $(SRC_FILES_BONUS)))

#DEPENDENCIES
LIBFT_SRC = $(INCLUDE)libft
FT_LINK = -L$(LIBFT_SRC) -lft

#RULES
all:
	$(MAKE) -C $(LIBFT_SRC) 
	$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(FT_LINK) -o $(NAME)

-include $(DEP)

$(NAME_BONUS): $(BONUS_OBJ)
		$(CC) $(BONUS_OBJ) $(FT_LINK) -o $(NAME_BONUS)

-include $(BONUS_DEP)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(DEP) $(BONUS_OBJ) $(BONUS_DEP)
	$(RM) ./$(OBJ_DIR)
	$(MAKE) -C $(LIBFT_SRC) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_SRC) fclean

re: fclean all

.PHONY: all clean fclean re bonus