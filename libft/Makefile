NAME	=	libft.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC_DIR = srcs/

SRC			= ft_itoa.c ft_putendl_fd.c ft_putstr_fd.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c \
				ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c\
				ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c\
				ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c\
				ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c\
				 ft_substr.c ft_strjoin.c ft_split.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c get_next_line_utils.c ft_strcmp.c\
				ft_max.c ft_min.c ft_strmapi.c ft_abs.c

SRCS			= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ = ${SRC:.c=.o}

OBJ_DIR = obj/

OBJS			= ${addprefix ${OBJ_DIR}, ${OBJ}}


${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	mkdir -p obj
	gcc -c -I includes ${CFLAGS} -c -o $@ $<

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
