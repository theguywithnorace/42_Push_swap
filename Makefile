SRC_DIR			= srcs/

SRC				=	execute_instructions.c initialize.c instructions_1.c\
						instructions_2.c parser_arguments.c parser_instructions.c\
						ps_move.c ps_check_1.c ps_check_2.c error.c print.c freeing.c\
						bonus.c ps_send.c ps_pvt.c ps_actions.c ps_actions_to_a.c

SRCS				= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ_DIR			=	obj/

HDR_DIR			= includes/

RM				= rm -f

CFLAGS		= -Wall -Wextra -Werror

OBJS			= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}

${OBJ_DIR}%.o	: ${SRC_DIR}%.c
#	mkdir -p obj
	gcc -c -I ${HDR_DIR} ${CFLAGS} -c -o $@ $<


all:	${OBJS}
	cd libft && make && cd ..
	gcc -o  checker srcs/ck.c ${CFLAGS}  ${OBJS} -I includes  -L. -lft
	gcc -o  push_swap srcs/ps.c ${CFLAGS} ${OBJS} -I includes -L. -lft

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
