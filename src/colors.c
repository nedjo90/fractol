/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:45:19 by nhan              #+#    #+#             */
/*   Updated: 2025/02/06 00:39:48 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_rgb_to_color(t_param *p)
{
	p->gradient = (float)p->iterator / ((float)p->max_iteration
			/ p->gradient_factor + 0.0000000000000001);
	p->red = (unsigned int)(p->gradient * p->rgb_red);
	p->green = (unsigned int)(p->gradient * p->rgb_green);
	p->blue = (unsigned int)(1.0f - p->gradient * p->rgb_blue);
	p->color = (p->red << 24) + (p->green << 16) + (p->blue << 8) + 255;
}

void	ft_set_color(t_param *p)
{
	if (p->iterator == p->max_iteration)
		p->color = TRANSPARENT;
	else
		ft_rgb_to_color(p);
}