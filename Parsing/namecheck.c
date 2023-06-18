/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:19:01 by sroggens          #+#    #+#             */
/*   Updated: 2023/06/18 00:46:04 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	namecheck(char **av, t_game *game)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
			break ;
		if (av[1][i + 1] == '\0')
			return (errormess(10));
		i++;
	}
	i = 0;
	game->parsing.namecheck = ft_split(av[1], '.');
	while (game->parsing.namecheck[i])
		i++;
	if (ft_strcmp("cub", game->parsing.namecheck[i - 1]) != 0)
	{
		freenamecheck(game);
		return (errormess(10));
	}
	return (freenamecheck(game));
}

int	freenamecheck(t_game *game)
{
	int	i;

	i = 0;
	while (game->parsing.namecheck[i])
	{
		free(game->parsing.namecheck[i]);
		i++;
	}
	free(game->parsing.namecheck);
	return (0);
}
