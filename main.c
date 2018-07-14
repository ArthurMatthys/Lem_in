/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/14 15:10:33 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_stat(t_room *room, int i)
{
	while (room)
	{
		if (room->stat == i)
			return (room);
		room = room->next;
	}
}

int			main(void)
{
	t_room	*start;
	t_room	*end = NULL;

	if (!(start = parse(end)))
		return (0);
	start = find_stat(end, 1);
	end = find_stat(end, 2);
	if (!put_len(end))
	{
		ft_printf("Error");
		return (0);
	}
	return (0);
}
