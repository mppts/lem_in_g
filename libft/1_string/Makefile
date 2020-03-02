.PHONY: all clean fclean re directories

DIR_SRC = srcs/
DIR_INC = -I../includes/
DIR_OBJ = ../obj/

SRC = ft_strcat.c\
      ft_strchr.c\
      ft_strchrcount.c\
      ft_strclr.c\
      ft_strcmp.c\
      ft_strcpy.c\
      ft_strdel.c\
      ft_strdup.c\
      ft_strequ.c\
      ft_striter.c\
      ft_striteri.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strmap.c\
      ft_strmapi.c\
      ft_strncat.c\
      ft_strncmp.c\
      ft_strncpy.c\
      ft_strnequ.c\
      ft_strnew.c\
      ft_strnlen.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strsplit.c\
      ft_strstr.c\
      ft_strsub.c\
      ft_strtolower.c\
      ft_strtoupper.c\
      ft_strtrim.c

HEADERS =	ft_string.h

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)
DEP = $(OBJ:%.o=%.d)
SRCS = $(SRC:%.c=$(DIR_SRC)%.c)
OBJS = $(SRC:%.c=$(DIR_OBJ)%.o)
DEPS = $(SRC:%.c=$(DIR_OBJ)%.d)

MKDIR_P = mkdir -p

all: directories $(OBJS)

directories:
	@$(MKDIR_P) $(DIR_OBJ)

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	gcc $(FLAGS) -MD -o $@ -c $< $(DIR_INC)
include $(wildcard *.d)


clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

re: clean all
