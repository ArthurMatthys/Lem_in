/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:16:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 16:44:26 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			create_nest(char *str, t_room *first, int *spec)
{
	char	**tab;
	int		j;
	
	j = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[0][j])
	{
		if (!ft_isprint(tab[0][j++]))
			return (0);
	}
}

t_room		*valid(char *str, t_room *first, int *spec)
{
	int		t[2];

	ft_bzero(t, 2);
	while (*str)
	{
		if (*str == ' ')
			t[0]++;
		else if (*str == '-')
			t[1]++;
		str++;
	}
	if (t[0] == 2)
		return (create_nest(str, first, spec));
	else if (t[1] == 1)
		return (create_link(str, first));
	else
		return (0);
}

t_room		*parse(char *str, t_room *room)
{
	char	*buff;
	int		spec;
	int		nbr;
	t_room	*first;

	first = NULL;
	spec = 0;
	while ((nbr = get_next_line(0, &str)))
	{
		if (ft_strcmp(str, "##start"))
			spec = 1;
		else if (ft_strcmp(str, "##end"))
			spec = 2;
		else if (nbr && str[0] == '#')
			;
		else if (!(first = valid(str, first, &spec)))
			return (NULL);
		free(str);
	}
	free_fd();
	return (first);
}
