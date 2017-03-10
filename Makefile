##
## Makefile for Makefile in /home/dams/delivery/CPE/CPE_2016_matchstick/
##
## Made by Damien Laurent
## Login   <damien.laurent@epitech.eu@epitech.eu>
##
## Started on  Mon Feb 13 18:13:54 2017 Damien Laurent
## Last update Fri Mar 10 16:06:37 2017 Damien Laurent
##

SRCS	=	reveil.c		\
				parsing.c		\
				get_next_line.c		\
				song.c					\
				linkedlist.c

SRC1	=	set.c

SRC2 	= add_rev.c		\
				get_next_line.c

OBJ		=		$(SRCS:.c=.o)

OBJ1		=		$(SRC1:.c=.o)

OBJ2		=		$(SRC2:.c=.o)


NAME		=		reveil

NAME1		=		set

NAME2		=		add

CC		=		gcc -g -O3 -Wextra -Wall -lc_graph_prog

all: $(NAME) $(NAME1) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME1): $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all
