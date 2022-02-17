/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:45 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 15:13:44 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_getwidth(char *file)
{
	int		width;
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i])
			width++;
		while (line[i] != ' ' && line[i])
			i++;
	}
	free(line);
	close(fd);
	return (width);
}

int	ft_getheight(char *file)
{
	int		height;
	int		fd;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

void	ft_readfile(char *file, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	fdf->height = ft_getheight(file);
	fdf->width = ft_getwidth(file);
	fdf->tab4matrix = (int **)malloc(sizeof(int *) * (fdf->height + 1));
	i = 0;
	while (i <= fdf->height)
		fdf->tab4matrix[i++] = (int *)malloc(sizeof(int) * (fdf->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = NULL;
	while (i < fdf->height)
	{
		line = get_next_line(fd);
		ft_fill_matrix(fdf->tab4matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	fdf->tab4matrix[i] = NULL;
}

void	ft_fill_matrix(int *tab4matrix, char *line)
{
	char	**nbs;
	int		i;

	nbs = ft_split(line, ' ');
	i = 0;
	while (nbs[i])
	{
		tab4matrix[i] = ft_atoi(nbs[i]);
		free(nbs[i]);
		i++;
	}
	free(nbs);
}
