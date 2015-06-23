/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 22:50:33 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 23:57:07 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_H
# define J_H

# include "libft.h"
# include "ft_dstr.h"
# include "ft_term.h"

/*
** ========================================================================== **
** J
** ----
** TODO:
**  Selection with keyboard
**  Fullscreen mode
**  History search
**  Keep last output for search
**  Save last output for later
**  Write an output in stdin
**  Pipe an output to a system command
**  Use of ft_regex
**  Config
**  Disable j
**  Put deletion history into a tab completion
*/

/*
** ========================================================================== **
** Bindings
** -----
** c = ctrl
** s = shift
** m = alt / option
** -----
** Cursor:
**  left / right		Move cursor into line
**  c+left / c+right	Move cursor into line word by word
**  c+A / home			Move to the start of the line
**  c+E / end			Move to the end of the line
**  up / right			Navigate in the history
** -
** Delete:
**  c+C					Clear line (if line is not empty)
**  delete				Delete
**  c+H					Backspace by word
**  c+delete			Delete by word
**  c+K					Delete from the cursor to the end of line
**  c+X					Delete current word
** -
** Paste:
**  c+Y					Paste last delete
**  c+V					Paste last delete but keep it in the history
** -
** (TODO) Selection:
**  (TODO) s+right / s+left		Select
**  (TODO) s+c+right / s+c+left	Select by word
** -
** Other:
**  tab					Auto complete
**  shift+tab			Auto complete in reverse order
**  m+!					Active debug print
**  c+space				Disable J
*/

# define PN(s,n)		(ft_write(FTOUT, (s), (n)))

# define MASTER_BUFF	512

# define FT_SYS_BUFF	512
# define PIPE_READ		0
# define PIPE_WRITE		1

# define MAX_ESCAPE_LEN	8

typedef struct	s_caps
{
	char			*ch; // Move cursor x (Maybe unsupported)
	char			*ce; // Clear from cursor to right
	char			*ti; // Enter TI mode
	char			*te; // Exit TI mode
}				t_caps;

typedef struct	s_hist
{
	struct s_hist	*prev;
	struct s_hist	*next;
	char			*str;
	int				length;
}				t_hist;

typedef struct	s_j
{
/*
** init + terminal
*/
	char			**cmd;
	int				master;
	int				slave_pid;
	t_term			term;
	t_caps			caps;
	char			*cwd;
/*
** line
*/
	int				flags;
	t_dstr			line;
	int				line_start;
	int				cursor;
/*
** history
*/
	t_hist			*history;
	t_hist			*hist_curr;
	t_hist			*deletions;
/*
** tab completion
*/
	t_dstr			*tab_res;
	int				tab_count;
	int				tab_curr;
}				t_j;

typedef struct	s_val
{
	int				from;
	int				to;
}				t_val;

# define VAL(f,t)		((t_val){(f), (t)})

# define FLAG_TI		(1 << 1)
# define FLAG_DEBUG		(1 << 2)
# define FLAG_RETURN	(1 << 3)

# define J_HIDE			(1 << 1)
# define J_SHOW			(1 << 2)
# define J_REFRESH		(J_HIDE | J_SHOW)

/*
** argv
*/
t_bool			parse_argv(t_j *j, int argc, char **argv);

/*
** term
*/
t_bool			start_slave(t_j *j);
void			start_master(t_j *j);

void			j_flush(t_j *j);
void			j_set(t_j *j, int flags);

void			scan_output(t_j *j, t_sub output);

/*
** keys
*/
void			handle_key(t_j *j, t_ulong key);

/*
** controls
*/
t_val			j_word_motion(t_j *j);
t_val			j_word(t_j *j);

void			j_history(t_j *j, t_dstr str);
void			j_deletion(t_j *j, t_sub str);

t_bool			j_glob(t_j *j);

void			j_completion(t_j *j, int order);

/*
** utils
*/
void			ft_tmakeraw(t_term *term);
t_bool			ft_openpt(int *master, int *slave);

int				ft_subindex(t_sub sub, char c);
int				ft_subchr(t_sub sub, t_is mask);

void			ft_freeall(void *data, int count, int size, void (*f)());

t_dstr			ft_system(char **cmd);

#endif
