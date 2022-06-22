/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:45 by Leo               #+#    #+#             */
/*   Updated: 2022/06/22 14:28:10 by lbounor          ###   ########lyon.fr   */
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
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
	{
		write(2, "This file doesn't exist, please indicate the right path.",
			57);
		return (0);
	}
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	ft_readfile(char *file, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	fdf->height = ft_getheight(file);
	if (fdf->height == 0)
		exit (EXIT_FAILURE);
	fdf->width = ft_getwidth(file);
	fdf->tab4matrix = (int **)malloc(sizeof(int *) * (fdf->height));
	i = 0;
	while (i < fdf->height)
		fdf->tab4matrix[i++] = (int *)malloc(sizeof(int) * (fdf->width));
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
		nbs[i] = NULL;
		i++;
	}
	free(nbs);
	nbs = NULL;
}

int	exit_prg(t_fdf *fdf)
{
	free_array(fdf);
	exit (EXIT_SUCCESS);
	return (0);
}
