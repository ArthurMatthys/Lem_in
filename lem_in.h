/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:08:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/14 15:11:14 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "ft_printf/includes/ft_printf.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	size_t			range;
	int				stat;
	int				nbr;
	struct s_room	*links;
	struct s_room	*next;
}					t_room;

int					put_len(t_room *end);
t_room				*parse(t_room *room);
void				*print_error(void);

#endif
