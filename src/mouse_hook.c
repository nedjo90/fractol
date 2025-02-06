/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:03:36 by nhan              #+#    #+#             */
/*   Updated: 2025/02/06 04:02:41 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_iteration_value(t_param *p, int zoom)
{
	long double	i;

	i = 0.1 * (p->max_iteration / 8);
	if (zoom == ZOOM_IN)
	{
		if (p->max_iteration + 8 < 8388608 + i)
			p->max_iteration += 8 + i;
	}
	else
	{
		if (p->max_iteration > D_MAX_ITER + i + 8)
			p->max_iteration -= i + 8;
		else
			p->max_iteration = D_MAX_ITER;
	}
	if (p->max_iteration > 8388608)
		p->max_iteration = 8388608;
}

void	ft_zoom_in(t_param *p)
{
	ft_point_to_pixel(p);
	p->zoom_count++;
	ft_pixel_to_point(p);
	p->origine_coordinate.reel += p->x - p->origine_coordinate.reel;
	p->origine_coordinate.imaginary += p->y - p->origine_coordinate.imaginary;
	update_iteration_value(p, ZOOM_IN);
}

void	ft_zoom_out(t_param *p)
{
	ft_point_to_pixel(p);
	p->zoom_count--;
	if (p->zoom_count < 0)
		p->zoom_count = 0;
	ft_pixel_to_point(p);
	p->origine_coordinate.reel -= p->x - p->origine_coordinate.reel;
	p->origine_coordinate.imaginary -= p->y - p->origine_coordinate.imaginary;
	update_iteration_value(p, ZOOM_OUT);
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_param *p;

	p = (t_param *)param;
	mlx_get_mouse_pos(p->mlx, &p->x, &p->y);
	if (ydelta > 0)
		ft_zoom_in(p);
	else if (ydelta < 0)
		ft_zoom_out(p);
	else if (xdelta)
		return ;
	ft_draw_image(p);
}