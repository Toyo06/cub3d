/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:59:23 by sroggens          #+#    #+#             */
/*   Updated: 2023/06/17 13:54:00 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strdupwen(const char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
