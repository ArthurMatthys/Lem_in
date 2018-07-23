/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:16:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 19:23:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*create_nest(char **tab, t_room *first, int *s, int ant)
{
	t_room		*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(tab[0]);
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->range = (*s == -2 || *s == -3 ? 0 : -1);
	new->nbr = ant * (*s == -1 || *s == -4);
	new->links = NULL;
	if (*s >= 0)
		new->stat = 0;
	else if (*s == -1 || *s == -4)
		new->stat = 1;
	else
		new->stat = 2;
	new->next = first;
	if (*s < 0)
		*s *= -1;
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

int				inner_room(char *b, int *s)
{
	if (!ft_strcmp(b, "##start"))
	{
		if ((*s > 2|| *s < 0))
			return (0);
		*s = (!(*s) ? -1 : -4);
		return (2);
	}
	else if (!ft_strcmp(b, "##end"))
	{
		if (*s > 2 || *s < 0)
			return (0);
		*s = (!(*s) ? -2 : -3);
		return (2);
	}
	else if (b[0] == 'L')
		return (0);
	return (1);
}

t_room			*rooms(t_room *first, int ant, int s, char *b)
{
	char		**tab;

	while (get_next_line(0, &b))
	{
		tab = ft_strsplit(b, '-');
		if (inner_room(b, &s) == 2);
		else if ((b[0] == '#' && s < 0) || (s > 3 && !ft_strcmp(b, "##start"))
				|| (s > 2 && !ft_strcmp(b, "##end")))
			return (ft_tabuff(tab, b, first));
		else if (b[0] == '#');
		else if (ft_tablen(tab) == 2)
		{
			if (s < 3 || !(tubes(b, first)))
				return (ft_tabuff(tab, b, first));
			return (!ft_tabuff(tab, b, NULL) && s >= 3 ? first : NULL);
		}
		else if (!ft_tabuff(tab, NULL, NULL) && (tab = ft_strsplit(b, ' ')) &&
				(ft_tablen(tab) != 3 || !valid_nest(tab, first)))
			return (ft_tabuff(tab, b, first));
		else
			first = create_nest(tab, first, &s, ant);
		ft_tabuff(tab, b, NULL);
	}
	return (s >= 3 ? first : NULL);
}
