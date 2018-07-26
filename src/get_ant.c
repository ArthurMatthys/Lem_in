/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_ant.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 17:20:43 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 11:23:34 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				reall(char *str, char **to)
{
	size_t		i;
	size_t		j;
	char		*cpy;

	i = ft_strlen(str);
	if (*to && i && (cpy = ft_strdup(*to)))
		ft_memdel((void **)to);
	else
		cpy = NULL;
	j = (cpy ? ft_strlen(cpy) : 0);
	if (i && (*to = (char *)malloc(sizeof(char) * (i + j + 2))))
	{
		if (cpy && j)
		{
			*to = ft_memcpy(*to, cpy, j);
			(*to)[j] = '\0';
		}
		free(cpy);
		(*to)[j] = '\0';
		cpy = ft_strdup(str);
		ft_strncat(*to, cpy, i + j);
		ft_strncat(*to, "\n", i + j + 1);
	}
	free(cpy);
	return (1);
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

t_room			*parse(t_room *room, char **to)
{
	char		*str;
	long long	ant;
	int			nbr;
	int			i;

	ant = 0;
	i = 0;
	while ((nbr = get_next_line(0, &str)) && reall(str, to))
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
			rooms(room, (int)ant, to, str) : NULL);
}
