
NAME = libasm.a

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test
TEST_OBJ_DIR = test_obj

SRC := $(wildcard $(SRC_DIR)/*.s)
OBJ := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC))
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))
TEST_BIN = test_binary

CC = gcc
NASM = nasm
NASM_FLAGS = -f macho64  # NASM flags for 64-bit output format for MACOS, for linux use elf64
RM = rm -f
RMDIR = rm -rf

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)   # Ensure ar creates the library and adds an index (ranlib is automatically invoked with -s)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	@$(NASM) $(NASM_FLAGS) -o $@ $<

$(TEST_OBJ_DIR):
	@mkdir -p $(TEST_OBJ_DIR)

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OBJ_DIR)
	@$(CC) -o $@ -c $<

$(TEST_BIN): $(NAME) $(TEST_OBJ)
	@$(CC) -o $(TEST_BIN) $(TEST_OBJ) $(NAME)

test: $(TEST_BIN)
	@./$(TEST_BIN)

clean:
	@$(RM) $(OBJ_DIR)/*.o
	@$(RM) $(TEST_OBJ_DIR)/*.o
	@$(RMDIR) $(OBJ_DIR) $(TEST_OBJ_DIR)
	@$(RM) $(TEST_BIN)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
