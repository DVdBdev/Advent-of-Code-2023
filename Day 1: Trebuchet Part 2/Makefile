NAME = trebuchet2
LIBFT = ../Libft-plus/libft.a
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = inc
CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR)
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJ		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(GREEN)✨ $(NAME) compiled!$(DEF_COLOR)"

$(LIBFT):
	@make -C ../Libft-plus

clean:
	@make clean -C ../Libft-plus
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🗑️  object files!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  executable files!$(DEF_COLOR)"

re: fclean all

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
