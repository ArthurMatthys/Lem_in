/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem-in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:08:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 11:23:20 by amatthys    ###    #+. /#+    ###.fr     */
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

typedef struct		s_ant
{
	int				nbr;
	char			*room;
}					t_ant;

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

int					reall(char *str, char **to);
int					put_len(t_room *init, t_room *end, int *st);
int					remove_access_s(t_room *init);
int					remove_all(t_room *room, char *str, int i);
int					tubes(char *str, char **to, t_room *first);
t_room				*find_room(t_room *init, char *str);
t_room				*parse(t_room *room, char **to);
t_room				*roomchr(t_room *init, char *str);
t_room				*rooms(t_room *room, int t, char **to, char *str);
void				moove_ants(t_room *init, t_room *start, t_ant *ant);
void				*print_error(void);
void				free_all(t_room *room);
void				*ft_tabuff(char **tab, char *buff, t_room *room);

#endif
