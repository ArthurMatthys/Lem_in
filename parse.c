/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:16:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/14 14:20:13 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*roomcpy(t_room *room)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(room->name);
	new->x = room->x;
	new->y = room->y;
	new->range = room->range;
	new->stat = room->stat;
	new->nbr = room->nbr;
	new->next = NULL;
	new->links = NULL;
	return (new);
}

t_room			*create_link(char *str, t_room *first)
{
	t_room	*dest;
	t_room	*src;
	t_room	*cpy;
	char	**tab;

	tab = ft_strsplit(str, '-');
	if (!ft_strcmp(tab[0], tab[1]))
		return (NULL);
	dest = first;
	src = first;
	while (dest)
	{
		if (!ft_strcmp(dest->name, tab[1]))
			break;
		dest = dest->next;
	}
	while (src)
	{
		if (!ft_strcmp(src->name, tab[0]))
			break;
		src = src->next;
	}
	if (!src || !dest)
		return (NULL);
	else
	{
		cpy = roomcpy(dest);
		cpy->next = src->links;
		src->links = cpy;
		cpy = roomcpy(src);
		cpy->next = dest->links;
		dest->links = cpy;
		
	}
	return (first);
}

int				tubes(char *str, t_room *first)
{
	int			nbr;
	char		*buff;
	char		**tab;

	if (!create_link(str, first))
		return (0);
	while ((nbr = get_next_line(0, &buff)))
	{
		tab = ft_strsplit(buff, '-');
		if (buff[0] == '#')
			;
		else if (ft_tablen(tab) != 2)
			return (0);

		else if (!create_link(buff, first))
			return (0);
	}
	return (1);
}

t_room			*create_nest(char **tab, t_room *first, int *stat, int ant)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(tab[0]);
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[1]);
	new->range = (*stat == -2 ? 0 : -1);
	new->nbr = ant * (*stat == -1 || *stat == -3);
	new->links = NULL;
	new->next = first;
	if (stat < 0)
		*stat *= -1;
	return (new);
}

int				valid_nest(char **tab)
{
	int			i;
	int			j;
	long long	t;

	j = 0;
	i = 0;
	while (tab[0][i])
	{
		if (!ft_isprint(tab[0][i++]))
			return (0);
	}
	i = 0;
	while (tab[++j] && tab[j][i])
	{
		t = ft_atoi(tab[j]);
		if (t < 0 || t > INT_MAX)
			return (0);
		if (!ft_isdigit(tab[j][i++]))
			return (0);
	}
	return (tab[0][i] == 'L' ? 0 : 1);
}

t_room			*rooms(t_room *first, int ant)
{
	int			stat;
	int			nbr;
	char		*str;
	char		**tab;

	stat = 0;
	while ((nbr = get_next_line(0, &str)))
	{
		if (ft_strcmp(str, "##start"))
		{
			if (stat % 2 == 1 || stat < 0)
				return (print_error());
			stat = (!stat ? -1 : -3);
		}
		else if (ft_strcmp(str, "##end"))
		{
			if (stat > 1 || stat < 0)
				return (print_error());
			stat = (!stat ? -2 : -3);
		}
		else if (str[0] == '#')
		{
			if (stat < 0)
				return (print_error());
		}
		else if (ft_tablen(ft_strsplit(str, '-')) == 2)
		{
			if (!tubes(str, first))
				return (print_error());
			return (stat == 3 ? first : NULL);
		}
		else
		{
			tab = ft_strsplit(str, ' ');
			if (ft_tablen(tab) != 3 || !valid_nest(tab))
				return (print_error());
			first = create_nest(tab, first, &stat, ant);
		}
	}
}

t_room			*parse(t_room *room)
{
	char		*str;
	long long	ant;
	int			nbr;

	ant = 0;
	while ((nbr = get_next_line(0, &str)))
	{
		if (str[0] != '#' || !ft_isdigit(str[0]) ||
			!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
			return (print_error());
		else if (str[0] == '#')
			;
		else
		{
			ant = ft_atoi(str);
			while (*str)
			{
				if (!ft_isdigit(*str++))
					return (print_error());
			}
			free(str);
			break;
		}
		free(str);
	}
	free(str);
	return (ant > 0 && ant <= INT_MAX && nbr ?
			rooms(room, (int)ant) : print_error());
}
