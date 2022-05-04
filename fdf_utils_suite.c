/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:18:39 by lbounor           #+#    #+#             */
/*   Updated: 2022/05/04 11:19:15 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	s_len = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) > start)
	{
		s_len = ft_strlen((char *)s);
		if (s_len > len)
			s_len = len;
	}
	substr = malloc(sizeof(char) * s_len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < s_len && s[i])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
		|| str == '\f' || str == '\r' || str == ' ');
}

int	ft_atoi(const char *str)
{
	char	signe;
	int		nombre;

	signe = 1;
	nombre = 0;
	while (ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nombre = (nombre * 10) + (*str - '0');
		str++;
	}
	return (nombre * signe);
}
