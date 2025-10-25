NAME = megaphone
CC = g++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98

SRCS = Contact.cpp Phonebook.cpp main.cpp \

HEADER = Contact.hpp Phonebook.hpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(HEADER) $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re