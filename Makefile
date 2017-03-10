##
## Makefile for Makefile in /home/dams/delivery/CPE/CPE_2016_matchstick/
##
## Made by Damien Laurent
## Login   <damien.laurent@epitech.eu@epitech.eu>
##
## Started on  Mon Feb 13 18:13:54 2017 Damien Laurent
## Last update Fri Mar 10 11:58:56 2017 Damien Laurent
##

SRCS	=	reveil.c		\
				parsing.c		\
				get_next_line.c		\
				song.c					\
				linkedlist.c

OBJ		=		$(SRCS:.c=.o)

NAME		=		reveil

CC		=		gcc -g -O3 -Wextra -Wall -lc_graph_prog

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
