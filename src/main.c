/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 18:31:44 by amatthys    ###    #+. /#+    ###.fr     */
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
		cpy = init;
		init = init->next;
		free(cpy->links);
		free(cpy->name);
		free(cpy);
	}
}

int			inner_main(t_room *init, t_room *end, t_room *start)
{
	t_ant	*ant;
	int		a;

	a = 0;
	if (!put_len(init, end, &a))
	{
		ft_tabuff(NULL, NULL, init);
		ft_printf("Error\n");
		return (0);
	}
	ant = create_ant(start->nbr, start);
	remove_access_s(init);
	moove_ants(init, start, ant);
	free_all(init);
	free(ant);
	return (0);
}

int			main(void)
{
	t_room	*start;
	t_room	*end;
	t_room	*init;

	init = NULL;
	if (!(init = parse(init)))
	{
		free_fd();
		ft_printf("Error\n");
		return (0);
	}
	free_fd();
	start = find_stat(init, 1);
	if (!start || !(end = find_stat(init, 2)))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (inner_main(init, end, start));
}
