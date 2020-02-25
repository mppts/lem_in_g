SRC_DIR			=	srcs
INCLUDES_DIR	=	includes
OBJ_DIR			=	obj

CHK_DIR			=	checkers
GNL_DIR			=	get_next_line
LST_DIR			=	lst
MEM_DIR			=	mem
PUT_DIR			=	put
STRCH_DIR		=	str_change
STR_DIR			=	string
TONUM_DIR		=	to_num
DSTR_DIR		=	dstr
BINHEAP_DIR		=	binary_heap

CHK		=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c

GNL		=	ft_get_next_line.c\
			ft_get_next_line2.c

LST		=	ft_del.c \
            ft_lstadd.c \
            ft_lstdel.c \
            ft_lstdelone.c \
            ft_lstiter.c \
            ft_lstmap.c \
            ft_lstnew.c

MEM		=	ft_bzero.c \
            ft_memalloc.c \
            ft_memccpy.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memdel.c \
            ft_memmove.c \
            ft_memset.c

PUT		=	ft_putchar.c \
            ft_putchar_fd.c \
            ft_putendl.c \
            ft_putendl_fd.c \
            ft_putnbr.c \
            ft_putnbr_fd.c \
            ft_putstr.c \
            ft_putstr_fd.c

STRCH	=	ft_itoa.c \
            ft_tolower.c \
            ft_toupper.c

STR		=	ft_strcat.c \
            ft_strchr.c \
            ft_strchrcount.c \
            ft_strclr.c \
            ft_strcmp.c \
            ft_strcpy.c \
            ft_strdel.c \
            ft_strdup.c \
            ft_strequ.c \
            ft_striter.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmap.c \
            ft_strmapi.c \
            ft_strncat.c \
            ft_strncmp.c \
            ft_strncpy.c \
            ft_strnequ.c \
            ft_strnew.c \
            ft_strnlen.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strsplit.c \
            ft_strstr.c \
            ft_strsub.c \
            ft_strtolower.c \
            ft_strtoupper.c \
            ft_strtrim.c

TONUM	=	ft_atoli.c \
            ft_atoi.c

DSTR	=	dstr.c\
			dstr2.c

BIN_HEAP = bin_free.c\
		 bin_get_root.c\
         bin_inc_key.c\
         bin_insert.c\
         bin_remove_root.c\
         bin_swap.c\
         binary_init.c\

FILES			+=	$(CHK) \
					$(GNL) \
					$(LST) \
					$(MEM) \
					$(PUT) \
					$(STRCH) \
					$(STR) \
					$(TONUM) \
					$(DSTR) \
					$(BIN_HEAP)

FILES_WITH_PATH	=	$(addprefix ./$(SRC_DIR)/$(CHK_DIR)/, $(CHK))\
					$(addprefix ./$(SRC_DIR)/$(GNL_DIR)/, $(GNL))\
					$(addprefix ./$(SRC_DIR)/$(LST_DIR)/, $(LST))\
					$(addprefix ./$(SRC_DIR)/$(MEM_DIR)/, $(MEM))\
					$(addprefix ./$(SRC_DIR)/$(PUT_DIR)/, $(PUT))\
					$(addprefix ./$(SRC_DIR)/$(STRCH_DIR)/, $(STRCH))\
					$(addprefix ./$(SRC_DIR)/$(STR_DIR)/, $(STR))\
					$(addprefix ./$(SRC_DIR)/$(TONUM_DIR)/, $(TONUM))\
					$(addprefix ./$(SRC_DIR)/$(DSTR_DIR)/, $(DSTR)) \
					$(addprefix ./$(SRC_DIR)/$(BINHEAP_DIR)/, $(BIN_HEAP))

OBJ				=	$(FILES:%.c=%.o)
OBJS			=	$(FILES:%.c=./$(OBJ_DIR)/%.o)

.PHONY:				all clean fclean re dirs

FLAGS = -Wall -Werror -Wextra

NAME	= libft.a

all: $(NAME)

$(NAME): dirs
				gcc $(FLAGS) -c $(FILES_WITH_PATH) -Iincludes/
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)

dirs:
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%o:$(FILES_WITH_PATH)%c
				gcc $(FLAGS) -o $@ -c $< -Iincludes/

clean:
				@rm -f $(OBJ_DIR)/$(OBJ)
				@rm -f $(OBJ)
				@rm -rf $(OBJ_DIR)

fclean: clean
				@rm -f $(NAME)

re: fclean all