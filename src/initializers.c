/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:06:23 by nhan              #+#    #+#             */
/*   Updated: 2025/02/05 23:46:16 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initial_coordinate(t_param *p)
{
	p->origine_coordinate.reel = p->width / 2;
	p->origine_coordinate.imaginary = p->height / 2;
}

void	init_param(t_param *p)
{
	p->width = D_WIDTH;
	p->height = D_HEIGHT;
	p->color = WHITE;
	p->max_iteration = D_MAX_ITER;
	p->max_convergence = D_MAX_CONVERGENCE;
	p->zoom_count = 0.0;
	p->resolution = (long double)1 / (p->height / 3);
	initial_coordinate(p);
}

int	fractol(t_param *p)
{
	p->mlx = mlx_init(p->width, p->height, "Fract-ol", true);
	if (!p->mlx)
		return (-1);
	p->img = mlx_new_image(p->mlx, p->width, p->height);
	if (!p->img)
		return (-2);
	if (mlx_image_to_window(p->mlx, p->img, 0, 0) < 0)
		return (-3);
	ft_draw_image(p);
	if (!p->mlx)
		mlx_terminate(p->mlx);
	mlx_loop(p->mlx);
	return (0);
}