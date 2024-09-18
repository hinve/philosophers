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
		$(SRCS_DIR)writes.c					\
		$(SRCS_DIR)utils.c					\
		$(SRCS_DIR)philo.c					\
		$(SRCS_DIR)init.c					\
		$(SRCS_DIR)threads.c				\
		$(SRCS_DIR)philo_actions.c 			\
		$(SRCS_DIR)routines.c 				\

OBJS_SRCS = $(OBJ_DIR)main.o				\
			$(OBJ_DIR)writes.o				\
			$(OBJ_DIR)utils.o				\
			$(OBJ_DIR)philo.o				\
			$(OBJ_DIR)init.o				\
			$(OBJ_DIR)threads.o				\
			$(OBJ_DIR)philo_actions.o		\
			$(OBJ_DIR)routines.o			\

CFLAGS = -Wall -Werror -Wextra -g -I$(INC_DIR) #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS_SRCS)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOUR_BLUE)Compiling $(COLOUR_YELLOW)philo$(COLOUR_END)"
	@gcc $(CFLAGS) $(OBJS_SRCS) -o $(BIN_DIR)$(NAME)
	@echo "$(COLOUR_GREEN)✅ READY ✅$(COLOUR_END)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_SRCS) $(OBJ_DIR)
	@echo "❌ $(COLOUR_RED)Making clean$(COLOUR_END)  ❌"

fclean:
	@rm -rf $(NAME) $(OBJS_SRCS) $(OBJ_DIR) $(BIN_DIR)
	@echo "❌ $(COLOUR_RED)Making fclean$(COLOUR_END) ❌"

re: fclean all

.PHONY: all clean fclean re