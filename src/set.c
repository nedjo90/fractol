/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:43:00 by nhan              #+#    #+#             */
/*   Updated: 2025/02/05 22:58:02 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_compute_set(t_param *p)
{
	p->compute_coordinate.reel = 0.0;
	p->compute_coordinate.imaginary = 0.0;
	p->iterator = 0;
	while (p->iterator < p->max_iteration)
	{
		if (((p->compute_coordinate.reel * p->compute_coordinate.reel)
				+ (p->compute_coordinate.imaginary
					* p->compute_coordinate.imaginary)) > p->max_convergence)
			break ;
		p->temp_coordinate.reel = p->compute_coordinate.reel;
		p->compute_coordinate.reel = (p->compute_coordinate.reel
				* p->compute_coordinate.reel) - (p->compute_coordinate.imaginary
				* p->compute_coordinate.imaginary) + p->coordinate.reel;
		p->compute_coordinate.imaginary = 2 * (p->temp_coordinate.reel
				* p->compute_coordinate.imaginary) + p->coordinate.imaginary;
		p->iterator++;
	}
}