/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_len.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 14:20:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 14:15:06 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(t_room *init, char *str)
{
	t_room	*cpy;

	cpy = init;
	while (cpy)
	{
		if (!(ft_strcmp(str, cpy->name)))
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}

int			put_len(t_room *init, t_room *end, int *st)
{
	t_room	*cpy;
	t_links	*link;

	link = end->links;
	while (link)
	{
		if (!(cpy = find_room(init, link->room)))
			return (0);
		if (cpy->stat == 1)
			*st = 1;
		if (cpy->range == -1 || cpy->range > end->range)
		{
			cpy->range = end->range + 1;
			put_len(init, cpy, st);
		}
		link = link->links;
	}
	return (*st);
}
