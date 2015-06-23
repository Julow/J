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
C_FLAGS := -Wall -Wextra -Werror -O2 -g

# Linking flags
LD_FLAGS := -L libft -l ft -l termcap

# C include flags
C_HEADS := -I include -I libft

#
# Internal
#

O_FILES := o/srcs/argv.o \
	o/srcs/ft_freeall.o \
	o/srcs/ft_openpt.o \
	o/srcs/ft_pidpath.o \
	o/srcs/ft_subchr.o \
	o/srcs/handle_key.o \
	o/srcs/j_completion.o \
	o/srcs/j_deletion.o \
	o/srcs/j_flush.o \
	o/srcs/j_glob.o \
	o/srcs/j_history.o \
	o/srcs/j_refresh.o \
	o/srcs/main.o \
	o/srcs/master.o \
	o/srcs/scan_output.o \
	o/srcs/slave.o \
	o/srcs/utils.o \
	o/srcs/keys/key_arrows.o \
	o/srcs/keys/key_ctrl_a.o \
	o/srcs/keys/key_ctrl_arrows.o \
	o/srcs/keys/key_ctrl_delete.o \
	o/srcs/keys/key_ctrl_e.o \
	o/srcs/keys/key_ctrl_k.o \
	o/srcs/keys/key_ctrl_l.o \
	o/srcs/keys/key_ctrl_v.o \
	o/srcs/keys/key_ctrl_x.o \
	o/srcs/keys/key_ctrl_y.o \
	o/srcs/keys/key_debug.o \
	o/srcs/keys/key_delete.o \
	o/srcs/keys/key_eof.o \
	o/srcs/keys/key_int.o \
	o/srcs/keys/key_nl.o \
	o/srcs/keys/key_refresh.o \
	o/srcs/keys/key_tab.o \
	o/srcs/unused/ft_subindex.o \
	o/srcs/unused/ft_system.o

MSG_0 := printf '\033[0;32m%-29.29s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-29.29s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

o/srcs/argv.o: srcs/argv.c include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_freeall.o: srcs/ft_freeall.c include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_openpt.o: srcs/ft_openpt.c include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_pidpath.o: srcs/ft_pidpath.c include/ft_proc.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_subchr.o: srcs/ft_subchr.c include/ft_proc.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/handle_key.o: srcs/handle_key.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_completion.o: srcs/j_completion.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_deletion.o: srcs/j_deletion.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_flush.o: srcs/j_flush.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_glob.o: srcs/j_glob.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_history.o: srcs/j_history.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_refresh.o: srcs/j_refresh.c include/ft_proc.h include/j.h include/keys.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/master.o: srcs/master.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/scan_output.o: srcs/scan_output.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/slave.o: srcs/slave.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/utils.o: srcs/utils.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_arrows.o: srcs/keys/key_arrows.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_a.o: srcs/keys/key_ctrl_a.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_arrows.o: srcs/keys/key_ctrl_arrows.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_delete.o: srcs/keys/key_ctrl_delete.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_e.o: srcs/keys/key_ctrl_e.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_k.o: srcs/keys/key_ctrl_k.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_l.o: srcs/keys/key_ctrl_l.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_v.o: srcs/keys/key_ctrl_v.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_x.o: srcs/keys/key_ctrl_x.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_y.o: srcs/keys/key_ctrl_y.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_debug.o: srcs/keys/key_debug.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_delete.o: srcs/keys/key_delete.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_eof.o: srcs/keys/key_eof.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_int.o: srcs/keys/key_int.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_nl.o: srcs/keys/key_nl.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_refresh.o: srcs/keys/key_refresh.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_tab.o: srcs/keys/key_tab.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/unused/ft_subindex.o: srcs/unused/ft_subindex.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/unused 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/unused/ft_system.o: srcs/unused/ft_system.c include/ft_proc.h include/j.h include/keys.h include/msg.h
	@mkdir -p o/srcs/unused 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs/unused o/srcs/keys o/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
