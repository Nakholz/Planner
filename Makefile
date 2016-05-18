##
## Makefile for  in /home/arnhol_m/rendu/synth/agenda
## 
## Made by martin Arnholz
## 
## Started on  Mon Jun 29 14:03:25 2015 martin Arnholz
## Last update Mon Apr 25 14:26:52 2016 
##

CC	= gcc -g3

CFLAGS	= -W -Wall -Wextra -I./include/

RM	= rm -f

NAME	= Planner

SRC	= srcs/list.c \
	  srcs/print_opt.c \
	  srcs/get_next_line.c \
	  srcs/strtok.c \
	  srcs/pars.c \
	  srcs/add_list.c \
	  srcs/main.c

OBJS	= $(SRC:.c=.o)

all	: $(NAME)
	  @echo "$(NAME) \\033[1;36m COMPILATION FINISHED \\033[0;39m"

.c.o	:
	 @$(CC) $(CFLAGS) -c -o $@ $<
	 @echo " $(CC) $(CFLAGS) -c -o $@ $< \\033[1;32m OK \\033[0;39m"

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
	@$(RM) $(OBJS)
	@$(RM) *~
	@echo " $(RM) $(OBJS) \\033[1;31m DELETING \\033[0;39m"
	@echo " $(RM) *~ \\033[1;31m DELETING \\033[0;39m"

fclean	: clean
	@$(RM) $(NAME)
	@echo " $(RM) *~ \\033[1;31m DELETING \\033[0;39m"

re	: fclean all

.PHONY	: fclean all re
