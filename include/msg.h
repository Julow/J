/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 23:39:34 by juloo             #+#    #+#             */
/*   Updated: 2015/07/07 01:00:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# define ENDL		"\n"

# define PREFIX		"j: "

# define E_ARG		"%s: -%s: %s" ENDL

# define E_TERM		PREFIX "Cannot init termcaps" ENDL
# define E_SLAVE	PREFIX "Cannot init tty" ENDL

#endif
