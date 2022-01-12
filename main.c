/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:37:09 by Leo               #+#    #+#             */
/*   Updated: 2022/01/12 11:33:31 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_readfile(argv[1], fdf);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			printf("%d", fdf->tab4matrix[i][j]);
			j++;
		}
		i++;
	}
}
