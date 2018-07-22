/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 10:57:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_stat(t_room *room, int i)
{
	t_room	*cpy;

	cpy = room;
	while (cpy)
	{
		if (cpy->stat == i)
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}

t_ant		*create_ant(int nbr, t_room *start)
{
	t_ant	*tab;

	tab = (t_ant *)malloc(sizeof(t_ant) * (nbr + 1));
	tab[nbr].room = NULL;
	tab[nbr].nbr = -2;
	while (--nbr >= 0)
	{
		tab[nbr].room = start->name;
		tab[nbr].nbr = nbr + 1;
	}
	return (tab);
}

void		free_all(t_room *init)
{
	t_room	*cpy;

	while (init)
	{
		cpy = init->next;
		free(init->links);
		free(init->name);
		free(init);
		init = cpy;
	}
}


int			main(void)
{
	t_room	*start;
	t_room	*end;
	t_room	*init = NULL;
	t_ant	*ant;
	int		a;
//	t_links	*link;

	a = 0;
//	ft_printf("test01\n");
	if (!(init = parse(init)))
	{
		free_fd();
		ft_printf("Error\n");
		return (0);
	}
//	ft_printf("test02\n");
	free_fd();
	start = init;
//	while (start)
//	{
//		ft_printf("%s : stats : %d ; nbr : %d\n", start->name, start->stat, start->nbr);
//		link = start->links;
//		while (link)
//		{
//			ft_printf("%s to %s\n", start->name, link->room);
//			link = link->links;
//		}
//		start = start->next;
//	}
	if (!(start = find_stat(init, 1)) || !(end = find_stat(init, 2)))
	{
		ft_printf("yoooo\n");
		return (0);
	}
//	ft_printf("%d\n", a);
	if (!put_len(init, end, &a))
	{
		ft_printf("Error\n");
		return (0);
	}
//	ft_printf("test04\n");
	ant = create_ant(start->nbr, start);
//	ft_printf("test05\n");
	remove_access_s(init);
//	ft_printf("start->nbr : %d\n", start->nbr);
	moove_ants(init, start, ant);
	free_all(init);
	free(ant);
	return (0);
}
