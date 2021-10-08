NAME		= minitalk

CLIENT		= client

SERVER		= server

SRCS_CL		= ${shell find ./srcs/client*.c}

SRCS_SE		= ${shell find ./srcs/server*.c}

OBJS_CL		= $(SRCS_CL:.c=.o)

OBJS_SE		= $(SRCS_SE:.c=.o)

HEADER		= ${shell find ./includes/*.h}

LIBFT		= ./libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJS_CL)
	make -C libft
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CL) $(LIBFT) -L ./libft -lft

$(SERVER) : $(OBJS_SE)
	make -C libft
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SE) $(LIBFT) -L ./libft -lft

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS_CL)
	rm -f $(OBJS_SE)
	make clean -C libft

fclean : clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re