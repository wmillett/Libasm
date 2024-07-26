NAME = libasm.a

SRC_DIR = src
OBJ_DIR = obj

SRC := $(wildcard $(SRC_DIR)/*.s)
OBJ := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC))

RM = rm -f
RMDIR = rm -rf

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@ar -cr $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@as -o $@ $<

clean:
	@$(RM) $(OBJ_DIR)/*.o
	@$(RMDIR) $(OBJ_DIR) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
