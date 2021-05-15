SRC_DIR			= srcs/

SRC				=	execute_instructions.c initialize.c instructions_1.c\
						instructions_2.c parser_arguments.c parser_instructions.c\
						ps_move.c ps_check_1.c ps_check_2.c error.c print.c freeing.c\
						bonus.c ps_send.c ps_pvt.c ps_actions.c ps_actions_to_a.c \
						ps_opti_1.c ps_opti_2.c print_2.c ps_actions_2.c ps_actions_3.c

OBJ              = ${SRC:.c=.o}

SRCS			= ${addprefix ${SRC_DIR}, ${SRC}}

OBJS			= ${addprefix ${OBJ_DIR}, ${OBJ}}

OBJ_DIR			=	obj/

HDR_DIR			= includes/

RM				= rm -f

CFLAGS		= -Wall -Wextra -Werror

${OBJ_DIR}%.o	: ${SRC_DIR}%.c
# mkdir -p obj
# @make  -s -C libft
	gcc -c -I ${HDR_DIR} ${CFLAGS} -c -o $@ $<


all:	${OBJS} 
	gcc -o  push_swap srcs/ps.c ${CFLAGS} ${OBJS} -I includes -L. -lft

checker:
	gcc -o  checker srcs/ck.c ${CFLAGS}  ${OBJS}  -I includes  -L. -lft

clean:
	${RM} ${OBJS}
	cd libft && make clean && cd ..
	${RM} .DS_Store

fclean:		clean
	cd libft && make fclean && cd ..
	${RM} push_swap
	${RM} checker

re:		fclean all

.PHONY:	all clean fclean re 
