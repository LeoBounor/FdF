/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:21:14 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 11:28:36 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_divlen(char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static size_t	ft_splitsize(char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	size;

	i = 0;
	len = 0;
	size = 0;
	while (s[i])
	{
		len = ft_divlen(s + i, c);
		if (len > 0)
		{
			size++;
			i--;
		}
		i += len;
		i++;
	}
	return (size);
}

static void	*ft_freesplit(char **split, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i < n)
		free(split[i--]);
	free(split);
	return (NULL);
}

static char	**ft_splitstr(char **split, char *s, char c)
{
	size_t		i;
	size_t		n;
	size_t		size;

	i = 0;
	n = 0;
	while (((char *)s)[i])
	{
		size = ft_divlen((char *)s + i, c);
		if (size > 0)
		{
			split[n] = ft_substr(s, i--, size);
			if (!split[n])
				return (ft_freesplit(split, n));
			n++;
		}
		i = i + size + 1;
	}
	split[n] = 0;
	return (split);
}

char	**ft_split(const char *s, char c)
{	
	size_t		size;
	char		**split;

	if (!s)
		return (NULL);
	size = ft_splitsize((char *)s, c);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_splitstr(split, (char *)s, c));
}

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
