/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:29:44 by Leo               #+#    #+#             */
/*   Updated: 2022/03/09 16:35:48 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 1920 - 1 || y < 0 || y > 1080 - 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	isometric(float *x, float *y, int z)
{
	int	tmp;

	tmp = *x;
	*x = (*x - *y) * cos(0.8);
	*y = (tmp + *y) * sin(0.8) - z;
}

void	bresenham(float x0, float y0, float x1, float y1, t_data *data, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;
	int		tmpx;
	int		tmpy;

	z = fdf->tab4matrix[(int)y0][(int)x0];
	z1 = fdf->tab4matrix[(int)y1][(int)x1];
	x0 *= data->zoom;
	x1 *= data->zoom;
	y0 *= data->zoom;
	y1 *= data->zoom;
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	isometric(&x0, &y0, z);
	isometric(&x1, &y1, z1);
	x0 += 350;
	y0 += 350;
	x1 += 350;
	y1 += 350;
	x_step = x1 - x0;
	y_step = y1 - y0;
	max = 0.0;
	while (max <= 1.0)
	{		
		my_mlx_pixel_put(data, tmpx, tmpy, data->color);
		tmpx = x0 + x_step * max;
		tmpy = y0 + y_step * max;
		max += 0.0001;
	}
}

void	drawline(t_data *data, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				bresenham(x, y, x + 1, y, data, fdf);
			if (y < fdf->height - 1)
				bresenham(x, y, x, y + 1, data, fdf);
			x++;
		}
		y++;
	}
}
