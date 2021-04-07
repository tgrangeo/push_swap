HEADER =	libft.h

SRCS =		ft_strlen.c ft_isdigit.c ft_putnbr_fd.c\
			ft_atoi.c ft_strdup.c ft_strchr.c ft_putchar_fd.c\
			ft_substr.c ft_strjoin.c ft_itoa.c \
			get_next_line.c get_next_line2.c ft_count.c\

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

GREEN	=	\033[0;32m

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ compiled."
$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)libft compiled ...$(NC)"
	@ar rcs $(NAME) $(OBJS)
bonus:		$(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)
clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
re: 	fclean all
