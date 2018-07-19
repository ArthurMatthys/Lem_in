/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:16:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/19 16:16:25 by amatthys    ###    #+. /#+    ###.fr     */
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

int					create_link(char *str, t_room *first)
{
	t_room	*dest;
	t_room	*src;
	char	**tab;
	t_links	*new1;
	t_links	*new2;

	new1 = (t_links *)malloc(sizeof(t_links));
	new2 = (t_links *)malloc(sizeof(t_links));
	tab = ft_strsplit(str, '-');
	ft_printf("test01\n");
	if (!ft_strcmp(tab[0], tab[1]))
		return (0);
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
		return (0);
	else
	{
		new1->links = dest->links;
		new1->room = src->name;
		dest->links = new1;
		new2->links = src->links;
		new2->room = dest->name;
		src->links = new2;
	}
	return (1);
}

int					tubes(char *str, t_room *first)
{
	int			nbr;
	char		*buff;
	char		**tab;

	if (!create_link(str, first))
		return (0);
	ft_printf("test01\n");
	while ((nbr = get_next_line(0, &buff)))
	{
		tab = ft_strsplit(buff, '-');
		if (buff[0] == '#')
			;
		else if (ft_tablen(tab) != 2)
			return (0);
		else if (!(create_link(buff, first)))
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
	new->nbr = (*stat > 0) * ant * ((*stat % 2) - (!(*stat % 2)));
	new->links = NULL;
	new->next = first;
	if (*stat < 0)
		*stat *= -1 * (*stat % 2) - 2 * (!(*stat % 2));
	return (new);
}

int				valid_nest(char **tab, t_room *first)
{
	int			i;
	int			j;
	long long	t;
	t_room		*cpy;

	cpy = first;
	j = 0;
	i = 0;
	while (tab[0][i])
	{
		if (!ft_isprint(tab[0][i++]))
			return (0);
	}
	while (cpy)
	{
		if ((!ft_strcmp(cpy->name, tab[0])) || (cpy->x == ft_atoi(tab[1]) && cpy->y == ft_atoi(tab[2]) && ft_strcmp(cpy->name, tab[0])))
			return (0);
		cpy = cpy->next;
	}
	i = 0;
	while (tab[++j] && (!(i = 0)))
	{
		t = ft_atoi(tab[j]);
		if (t < 0 || t > INT_MAX)
			return (0);
		while (tab[j][i])
		{
			if (!ft_isdigit(tab[j][i++]))
				return (0);
			i++;
		}
		j++;
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
		ft_printf("test01\nstat :%d\n", stat);
		if (!ft_strcmp(str, "##start"))
		{
//			ft_printf("test02\nstat :%d\n", stat);
			if (stat % 2 == 1 || stat < 0)
				return (print_error());
			stat = (!stat ? -1 : -4);
		}
		else if (!ft_strcmp(str, "##end"))
		{
//			ft_printf("test03\nstat :%d\n", stat);
			if (stat > 1 || stat < 0)
				return (print_error());
			stat = (!stat ? -2 : -3);
		}
		else if (str[0] == '#')
		{
//			ft_printf("test04\n");
			if (stat < 0)
				return (print_error());
		}
		else if (ft_tablen(ft_strsplit(str, '-')) == 2)
		{
			ft_printf("test05\n");
			if (!(tubes(str, first)))
				return (print_error());
			return (stat == 3 ? first : NULL);
		}
		else
		{
			ft_printf("test06\n");
			tab = ft_strsplit(str, ' ');
			if (ft_tablen(tab) != 3 || !valid_nest(tab, first))
				return (print_error());
			first = create_nest(tab, first, &stat, ant);
		}
//		ft_printf("test07\n");
		free(str);
	}
	return (first);
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
		if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
			return (print_error());
		else if (str[0] == '#')
			;
		else if (!ft_isdigit(str[0]))
			return (print_error());
		else
		{
			ant = ft_atoi(str);
			while (str[i])
			{
				if (!ft_isdigit(str[i++]))
				{
					free(str);
					return (print_error());
				}
			}
			free(str);
			break;
		}
		free(str);
	}
	return (ant > 0 && ant <= INT_MAX && nbr ?
			rooms(room, (int)ant) : print_error());
}
