/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:29:44 by Leo               #+#    #+#             */
/*   Updated: 2022/01/17 16:55:26 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(float *x0, float *y0, int z0)
{
	*x0 = (*x0 - *y0) * cos(0.8);
	*y0 = (*x0 + *y0) * sin(0.8) - z0;
}

void	bresenham(float x0, float y0, float x1, float y1, t_fdf *fdf)
{
	/*
	x0 *= data->zoom;
	x1 *= data->zoom;
	y0 *= data->zoom;
	y1 *= data->zoom;
	
	z = fdf->tab4matrix[(int)x0][(int)y0];
	z1 = fdf->tab4matrix[(int)x1][(int)y1];
	
	isometric(&x0, &y0, z);
	isometric(&x1, &y1, z1);
	my_mlx_pixel_put(data, x0, y0, 0x00FF0000);
	}
	*/
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
