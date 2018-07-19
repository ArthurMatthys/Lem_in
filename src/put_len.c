/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_len.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 14:20:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 16:41:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "../includes/lem_in.h"
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

int			put_len(t_room *init, t_room *end)
{
	t_room	*cpy;
	t_links	*link;
	int		st;

	st = 0;
	link = end->links;
	ft_printf("test01\n");
	while (link)
	{
		ft_printf("test02\n");
		if (!(cpy = find_room(init, link->room)))
			return (0);
		ft_printf("test03\n");
		if (cpy->stat == 1)
			st = 1;
		ft_printf("test04\n");
		if (cpy->range == -1 || cpy->range > end->range)
		{
			cpy->stat = end->range + 1;
			if (!(put_len(init, cpy)))
				return (0);
		}
		ft_printf("test05\n");
		link = link->links;
	}
	ft_printf("test06\n");
	if (end)
		return (st);
	else
		return (0);
}

