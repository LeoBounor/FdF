/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/03/02 15:52:37 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	/*t_data	*img;
	t_fdf	*fdf;

	img = malloc(sizeof(t_data));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_readfile(argv[1], fdf);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1920, 1080, "Fil de Fer !");
	img->zoom = 20;
	drawline(img, fdf);
	mlx_put_image_to_window(&img, img->win_ptr, img->img, 0, 0);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 30, 30);
	mlx_loop(img->mlx_ptr);*/
	/*img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1920, 1080, "my window");
	img->img = mlx_new_image(img->mlx_ptr, 1920, 1080);
	drawline(img->img, fdf);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
	mlx_loop(img->mlx_ptr);*/

	t_data	*img;
	t_fdf	*fdf;

	img = malloc(sizeof(t_data));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_readfile(argv[1], fdf);
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	img->zoom = 35;
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	drawline(img, fdf);
	//my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 30, 30);
	mlx_loop(img->mlx);
	free (img);
}
