SRC_DIR			= srcs/

SRC				=	execute_instructions.c initialize.c instructions_1.c\
						instructions_2.c parser_arguments.c parser_instructions.c\
						ps_move.c ps_check_1.c ps_check_2.c error.c print.c freeing.c\
						bonus.c

SRCS				= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ_DIR			=	obj/

HDR_DIR			= includes/

LIBPS			= libps.a

RM				= rm -f

CFLAGS		= -Wall -Wextra -Werror

OBJS			= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}

${OBJ_DIR}%.o	: ${SRC_DIR}%.c
	mkdir -p obj libs
	gcc -c -I ${HDR_DIR} -L. -lft ${CFLAGS} -c -o $@ $<


all:	${OBJS}
	mkdir -p obj	
	cd libft && make && cd ..
	ar rcs ${LIBPS} ${OBJS}
	gcc -o  checker srcs/ck.c ${CFLAGS} -I includes  -L. -lft -lps
	gcc -o  push_swap srcs/ps.c ${CFLAGS} -I includes -L. -lft -lps

clean:
	${RM} ${OBJS}
	${RM} .DS_Store
	${RM} push_swap
	${RM} checker

fclean:		clean
	cd libft && make fclean && cd ..
	${RM} ${LIBPS}

re:		fclean all

.PHONY:	all clean fclean re 
