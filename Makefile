COLOUR_GREEN = \033[0;32m
COLOUR_RED = \033[0;31m
COLOUR_BLUE = \033[0;34m
COLOUR_YELLOW = \033[0;33m
COLOUR_END = \033[0m

NAME = philo

INC_DIR = inc/
OBJ_DIR = objs/
SRCS_DIR = src/
BIN_DIR = bin/

SRCS = $(SRCS_DIR)main.c					\
		$(SRCS_DIR)write_errors.c					\

OBJS_SRCS = $(OBJ_DIR)main.o				\
			$(OBJ_DIR)write_errors.o				\

CFLAGS = -Wall -Werror -Wextra -g -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS_SRCS)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOUR_BLUE)Compilando archivos de $(COLOUR_YELLOW)philo$(COLOUR_END)"
	@gcc $(CFLAGS) $(OBJS_SRCS) -o $(BIN_DIR)$(NAME)
	@echo "$(COLOUR_GREEN)✅ LISTO ✅$(COLOUR_END)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_SRCS) $(OBJ_DIR)
	@echo "❌ $(COLOUR_RED)Efectuando clean$(COLOUR_END)  ❌"

fclean:
	@rm -rf $(NAME) $(OBJS_SRCS) $(OBJ_DIR) $(BIN_DIR)
	@echo "❌ $(COLOUR_RED)Efectuando fclean$(COLOUR_END) ❌"

re: fclean all

.PHONY: all clean fclean re