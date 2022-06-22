/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/06/22 14:32:05 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > 1000 - 1 || y < 0 || y > 1000 - 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	isometric(float *x, float *y, int z)
{
	int	tmp;

	tmp = *x;
	*x = (*x - *y) * cos(0.5);
	*y = (tmp + *y) * sin(0.5) - z;
}

static void	clear_win(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	fdf->img.color = 0x000000;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			my_mlx_pixel_put(&fdf->img, x, y, fdf->img.color);
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
	if (key == 123)
		fdf->img.shift_x -= 10;
	if (key == 124)
		fdf->img.shift_x += 10;
	if (key == 6)
		fdf->img.zoom += 2;
	if (key == 7)
		fdf->img.zoom -= 2;
	if (key == 53)
	{
		free_array(fdf);
		exit (EXIT_SUCCESS);
	}
	clear_win(fdf);
	drawline(&fdf->img, fdf);
	mlx_put_image_to_window(fdf->img.mlx, fdf->img.mlx_win,
		fdf->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		write(2, "Error arguments!", 17);
		return (0);
	}
	ft_readfile(argv[1], &fdf);
	fdf.img.mlx = mlx_init();
	fdf.img.mlx_win = mlx_new_window(fdf.img.mlx, 1000, 1000, "Fdf!");
	fdf.img.zoom = 15;
	fdf.img.img = mlx_new_image(fdf.img.mlx, 1000, 1000);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
			&fdf.img.line_length, &fdf.img.endian);
	drawline(&fdf.img, &fdf);
	mlx_key_hook(fdf.img.mlx_win, deal_key, &fdf);
	mlx_hook(fdf.img.mlx_win, 17, 1L << 0, exit_prg, &fdf);
	mlx_put_image_to_window(fdf.img.mlx, fdf.img.mlx_win, fdf.img.img, 0, 0);
	mlx_loop(fdf.img.mlx);
	return (0);
}
