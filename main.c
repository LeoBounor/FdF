/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/01/15 17:27:33 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_fdf	*fdf;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fil de Fer !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.zoom = 20;
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_readfile(argv[1], fdf);
	drawline(&img, fdf);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 30, 30);
	mlx_loop(mlx);
}
