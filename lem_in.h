/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:08:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 13:55:38 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "ft_printf/includes/ft_printf.h"

typedef struct	s_room
{
	char *	name;
	size_t	x;
	size_t	y;
	size_t	range;
	int		stat;
	s_room	*links;
	s_room	*next;
}				t_room;

t_room			*parse(char *str, t_room *room);

#endif
