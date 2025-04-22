NAME = libasm.a

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = test
TEST_OBJ_DIR = test_obj

SRC := $(wildcard $(SRC_DIR)/*.s)
OBJ := $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC))
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ := $(patsubst $(TEST_DIR)/%.c, $(TEST_OBJ_DIR)/%.o, $(TEST_SRC))
TEST_FILES = test_program test_output.txt


CC = gcc
CFLAGS = -fPIE -Wall -Wextra -Werror
NASM = nasm
ifeq ($(shell uname), Darwin)
    NASM_FLAGS = -f macho64  # NASM flags for 64-bit output format for macOS
else
    NASM_FLAGS = -f elf64    # NASM flags for 64-bit output format for Linux
endif
LDFLAGS = -pie
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
	@$(CC) $(CFLAGS) -o $@ -c $<

test: $(NAME) $(TEST_OBJ)
	@$(CC) $(LDFLAGS) -o test_program $(TEST_OBJ) $(NAME)
	@./test_program

clean:
	@$(RM) $(OBJ_DIR)/*.o
	@$(RM) $(TEST_OBJ_DIR)/*.o
	@$(RMDIR) $(OBJ_DIR) $(TEST_OBJ_DIR)
	@$(RM) $(TEST_FILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test $(OBJ_DIR) $(TEST_OBJ_DIR)
