/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:29:44 by Leo               #+#    #+#             */
/*   Updated: 2022/02/17 14:53:35 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((y >= 0 && y < 1080) && (x >= 0 && x < 1920))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(8);
	*y = (*x + *y) * sin(8) - z;
}

void	bresenham(float x0, float y0, float x1, float y1, t_data *data, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

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
	x0 += 150;
	y0 += 150;
	x1 += 150;
	y1 += 150;
	x_step = x1 - x0;
	y_step = y1 - y0;
	if (x_step < 0)
		x_step = -x_step;
	if (y_step < 0)
		y_step = -y_step;
	if (x_step > y_step)
		max = x_step;
	else
		max = y_step;
	x_step /= max;
	y_step /= max;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color);
		//my_mlx_pixel_put(data, x0, y0, data->color);
		x0 += x_step;
		y0 += y_step;
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
