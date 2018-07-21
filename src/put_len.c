/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_len.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 14:20:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 17:11:25 by amatthys    ###    #+. /#+    ###.fr     */
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

//	ft_printf("st : %d\n", *st);
	link = end->links;
	while (link)
	{
//		ft_printf("%s from %s\n", link->room, end->name);
		if (!(cpy = find_room(init, link->room)))
			return (0);
//		ft_printf("%s : (range) %d : (stat) %d\n", cpy->name, cpy->range, cpy->stat);
//		ft_printf("test03\n");
		if (cpy->stat == 1)
			*st = 1;
//		ft_printf("test04\n");
//		ft_printf("%s : %d\n", end->name, end->range);
		if (cpy->range == -1 || cpy->range > end->range)
		{
			cpy->range = end->range + 1;
			put_len(init, cpy, st);
		}
//		ft_printf("test05\n");
		link = link->links;
//		ft_printf("%s : (range) %d : (stat) %d\n", cpy->name, cpy->range, cpy->stat);
	}
//	ft_printf("test06\n");
//	ft_printf("yo : %d : %d\n", !end, st);
	return (*st);
}

