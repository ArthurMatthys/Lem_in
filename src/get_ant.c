/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_ant.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 17:20:43 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 17:21:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				inside_loop(char *str, long long *ant)
{
	int			i;

	i = 0;
	if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		return (0);
	else if (str[0] == '#')
		;
	else if (!ft_isdigit(str[0]))
		return (0);
	else
	{
		*ant = ft_atoi(str);
		while (str[i])
			if (!ft_isdigit(str[i++]))
				return (0);
		return (1);
	}
	return (1);
}

t_room			*parse(t_room *room)
{
	char		*str;
	long long	ant;
	int			nbr;
	int			i;

	ant = 0;
	i = 0;
	while ((nbr = get_next_line(0, &str)))
	{
		if (!inside_loop(str, &ant))
		{
			free(str);
			return (NULL);
		}
		else if (ant)
		{
			free(str);
			break ;
		}
		free(str);
	}
	return (ant > 0 && ant <= INT_MAX && nbr ?
			rooms(room, (int)ant, 0, str) : NULL);
}
