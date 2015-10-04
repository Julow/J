O_FILES :=	o/srcs/argv.o o/srcs/ft/ft_call.o o/srcs/ft/ft_dstrreplace.o \
			o/srcs/ft/ft_getkey.o o/srcs/ft/ft_hmatch.o o/srcs/ft/ft_open.o \
			o/srcs/ft/ft_openpt.o o/srcs/ft/ft_pidpath.o \
			o/srcs/ft_hist/ft_histadd.o o/srcs/ft_hist/ft_histdelete.o \
			o/srcs/ft_hist/ft_histload.o o/srcs/ft_hist/ft_histsave.o \
			o/srcs/ft_hist/ft_histtrunc.o o/srcs/ft_prompt/completion.o \
			o/srcs/ft_prompt/flush.o o/srcs/ft_prompt/ft_freeall.o \
			o/srcs/ft_prompt/ft_promptinit.o o/srcs/ft_prompt/ft_promptkey.o \
			o/srcs/ft_prompt/ft_promptput.o o/srcs/ft_prompt/glob.o \
			o/srcs/ft_prompt/keys/key_arrows.o \
			o/srcs/ft_prompt/keys/key_ctrl_a.o \
			o/srcs/ft_prompt/keys/key_ctrl_arrows.o \
			o/srcs/ft_prompt/keys/key_ctrl_delete.o \
			o/srcs/ft_prompt/keys/key_ctrl_e.o \
			o/srcs/ft_prompt/keys/key_ctrl_g.o \
			o/srcs/ft_prompt/keys/key_ctrl_k.o \
			o/srcs/ft_prompt/keys/key_ctrl_o.o \
			o/srcs/ft_prompt/keys/key_ctrl_v.o \
			o/srcs/ft_prompt/keys/key_ctrl_w.o \
			o/srcs/ft_prompt/keys/key_ctrl_x.o \
			o/srcs/ft_prompt/keys/key_ctrl_y.o \
			o/srcs/ft_prompt/keys/key_delete.o o/srcs/ft_prompt/keys/key_eof.o \
			o/srcs/ft_prompt/keys/key_int.o o/srcs/ft_prompt/keys/key_nl.o \
			o/srcs/ft_prompt/keys/key_shift_arrows.o \
			o/srcs/ft_prompt/keys/key_tab.o o/srcs/ft_prompt/motions.o \
			o/srcs/j_ask.o o/srcs/j_flush.o o/srcs/j_key.o o/srcs/j_output.o \
			o/srcs/j_resize.o o/srcs/j_search.o o/srcs/j_set.o \
			o/srcs/keys/key_ctrl_f.o o/srcs/keys/key_ctrl_l.o \
			o/srcs/keys/key_ctrl_p.o o/srcs/keys/key_ctrl_r.o \
			o/srcs/keys/key_debug.o o/srcs/keys/key_refresh.o o/srcs/main.o \
			o/srcs/master.o o/srcs/scan_output.o o/srcs/slave.o

LIBS_DEPEND := libft/libft.a

libs:
	JOBS=1 make -C libft extra/ft_term
.PHONY: libs



MAX_SOURCE_LEN := 38
o/srcs/argv.o: srcs/argv.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h include/msg.h | o/srcs/
o/srcs/ft/ft_call.o: srcs/ft/ft_call.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/ft/
o/srcs/ft/ft_dstrreplace.o: srcs/ft/ft_dstrreplace.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/ft/
o/srcs/ft/ft_getkey.o: srcs/ft/ft_getkey.c include/ft_getkey.h | o/srcs/ft/
o/srcs/ft/ft_hmatch.o: srcs/ft/ft_hmatch.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/ft/
o/srcs/ft/ft_open.o: srcs/ft/ft_open.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/ft/
o/srcs/ft/ft_openpt.o: srcs/ft/ft_openpt.c | o/srcs/ft/
o/srcs/ft/ft_pidpath.o: srcs/ft/ft_pidpath.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_proc.h | o/srcs/ft/
o/srcs/ft_hist/ft_histadd.o: srcs/ft_hist/ft_histadd.c include/ft_hist.h \
	| o/srcs/ft_hist/
o/srcs/ft_hist/ft_histdelete.o: srcs/ft_hist/ft_histdelete.c include/ft_hist.h \
	| o/srcs/ft_hist/
o/srcs/ft_hist/ft_histload.o: srcs/ft_hist/ft_histload.c include/ft_hist.h \
	| o/srcs/ft_hist/
o/srcs/ft_hist/ft_histsave.o: srcs/ft_hist/ft_histsave.c include/ft_hist.h \
	include/ft_getkey.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/ft_hist/
o/srcs/ft_hist/ft_histtrunc.o: srcs/ft_hist/ft_histtrunc.c include/ft_hist.h \
	| o/srcs/ft_hist/
o/srcs/ft_prompt/completion.o: srcs/ft_prompt/completion.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/flush.o: srcs/ft_prompt/flush.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/ft_freeall.o: srcs/ft_prompt/ft_freeall.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/ft_prompt/
o/srcs/ft_prompt/ft_promptinit.o: srcs/ft_prompt/ft_promptinit.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/ft_promptkey.o: srcs/ft_prompt/ft_promptkey.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/ft_promptput.o: srcs/ft_prompt/ft_promptput.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/glob.o: srcs/ft_prompt/glob.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h | o/srcs/ft_prompt/
o/srcs/ft_prompt/keys/key_arrows.o: srcs/ft_prompt/keys/key_arrows.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_a.o: srcs/ft_prompt/keys/key_ctrl_a.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_arrows.o: srcs/ft_prompt/keys/key_ctrl_arrows.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_delete.o: srcs/ft_prompt/keys/key_ctrl_delete.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_e.o: srcs/ft_prompt/keys/key_ctrl_e.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_g.o: srcs/ft_prompt/keys/key_ctrl_g.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_k.o: srcs/ft_prompt/keys/key_ctrl_k.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_o.o: srcs/ft_prompt/keys/key_ctrl_o.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_v.o: srcs/ft_prompt/keys/key_ctrl_v.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_w.o: srcs/ft_prompt/keys/key_ctrl_w.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_x.o: srcs/ft_prompt/keys/key_ctrl_x.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_ctrl_y.o: srcs/ft_prompt/keys/key_ctrl_y.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_delete.o: srcs/ft_prompt/keys/key_delete.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_eof.o: srcs/ft_prompt/keys/key_eof.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_int.o: srcs/ft_prompt/keys/key_int.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_nl.o: srcs/ft_prompt/keys/key_nl.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_shift_arrows.o: \
	srcs/ft_prompt/keys/key_shift_arrows.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_prompt_keys.h \
	include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/keys/key_tab.o: srcs/ft_prompt/keys/key_tab.c \
	include/ft_getkey.h include/ft_hist.h include/ft_prompt.h \
	include/ft_prompt_keys.h include/ft_range.h | o/srcs/ft_prompt/keys/
o/srcs/ft_prompt/motions.o: srcs/ft_prompt/motions.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h | o/srcs/ft_prompt/
o/srcs/j_ask.o: srcs/j_ask.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_prompt_keys.h | o/srcs/
o/srcs/j_flush.o: srcs/j_flush.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
o/srcs/j_key.o: srcs/j_key.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_prompt_keys.h | o/srcs/
o/srcs/j_output.o: srcs/j_output.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
o/srcs/j_resize.o: srcs/j_resize.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
o/srcs/j_search.o: srcs/j_search.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_prompt_keys.h | o/srcs/
o/srcs/j_set.o: srcs/j_set.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
o/srcs/keys/key_ctrl_f.o: srcs/keys/key_ctrl_f.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/keys/
o/srcs/keys/key_ctrl_l.o: srcs/keys/key_ctrl_l.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/keys/
o/srcs/keys/key_ctrl_p.o: srcs/keys/key_ctrl_p.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_prompt_keys.h | o/srcs/keys/
o/srcs/keys/key_ctrl_r.o: srcs/keys/key_ctrl_r.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/keys/
o/srcs/keys/key_debug.o: srcs/keys/key_debug.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	| o/srcs/keys/
o/srcs/keys/key_refresh.o: srcs/keys/key_refresh.c include/ft_getkey.h \
	include/ft_hist.h include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_proc.h | o/srcs/keys/
o/srcs/main.o: srcs/main.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h include/msg.h | o/srcs/
o/srcs/master.o: srcs/master.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h \
	include/ft_prompt_keys.h | o/srcs/
o/srcs/scan_output.o: srcs/scan_output.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
o/srcs/slave.o: srcs/slave.c include/ft_getkey.h include/ft_hist.h \
	include/ft_prompt.h include/ft_range.h include/j.h | o/srcs/
