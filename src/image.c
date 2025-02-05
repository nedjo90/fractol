/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:07:13 by nhan              #+#    #+#             */
/*   Updated: 2025/02/05 23:43:48 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_point_to_pixel(t_param *p)
{
	p->coordinate.imaginary = (p->y - p->origine_coordinate.imaginary)
		* p->resolution * pow(D_ZOOM, p->zoom_count);
	p->coordinate.reel = (p->x - p->origine_coordinate.reel) * p->resolution
		* pow(D_ZOOM, p->zoom_count);
}

int	ft_draw_image(t_param *p)
{
	if (!p->img)
		return (-1);
	p->y = 0;
	while (p->y < p->height)
	{
		p->x = 0;
		while (++p->x < p->width)
		{
			ft_point_to_pixel(p);
			ft_compute_set(p);
			ft_set_color(p);
			mlx_put_pixel(p->img, p->x, p->y, p->color);
			p->x++;
		}
		p->y++;
	}
	return (0);
}