/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 11:27:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 15:13:07 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int argc, char **argv)
{
	t_room	*room = NULL;

	if (argc != 2)
	{
		ft_printf("Error : unvalid entry");
		return (0);
	}
	if (!(room = parse(argv[1], room)))
	{
		ft_printf("Error : unvalid entry");
		return (0);
	}
	return (0);
}
