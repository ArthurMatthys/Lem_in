/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   remove_access.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 08:44:48 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 15:08:50 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				remove_all(t_room *room, char *str)
{
	t_links		*link;
	t_links		*to_del;

	link = room->links;
	while (link)
	{
		to_del = link;
		link = link->links;
		free(to_del);
	}
	if (room->stat == 2)
	{
		room->links = NULL;
		return (1);
	}
	to_del = (t_links *)malloc(sizeof(t_links));
	to_del->links = NULL;
	to_del->room = str;
	room->links = to_del;
	return (1);
}

int		remove_access(t_room *init, t_room *room)
{
	t_links		*link;
	t_room		*chr = NULL;
	char		*str = NULL;
	int			i;

	link = room->links;
	if (room->stat == -1 || !link)
		return (1);
	i = room->range;
	str = room->name;
	while (link)
	{
		chr = find_room(init, link->room);
		if (chr->range < i && chr->range >= 0)
		{
			i = chr->range;
			str = chr->name;
		}
		link = link->links;
	}
	return (remove_all(room, str));
}

int		remove_access_s(t_room *init)
{
	t_room	*cpy;

	cpy = init;
	while (cpy)
	{
		remove_access(init, cpy);
		cpy = cpy->next;
	}
	return (1);
}
