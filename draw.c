/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:29:44 by Leo               #+#    #+#             */
/*   Updated: 2022/05/04 13:23:33 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_putcolor(int *z, int *z1, int *color)
{
	if (*z || *z1)
		*color = 0xe80c0c;
	else
		*color = 0xffffff;
}

void	bresenham(t_point *point, t_data *data, t_fdf *fdf)
{
	point->z = fdf->tab4matrix[(int)point->y0][(int)point->x0];
	point->z1 = fdf->tab4matrix[(int)point->y1][(int)point->x1];
	point->x0 *= data->zoom;
	point->x1 *= data->zoom;
	point->y0 *= data->zoom;
	point->y1 *= data->zoom;
	ft_putcolor(&point->z1, &point->z, &data->color);
	isometric(&point->x0, &point->y0, point->z);
	isometric(&point->x1, &point->y1, point->z1);
	point->x0 += data->shift_x;
	point->y0 += data->shift_y;
	point->x1 += data->shift_x;
	point->y1 += data->shift_y;
	point->x_step = point->x1 - point->x0;
	point->y_step = point->y1 - point->y0;
	point->max = 0.0;
	while (point->max <= 1.0)
	{		
		my_mlx_pixel_put(data, point->tmp_x, point->tmp_y, data->color);
		point->tmp_x = point->x0 + point->x_step * point->max;
		point->tmp_y = point->y0 + point->y_step * point->max;
		point->max += 0.0001;
	}
}

static void	condition_x(int *x, int *y, t_point *point)
{
	point->x0 = *x;
	point->x1 = *x + 1;
	point->y0 = *y;
	point->y1 = *y;
}

static void	condition_y(int *x, int *y, t_point *point)
{
	point->x0 = *x;
	point->x1 = *x;
	point->y0 = *y;
	point->y1 = *y + 1;
}

void	drawline(t_data *data, t_fdf *fdf)
{
	t_point	point;
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
			{
				condition_x(&x, &y, &point);
				bresenham(&point, data, fdf);
			}
			if (y < fdf->height - 1)
			{
				condition_y(&x, &y, &point);
				bresenham(&point, data, fdf);
			}
			x++;
		}
		y++;
	}
}
