/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:55 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 11:34:59 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_mms_20191025_beta/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct fdf
{
	int		width;
	int		height;
	int		**tab4matrix;
}			t_fdf;

/* FUNCTIONS FOR READ FILE */
void	ft_readfile(char *file, t_fdf *fdf);
void	ft_fill_matrix(int *tab4matrix, char *line);
int		ft_getwidth(char *file);
int		ft_getheight(char *file);

/* FUNCTIONS UTILS */
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif