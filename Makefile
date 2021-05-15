NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

SRC_DIR 	= srcs/

SRC			= execute_instructions.c initialize.c instructions_1.c\
			instructions_2.c parser_arguments.c parser_instructions.c\
			ps_move.c ps_check_1.c ps_check_2.c error.c print.c freeing.c\
			bonus.c ps_send.c ps_pvt.c ps_actions.c ps_actions_to_a.c \
			ps_opti_1.c ps_opti_2.c print_2.c ps_actions_2.c ps_actions_3.c

SRCS		= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ 		= ${SRC:.c=.o}

OBJ_DIR 	= obj/

OBJS		= ${addprefix ${OBJ_DIR}, ${OBJ}}


${NAME}: ${OBJS}
	gcc -o  push_swap srcs/ps.c ${CFLAGS} ${OBJS} -I includes -L. -lft

# mkdir -p obj
# @make  -s -C libft
${OBJ_DIR}%.o: ${SRC_DIR}%.c
	make -s -C libft
	gcc -c -I includes ${CFLAGS} -c -o $@ $<

all: ${NAME}

checker:
	gcc -o  checker srcs/ck.c ${CFLAGS}  ${OBJS}  -I includes  -L. -lft

clean:
	${RM} .DS_Store
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} checker


re: fclean all

.PHONY:	all clean fclean re



