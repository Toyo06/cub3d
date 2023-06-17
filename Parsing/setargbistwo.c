/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setargbistwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:04:31 by sroggens          #+#    #+#             */
/*   Updated: 2023/06/18 00:46:04 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	setvaluepremap(t_game *game)
{
	game->parsing.k = game->parsing.i;
	game->parsing.l = 0;
	game->parsing.i = 0;
	while (game->parsing.tmp[game->parsing.i])
	{
		game->parsing.tmpcheck
			= ft_split(game->parsing.tmp[game->parsing.i], ' ');
		if (game->parsing.tmpcheck[1] == NULL
			|| game->parsing.tmpcheck[1][0] == '\n')
			return (errormess(4));
		if (checkifitexist(game->parsing.tmpcheck[0]) == 1)
			return (errormess(4));
		if (addvaluetorighttab(game->parsing.tmpcheck, game) == 1)
			return (1);
		free(game->parsing.tmpcheck[0]);
		free(game->parsing.tmpcheck[1]);
		free(game->parsing.tmpcheck);
		game->parsing.i++;
	}
	return (0);
}

int	checkifitexist(char *str)
{
	if (ft_strcmp(str, "EA") == 0 || ft_strcmp(str, "NO")
		== 0 || ft_strcmp(str, "SO") == 0
		|| ft_strcmp(str, "WE") == 0
		|| ft_strcmp(str, "F") == 0 || ft_strcmp(str, "C") == 0)
		return (0);
	return (1);
}

int	addeano(char **str, t_game *game, int fd)
{
	if (ft_strcmp(str[0], "EA") == 0)
	{
		if (game->parsing.ea == 1)
			return (errormess(5));
		game->parsing.ea = 1;
		game->txt.ea = ft_strdupwen(str[1]);
		fd = open(game->txt.ea, O_RDONLY);
		if (fd == -1)
			return (errormess(6));
		close(fd);
	}
	if (ft_strcmp(str[0], "NO") == 0)
	{
		if (game->parsing.no == 1)
			return (errormess(5));
		game->parsing.no = 1;
		game->txt.no = ft_strdupwen(str[1]);
		fd = open(game->txt.no, O_RDONLY);
		if (fd == -1)
			return (errormess(6));
		close(fd);
	}
	return (0);
}

int	addsowe(char **str, t_game *game, int fd)
{
	if (ft_strcmp(str[0], "SO") == 0)
	{
		if (game->parsing.so == 1)
			return (errormess(5));
		game->parsing.so = 1;
		game->txt.so = ft_strdupwen(str[1]);
		fd = open(game->txt.so, O_RDONLY);
		if (fd == -1)
			return (errormess(6));
		close(fd);
	}
	if (ft_strcmp(str[0], "WE") == 0)
	{
		if (game->parsing.we == 1)
			return (errormess(5));
		game->parsing.we = 1;
		game->txt.we = ft_strdupwen(str[1]);
		fd = open(game->txt.we, O_RDONLY);
		if (fd == -1)
			return (errormess(6));
		close(fd);
	}
	return (0);
}

int	addfc(char **str, t_game *game)
{
	if (ft_strcmp(str[0], "F") == 0)
	{
		if (game->parsing.f == 1)
			return (errormess(5));
		game->parsing.f = 1;
		game->parsing.ftab = ft_strdupwen(str[1]);
		if (checkandfillrgbvalue(game->parsing.ftab, game, 'f') == 1)
			return (1);
	}
	if (ft_strcmp(str[0], "C") == 0)
	{
		if (game->parsing.c == 1)
			return (errormess(5));
		game->parsing.c = 1;
		game->parsing.ctab = ft_strdupwen(str[1]);
		if (checkandfillrgbvalue(game->parsing.ctab, game, 'c') == 1)
			return (1);
	}
	return (0);
}
