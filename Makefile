##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for ftrace
##

NAME         =		    ftrace

INCLUDE      =         -I include/ -I include/lib/ -L lib/ \
                       -lmy -lmyprintf -lformatstring

CFLAGS       +=         -Wall -Wextra -pedantic \
					        -Wstrict-prototypes -fstack-protector\
					        -Wold-style-definition -std=c99 $(INCLUDE)

SOURCES      =         src/

MAIN		 =         $(SOURCES)main.c

SRC          =         $(SOURCES)ftrace.c \
			           $(SOURCES)stack.c	 \
					   $(SOURCES)get_maps.c \
					   $(SOURCES)get_errno_code.c \
					   $(SOURCES)get_syscall.c \
					   $(SOURCES)print_syscall.c \
					   $(SOURCES)check_syscall.c \
					   $(SOURCES)check_funccall.c \
					   $(SOURCES)print/print_env.c \
					   $(SOURCES)print/print_num.c \
					   $(SOURCES)print/print_string.c \
					   $(SOURCES)print/print_pointer.c \
					   $(SOURCES)print/print_struct_stat.c \
					   $(SOURCES)print/print_void_ptr.c \

TESTS		 =		   tests/syscalls.c \
					   tests/print.c	\
					   tests/ftrace.c	\

SRC_COUNT    =         $(words $(SRC))

NB           =         0

OBJ          =	        $(SRC:.c=.o)
OBJ			+=			$(MAIN:.c=.o)

TEMPFILES    =         *~ *vgcore* *.gcda *.html *.gcno unit_tests #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

all:	$(NAME)

$(NAME):	$(OBJ)
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@make -C lib/my/ --no-print-directory
			@make -C lib/myprintf/ --no-print-directory
			@make -C lib/formatstring/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3 -pg
debug:		all

clean:
			@make -C lib/my/ clean --no-print-directory
			@make -C lib/myprintf/ clean --no-print-directory
			@make -C lib/formatstring/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C lib/myprintf/ fclean --no-print-directory
			@make -C lib/formatstring/ fclean --no-print-directory
			@make -C lib/my/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

tests_run:
			@make -C lib/my/ --no-print-directory
			@make -C lib/myprintf/ --no-print-directory
			@make -C lib/formatstring/ --no-print-directory
			@gcc -o unit_tests -Wall -Wextra $(SRC) $(TESTS) $(INCLUDE) \
				-lcriterion --coverage
			@./unit_tests

coverage:	tests_run
			@gcovr -r . --exclude tests/
			@gcovr -b --exclude tests/
			@gcovr --exclude tests/ --html --html-details -o coverage.html
			@xdg-open coverage.html

docs:		fclean
			@doxygen Doxyfile
			@xdg-open doc/html/index.html

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python3 build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug
