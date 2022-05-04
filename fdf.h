/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:55 by Leo               #+#    #+#             */
/*   Updated: 2022/03/15 10:50:38 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx;
	void	*mlx_win;
}	t_data;

typedef struct s_fdf
{
	int				width;
	int				height;
	int				**tab4matrix;
	struct s_data	img;
}	t_fdf;

typedef struct s_point {
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;
	int		tmp_x;
	int		tmp_y;
}	t_point;

/* FUNCTIONS FOR READ FILE */
void	ft_readfile(char *file, t_fdf *fdf);
void	ft_fill_matrix(int *tab4matrix, char *line);
int		ft_getwidth(char *file);
int		ft_getheight(char *file);

/* FUNCTIONS FOR DRAW */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	isometric(float *x, float *y, int z);
void	bresenham(t_point *point, t_data *data, t_fdf *fdf);
void	drawline(t_data *data, t_fdf *fdf);
void	condition_x(int *x, int *y, t_point *point);
void	condition_y(int *x, int *y, t_point *point);

/* FUNCTIONS UTILS */
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif