/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 16:51:51 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "../includes/lem_in.h"
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

int			main(void)
{
	t_room	*start;
	t_room	*end;
	t_room	*init = NULL;

	if (!(init = parse(init)))
		return (0);
	if (!(start = find_stat(init, 1)) || !(end = find_stat(init, 2)))
		return (0);
	if (!put_len(init, end))
	{
		ft_printf("Error");
		return (0);
	}
	return (0);
}
