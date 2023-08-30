SOURCES	=	ft_bzero.c ft_memset.c ft_calloc.c ft_itoa.c

NAME 			= libft.a

OBJECTS 		= $(SOURCES:.c=.o)

CC 				= gcc

RM 				= rm -rf

CFLAGS 			= -Wall -Werror -Wextra

all: 			$(NAME)


$(NAME): 		$(OBJECTS)
			$(AR) rc $(NAME) $(OBJECTS)

clean:
				$(RM) $(OBJECTS)

fclean: 		clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re