/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   movement.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/19 15:37:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 17:40:25 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

void		moove_room(int i, t_ant *ant, t_room *next, int *count)
{
//	ft_printf("->|%d|<-", i);
	ant[i].room = next->name;
	next->nbr = -1;
	if (i != *count)
		ft_printf(" ");
	ft_printf("L%d-%s", i, next->name);
	if (next->stat == 2)
	{
		ft_printf(" ");
		*count += 1;
	}
}

void		reset_nbr(t_room *init)
{
	t_room	*next;

	next = init;
	while (next)
	{
		if (next->nbr == -1)
			next->nbr = 0;
		next = next->next;
	}
}


void		moove_ants(t_room *init, t_room *start, t_ant *ant)
{
	int		i;
	int		count;
	t_room	*cpy;
	t_room	*next;

	count = 0;
	while (1)
	{
//		ft_printf("count : %d\n", count);
		i = count;
		while (ant[i].nbr != -2)
		{
			cpy = find_room(init, ant[i].room);
			next = find_room(init, cpy->links->room);
			if (!next->nbr)
				moove_room(i, ant, next, &count);
			i++;
		}
		reset_nbr(init) ;
		ft_printf("\n");
		if (count == start->nbr)
			break;
	}
}
