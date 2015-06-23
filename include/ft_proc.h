/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 21:14:11 by juloo             #+#    #+#             */
/*   Updated: 2015/06/23 21:26:41 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROC_H
# define FT_PROC_H

# include <sys/types.h>

/*
** ft_pidpath
** ----
** Get the current directory of an other process
** ----
** Return an alloced string containing the absolute path
** Return NULL on error
*/
char			*ft_pidpath(pid_t pid);

#endif
