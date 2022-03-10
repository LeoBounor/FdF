/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/03/09 21:32:31 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_data *data, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x -= 10;
	if (key == 123)
		data->shift_x += 10;
	//mlx_clear_window(data->mlx, data->mlx_win);
	drawline(data, fdf);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 30, 30);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_fdf	fdf;

	ft_readfile(argv[1], &fdf);
	img.shift_x = 0;
	img.shift_y = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "Hello world!");
	img.zoom = 15;
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	drawline(&img, &fdf);
	mlx_key_hook(img.mlx_win, deal_key, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 30, 30);
	mlx_loop(img.mlx);
}
