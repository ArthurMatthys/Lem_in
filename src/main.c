/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/20 11:27:11 by amatthys    ###    #+. /#+    ###.fr     */
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

	tab = (t_ant *)malloc(sizeof(t_ant) * (nbr +1));
	tab[nbr].room = NULL;
	tab[nbr].nbr = -2;
	while (nbr >= 0)
	{
		tab[nbr].room = start->name;
		tab[nbr].nbr = nbr + 1;
		nbr--;
	}
	return (tab);
}


int			main(void)
{
	t_room	*start;
	t_room	*end;
	t_room	*init = NULL;
	t_ant	*ant;

	if (!(init = parse(init)))
		return (0);
	if (!(start = find_stat(init, 1)) || !(end = find_stat(init, 2)))
		return (0);
	if (!put_len(init, end))
	{
		ft_printf("Error");
		return (0);
	}
	ant = create_ant(start->nbr, start);
	remove_access_s(init);
	moove_ants(init, start, ant);
	return (0);
}
