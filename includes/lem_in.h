/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:08:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 09:16:55 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../ft_printf/libft/includes/libft.h"
# include "../ft_printf/libft/includes/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct		s_links
{
	char			*room;
	struct s_links	*links;
}					t_links;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				range;
	int				stat;
	int				nbr;
	t_links			*links;
	struct s_room	*next;
}					t_room;

int					put_len(t_room *init, t_room *end);
t_room				*parse(t_room *room);
void				*print_error(void);

#endif
