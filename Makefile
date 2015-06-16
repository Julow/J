#
# j
#
# Makefile
#

#
# Config
#

# Project name
NAME := j

# Project directories
DIRS := srcs include

# Obj directory
O_DIR := o

# Makefiles to call
LIBS := libft

# Number of threads
THREADS := 1

# C compiler
C_CC := clang

# Linking compiler
LD_CC := clang

# C flags
C_FLAGS := -Wall -Wextra -Werror -O2

# Linking flags
LD_FLAGS := -L libft -l ft -l termcap -l util

# C include flags
C_HEADS := -I include -I libft

#
# Internal
#

O_FILES := o/srcs/argv.o \
	o/srcs/handle_key.o \
	o/srcs/j_flush.o \
	o/srcs/main.o \
	o/srcs/master.o \
	o/srcs/slave.o \
	o/srcs/keys/key_eof.o \
	o/srcs/keys/key_int.o \
	o/srcs/keys/key_nl.o

MSG_0 := printf '\033[0;32m%-21.21s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-21.21s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

o/srcs/argv.o: srcs/argv.c include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/handle_key.o: srcs/handle_key.c include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_flush.o: srcs/j_flush.c include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/master.o: srcs/master.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/slave.o: srcs/slave.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_eof.o: srcs/keys/key_eof.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_int.o: srcs/keys/key_int.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_nl.o: srcs/keys/key_nl.c include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs/keys o/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
