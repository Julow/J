/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:14:11 by juloo             #+#    #+#             */
/*   Updated: 2015/06/24 23:55:46 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROC_H
# define FT_PROC_H

# include <sys/types.h>

# ifdef __APPLE__
#  include "libproc.h"
#  define PROC_PATH_LEN		PROC_PIDPATHINFO_MAXSIZE
# else
#  define PROC_PATH_LEN		256
# endif

/*
** ft_pidpath
** ----
** Get the current directory of an other process
** ----
** Return an alloced string containing the absolute path
** Return NULL on error
*/
int				ft_pidpath(pid_t pid, char *buff, int buff_size);

#endif
