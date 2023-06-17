/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:05:21 by sroggens          #+#    #+#             */
/*   Updated: 2023/06/17 14:05:22 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	colorcheck(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] != '\0')
			i++;
		else if (str[i] == ',' && str[i + 1] == '\0')
			return (1);
		if (str[i] < 48 && str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}