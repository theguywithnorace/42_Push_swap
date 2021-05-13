
NAME		= libft.a

SRCS		=	ft_itoa.c ft_putendl_fd.c ft_putstr_fd.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c \
				ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c\
				ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c\
				ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c\
				ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c\
				 ft_substr.c ft_strjoin.c ft_split.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c get_next_line_utils.c ft_strcmp.c\
				ft_max.c ft_min.c ft_strmapi.c ft_abs.c

LIB			= ../libft.a

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

OBJS		= ${SRCS:.c=.o}

.c.o:
	gcc -c -I ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rc ${LIB} ${OBJS}  
	ranlib ${LIB}  


all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${LIB}

re:		fclean all

.PHONY:	all clean fclean re libft.a
