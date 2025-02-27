NAME	:= megaphone

CC		:= c++

CFLAGS	:= -Wall -Werror -Wextra -std=c++98 -g

SRCS	:= megaphone.cpp \

OBJS	:= megaphone.o

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

