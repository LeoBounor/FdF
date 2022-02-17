/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:42:58 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 14:48:47 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*strjoin;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	strjoin = malloc(len1 + len2 + 1);
	if (!strjoin)
		return (s1);
	i = 0;
	while (i < len1)
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = -1;
	while (++j < len2)
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	free(s1);
	return (strjoin);
}
