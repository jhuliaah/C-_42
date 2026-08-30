
NAME = account
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = ./obj/
SRC = Account.cpp tests.cpp
OBJS = $(addprefix $(OBJS_FOLDER), $(SRC:.cpp=.o))
LOG = $(shell date +%Y%m%d_%H%M%S).log 2>&1

all: $(OBJS_FOLDER) $(NAME)
	@./$(NAME) > $(LOG)
	@rm -rf $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_FOLDER)%.o: %.cpp | $(OBJS_FOLDER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_FOLDER):
	@mkdir -p $(OBJS_FOLDER)

clean:
	@rm -rf $(OBJS_FOLDER)

fclean: clean
	@rm -rf $(NAME) *.log

re: fclean all

.PHONY: all clean fclean re