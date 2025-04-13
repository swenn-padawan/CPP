NAME	:= Animal

CC	:=	c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS	:= Animal.cpp \
		   Dog.cpp \
		   Cat.cpp \
		   WrongAnimal.cpp \
		   WrongCat.cpp \
		   main.cpp \

BUILD	:= .objs

OBJS	:= $(addprefix $(BUILD)/, $(SRCS:%.cpp=%.o))

MAKEFLAGS	+= --no-print-directory

RM			:= rm -rf

DIR_UP		= mkdir -p $(@D)

################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo " $(GREEN)$(BOLD)$(ITALIC)■$(RESET)  building	$(GREEN)$(BOLD)$(ITALIC)$(NAME)$(RESET)"

$(BUILD)/%.o: %.cpp
	@$(DIR_UP)
	@echo " $(CYAN)$(BOLD)$(ITALIC)■$(RESET)  compiling	$(GRAY)$(BOLD)$(ITALIC)$^$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(BUILD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

################################################################################


BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
MAGENTA		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
GRAY		=	\033[90m

BOLD		=	\033[1m
ITALIC		=	\033[3m

RESET		=	\033[0m
LINE_CLR	=	\33[2K\r
