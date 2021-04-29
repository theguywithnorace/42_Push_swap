SRC_DIR			= srcs/

SRC				=	execute_instructions.c initialize.c instructions_1.c\
						instructions_2.c parser_arguments.c parser_instructions.c\
						ps_move.c ps_check.c error.c

SRCS				= ${addprefix ${SRC_DIR}, ${SRC}}

OBJ_DIR			=	obj/

HDR_DIR			= includes/

LIBPS			= libs/libps.a

RM				= rm -f

OBJS			= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS}}

${OBJ_DIR}%.o	: ${SRC_DIR}%.c
	gcc -c -I ${HDR_DIR} -c -o $@ $<


all:	${OBJS}
	mkdir -p libs obj	
	cd libft && make && cd ..
	ar rcs ${LIBPS} ${OBJS}
	gcc -o checker checker.c  -I includes -Llibs -lft -lps
	gcc -o push_swap push_swap.c  -I includes -Llibs -lft -lps

oho:
	echo ${OBJS}

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
