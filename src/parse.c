/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:16:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 14:01:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*roomchr(t_room *init, char *str)
{
	t_room		*cpy;

	cpy = init;
	while (cpy)
	{
		if (!ft_strcmp(cpy->name, str))
			break ;
		cpy = cpy->next;
	}
	return (cpy);
}

t_room			*create_nest(char **tab, t_room *first, int *stat, int ant)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(tab[0]);
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->range = (*stat == -2 || *stat == -3 ? 0 : -1);
	new->nbr = ant * (*stat == -1 || *stat == -4);
	new->links = NULL;
	if (*stat >= 0)
		new->stat = 0;
	else if (*stat == -1 || *stat == -4)
		new->stat = 1;
	else
		new->stat = 2;
	new->next = first;
	if (*stat < 0)
		*stat *= -1;
	return (new);
}

int				inside_loop2(char **tab, t_room *cpy)
{
	int			i;

	i = 0;
	while (tab[0][i])
	{
		if (!ft_isprint(tab[0][i]))
			return (0);
		i++;
	}
	while (cpy)
	{
		if ((!ft_strcmp(cpy->name, tab[0])) || (cpy->x == ft_atoi(tab[1]) &&
					cpy->y == ft_atoi(tab[2]) && ft_strcmp(cpy->name, tab[0])))
			return (0);
		cpy = cpy->next;
	}
	return (1);
}

int				valid_nest(char **tab, t_room *first)
{
	int			i;
	int			j;
	long long	t;
	t_room		*cpy;

	cpy = first;
	j = 1;
	if (!inside_loop2(tab, cpy))
		return (0);
	while (j < 3 && (!(i = 0)))
	{
		t = ft_atoi(tab[j]);
		if (t < 0 || t > INT_MAX)
			return (0);
		while (tab[j][i])
		{
			if (!ft_isdigit(tab[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (tab[0][0] == 'L' ? 0 : 1);
}

int				inner_room(char *str, char **tab, t_room *first, int *stat)
{
	if (!ft_strcmp(str, "##start"))
	{
		if ((*stat % 2 == 1 || *stat < 0))
		{
			ft_freetabuff(tab, str, first);
			return (0);
		}
		*stat = (!(*stat) ? -1 : -4);
		return (2);
	}
	else if (!ft_strcmp(str, "##end"))
	{
		if (*stat > 1 || *stat < 0)
		{
			ft_freetabuff(tab, str, first);
			return (0);
		}
		*stat = (!(*stat) ? -2 : -3);
		return (2);
	}
	else if (str[0] == 'L')
	{
		ft_freetabuff(tab, str, first);
		return (0);
	}
	return (1);
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
		tab = ft_strsplit(str, '-');
		if (inner_room(str, tab, first, &stat) == 2)
			;
		else if (!tab)
			return (NULL);
/*		if (!ft_strcmp(str, "##start"))
		{
			if ((stat % 2 == 1 || stat < 0))
				return (ft_freetabuff(tab, str, first));
			stat = (!stat ? -1 : -4);
		}
		else if (!ft_strcmp(str, "##end"))
		{
			if (stat > 1 || stat < 0)
				return (ft_freetabuff(tab, str, first));
			stat = (!stat ? -2 : -3);
		}
		else if (str[0] == 'L')
		{
			ft_freetabuff(tab, str, first);
			return (0);
		}
*/		else if (str[0] == '#')
		{
			if (stat < 0)
				return (ft_freetabuff(tab, str, first));
		}
		else if (ft_tablen(tab) == 2)
		{
			if (stat < 3 || !(tubes(str, first)))
				return (ft_freetabuff(tab, str, first));
			ft_freetabuff(tab, str, NULL);
			return (stat >= 3 ? first : NULL);
		}
		else
		{
			ft_freetabuff(tab, NULL, NULL);
			tab = ft_strsplit(str, ' ');
			if (ft_tablen(tab) != 3 || !valid_nest(tab, first))
				return (ft_freetabuff(tab, str, first));
			first = create_nest(tab, first, &stat, ant);
		}
		ft_freetabuff(tab, str, NULL);
	}
	return (stat >= 3 ? first : NULL);
}

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
			rooms(room, (int)ant) : NULL);
}
