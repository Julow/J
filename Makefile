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
	o/srcs/ft_dstrreplace.o \
	o/srcs/ft_hmatch.o \
	o/srcs/ft_openpt.o \
	o/srcs/ft_pidpath.o \
	o/srcs/j_ask.o \
	o/srcs/j_flush.o \
	o/srcs/j_history.o \
	o/srcs/j_key.o \
	o/srcs/j_search.o \
	o/srcs/j_set.o \
	o/srcs/main.o \
	o/srcs/master.o \
	o/srcs/scan_output.o \
	o/srcs/slave.o \
	o/srcs/ft_prompt/completion.o \
	o/srcs/ft_prompt/deletion.o \
	o/srcs/ft_prompt/flush.o \
	o/srcs/ft_prompt/ft_freeall.o \
	o/srcs/ft_prompt/ft_promptinit.o \
	o/srcs/ft_prompt/ft_promptkey.o \
	o/srcs/ft_prompt/glob.o \
	o/srcs/ft_prompt/history.o \
	o/srcs/ft_prompt/motions.o \
	o/srcs/ft_prompt/keys/key_arrows.o \
	o/srcs/ft_prompt/keys/key_ctrl_a.o \
	o/srcs/ft_prompt/keys/key_ctrl_arrows.o \
	o/srcs/ft_prompt/keys/key_ctrl_delete.o \
	o/srcs/ft_prompt/keys/key_ctrl_e.o \
	o/srcs/ft_prompt/keys/key_ctrl_k.o \
	o/srcs/ft_prompt/keys/key_ctrl_o.o \
	o/srcs/ft_prompt/keys/key_ctrl_v.o \
	o/srcs/ft_prompt/keys/key_ctrl_w.o \
	o/srcs/ft_prompt/keys/key_ctrl_x.o \
	o/srcs/ft_prompt/keys/key_ctrl_y.o \
	o/srcs/ft_prompt/keys/key_delete.o \
	o/srcs/ft_prompt/keys/key_eof.o \
	o/srcs/ft_prompt/keys/key_int.o \
	o/srcs/ft_prompt/keys/key_nl.o \
	o/srcs/ft_prompt/keys/key_shift_arrows.o \
	o/srcs/ft_prompt/keys/key_tab.o \
	o/srcs/keys/key_ctrl_f.o \
	o/srcs/keys/key_ctrl_l.o \
	o/srcs/keys/key_ctrl_r.o \
	o/srcs/keys/key_refresh.o

MSG_0 := printf '\033[0;32m%-40.40s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-40.40s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

o/srcs/argv.o: srcs/argv.c include/ft_prompt.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_dstrreplace.o: srcs/ft_dstrreplace.c include/ft_prompt.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_hmatch.o: srcs/ft_hmatch.c include/ft_prompt.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_openpt.o: srcs/ft_openpt.c include/ft_prompt.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_pidpath.o: srcs/ft_pidpath.c include/ft_proc.h include/ft_prompt.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_ask.o: srcs/j_ask.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_flush.o: srcs/j_flush.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_history.o: srcs/j_history.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_key.o: srcs/j_key.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_search.o: srcs/j_search.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/j_set.o: srcs/j_set.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/master.o: srcs/master.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/scan_output.o: srcs/scan_output.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/slave.o: srcs/slave.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/completion.o: srcs/ft_prompt/completion.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/deletion.o: srcs/ft_prompt/deletion.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/flush.o: srcs/ft_prompt/flush.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/ft_freeall.o: srcs/ft_prompt/ft_freeall.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/ft_promptinit.o: srcs/ft_prompt/ft_promptinit.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/ft_promptkey.o: srcs/ft_prompt/ft_promptkey.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/glob.o: srcs/ft_prompt/glob.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/history.o: srcs/ft_prompt/history.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/motions.o: srcs/ft_prompt/motions.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_arrows.o: srcs/ft_prompt/keys/key_arrows.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_a.o: srcs/ft_prompt/keys/key_ctrl_a.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_arrows.o: srcs/ft_prompt/keys/key_ctrl_arrows.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_delete.o: srcs/ft_prompt/keys/key_ctrl_delete.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_e.o: srcs/ft_prompt/keys/key_ctrl_e.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_k.o: srcs/ft_prompt/keys/key_ctrl_k.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_o.o: srcs/ft_prompt/keys/key_ctrl_o.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_v.o: srcs/ft_prompt/keys/key_ctrl_v.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_w.o: srcs/ft_prompt/keys/key_ctrl_w.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_x.o: srcs/ft_prompt/keys/key_ctrl_x.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_ctrl_y.o: srcs/ft_prompt/keys/key_ctrl_y.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_delete.o: srcs/ft_prompt/keys/key_delete.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_eof.o: srcs/ft_prompt/keys/key_eof.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_int.o: srcs/ft_prompt/keys/key_int.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_nl.o: srcs/ft_prompt/keys/key_nl.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_shift_arrows.o: srcs/ft_prompt/keys/key_shift_arrows.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/ft_prompt/keys/key_tab.o: srcs/ft_prompt/keys/key_tab.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/ft_prompt/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_f.o: srcs/keys/key_ctrl_f.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_l.o: srcs/keys/key_ctrl_l.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_ctrl_r.o: srcs/keys/key_ctrl_r.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/keys/key_refresh.o: srcs/keys/key_refresh.c include/ft_proc.h include/ft_prompt.h include/ft_prompt_keys.h include/j.h include/msg.h
	@mkdir -p o/srcs/keys 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs/keys o/srcs/ft_prompt/keys o/srcs/ft_prompt o/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
