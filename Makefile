NAME = lem-in

.PHONY : all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = includes/
DIR_OBJ = obj/

LIB = libft.a
DIR_LIB	= $(LIB:.a=/)
LIB_INCLUDES = $(LIB:.a=/includes/)

SOURCE = \
         main.c\
         man_err.c\
         parse_hash.c\
         parse_links.c\
         parse_map.c\
         parse_room.c\
         parse_room2.c\
		 parse_utils.c\
		 solver_dijkstra.c\
         solver_ek.c\
         solver_ek2.c\
         solver_tools.c\
         solver_bfs.c\
         deque.c\
         deque2.c\
         writer_main_new.c\
		 writer_push_ants.c


HEADERS =	lem_in.h \
			libft.h \
			binary_heap.h

FLAGS = -Wall -Wextra -Werror -g3
FLAGS = 
OBJ = $(SOURCE:%.c=%.o)
OBJS = $(SOURCE:%.c=$(DIR_OBJ)%.o)
SRCS = $(SOURCE:%.c=$(DIR_SRC)%.c)

all: $(NAME)

$(NAME): $(LIB) directories $(OBJS)
	gcc -g3 $(FLAGS) -o $(NAME) $(OBJS) -L$(DIR_LIB) -lft

directories:
	mkdir -p $(DIR_OBJ)

$(LIB):
	$(MAKE) -C $(DIR_LIB)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc -g3 $(FLAGS) -o $@ -c $< -I$(DIR_INC) -I$(LIB_INCLUDES)

clean:
	rm -f $(DIR_OBJ)*.o
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
