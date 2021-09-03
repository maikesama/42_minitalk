CC = gcc -Wall -Werror -Wextra

CLIENT = client

SERVER = server

SRCS_C = client.c

SRCS_S = server.c

OBJS_C = ${SRCS_C:.c=.o}

OBJS_S = ${SRCS_S:.c=.o}

LIBS = -L./Libraries/ft_printf -L./Libraries/libft -lftprintf -lft

all: lib $(CLIENT) $(SERVER)

$(CLIENT):$(OBJS_C)
	$(CC) -o $(CLIENT) $(OBJS_C) $(LIBS)

$(SERVER):$(OBJS_S)
	$(CC) -o $(SERVER) $(OBJS_S) $(LIBS)

lib:
	make -C ./Libraries/libft
	make -C ./Libraries/ft_printf

clean: cleanclient cleanserver

cleanclient:
	rm -f $(CLIENT) $(OBJS_C)

cleanserver:
	rm -f $(SERVER) $(OBJS_S)

cleanlib:
	make fclean -C ./Libraries/libft
	make fclean -C ./Libraries/ft_printf

fclean: cleanclient cleanserver cleanlib

re: clean all

reclient: cleanclient client

reserver: cleanserver server