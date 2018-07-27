/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tubes.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 13:56:28 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 14:13:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int				new_links(t_room *dest, t_room *src)
{
	t_links		*new1;
	t_links		*new2;

	if (!src || !dest)
		return (0);
	else
	{
		new1 = (t_links *)malloc(sizeof(t_links));
		new2 = (t_links *)malloc(sizeof(t_links));
		new1->links = dest->links;
		new1->room = src->name;
		dest->links = new1;
		new2->links = src->links;
		new2->room = dest->name;
		src->links = new2;
	}
	return (1);
}

int				create_link(char *str, t_room *first)
{
	t_room		*dest;
	t_room		*src;
	char		**tab;

	tab = ft_strsplit(str, '-');
	if (!ft_strcmp(tab[0], tab[1]))
	{
		ft_freetab(tab);
		return (0);
	}
	dest = first;
	src = first;
	dest = roomchr(dest, tab[0]);
	src = roomchr(src, tab[1]);
	if (new_links(dest, src))
	{
		ft_freetab(tab);
		return (1);
	}
	else
	{
		ft_freetab(tab);
		return (0);
	}
}

void			*ft_tabuff(char **tab, char *buff, t_room *room)
{
	t_room		*cpy;
	t_room		*to_del;

	if (buff)
		free(buff);
	buff = NULL;
	if (tab)
		ft_freetab(tab);
	tab = NULL;
	cpy = room;
	while (cpy)
	{
		to_del = cpy;
		cpy = cpy->next;
		remove_all(to_del, NULL, 0);
		free(to_del->name);
		to_del->name = NULL;
		free(to_del);
		to_del = NULL;
	}
	return (NULL);
}

int				tubes(char *str, char **to, t_room *first)
{
	char		*buff;
	char		**tab;

	if (!create_link(str, first) || !ft_strcmp(str, "##end") ||
			!ft_strcmp(str, "##start"))
		return (0);
	while (get_next_line(0, &buff))
	{
		reall(buff, to);
		tab = ft_strsplit(buff, '-');
		if (!ft_strcmp(buff, "##end") || !ft_strcmp(buff, "##start"))
			return (ft_tabuff(tab, buff, NULL) ? 0 : 0);
		else if (buff[0] == '#')
			;
		else if (ft_tablen(tab) != 2)
			return (ft_tabuff(tab, buff, NULL) ? 0 : 0);
		else if (!(create_link(buff, first)))
			return (ft_tabuff(tab, buff, NULL) ? 0 : 0);
		ft_tabuff(tab, buff, NULL);
	}
	reall(buff, to);
	ft_tabuff(NULL, buff, NULL);
	return (1);
}
