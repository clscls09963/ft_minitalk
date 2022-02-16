CC = gcc
CFLAGS = -Wextra -Wall -Werror
AR = ar rcs

NAME1 = server
NAME2 = client
NAME3 = server_bonus
NAME4 = client_bonus

S_SRC = server.c \
		serverutile.c

C_SRC = client.c \
		clientutile.c

SB_SRC = server_bonus.c\
		serverutile.c\
		server_bonus2.c

CB_SRC = client_bonus.c\
		clientutile.c

OBJS1 = $(S_SRC:.c=.o)
OBJS2 = $(C_SRC:.c=.o)
OBJS3 = $(SB_SRC:.c=.o)
OBJS4 = $(CB_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME3): $(OBJS3)
	$(CC) $(CFLAGS) $^ -o $@ 

$(NAME4): $(OBJS4)
	$(CC) $(CFLAGS) $^ -o $@ 

all: $(NAME1) $(NAME2)

bonus: $(NAME3) $(NAME4)

fclean: clean
	rm -rf $(NAME1) $(NAME2) $(NAME3) $(NAME4)

clean:
	rm -rf $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)

re: fclean all
