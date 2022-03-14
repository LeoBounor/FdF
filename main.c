/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/03/14 15:25:38 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_win(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			my_mlx_pixel_put(fdf->img, x, y, data->color);
			x++;
		}
		y++;
	}
}

int	deal_key(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->img.shift_y -= 10;
	if (key == 125)
		fdf->img.shift_y += 10;
	if (key == 124)
		fdf->img.shift_x -= 10;
	if (key == 123)
		fdf->img.shift_x += 10;
	mlx_clear_window(fdf->img.mlx, fdf->img.mlx_win);
	drawline(&fdf->img, fdf);
	mlx_put_image_to_window(fdf->img.mlx, fdf->img.mlx_win, fdf->img.img, 30, 30);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_readfile(argv[1], &fdf);
	fdf.img.mlx = mlx_init();
	fdf.img.mlx_win = mlx_new_window(fdf.img.mlx, 1000, 1000, "Fdf!");
	fdf.img.zoom = 15;
	fdf.img.img = mlx_new_image(fdf.img.mlx, 1000, 1000);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
			&fdf.img.line_length, &fdf.img.endian);
	drawline(&fdf.img, &fdf);
	mlx_key_hook(fdf.img.mlx_win, deal_key, &fdf);
	mlx_put_image_to_window(fdf.img.mlx, fdf.img.mlx_win, fdf.img.img, 30, 30);
	mlx_loop(fdf.img.mlx);
}
