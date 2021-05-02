SRC_DIR			= srcs/

SRC				=	execute_instructions.c initialize.c instructions_1.c\
						instructions_2.c parser_arguments.c parser_instructions.c\
						ps_move.c ps_check.c error.c print.c freeing.c

SRCS				= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ_DIR			=	obj/

HDR_DIR			= includes/

LIBPS			= libs/libps.a

RM				= rm -f

CFLAGS		= -Wall -Wextra -Werror

OBJS			= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}

${OBJ_DIR}%.o	: ${SRC_DIR}%.c
	mkdir -p obj libs
	gcc -c -I ${HDR_DIR} ${CFLAGS} -c -o $@ $<


all:	${OBJS}
	mkdir -p libs obj	
	cd libft && make && cd ..
	ar rcs ${LIBPS} ${OBJS}
	gcc -g -o  checker ck.c  -I includes -Llibs -lft -lps
	gcc -g -o  push_swap ps.c  -I includes -Llibs -lft -lps

clean:
	${RM} ${OBJS}
#	cd libft && make clean && cd ..
	${RM} .DS_Store
	${RM} push_swap
	${RM} checker

fclean:		clean
	cd libft && make fclean && cd ..
	${RM} ${LIB}

re:		fclean ${NAME}

.PHONY:	all clean fclean re 
