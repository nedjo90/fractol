/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:03:39 by nhan              #+#    #+#             */
/*   Updated: 2025/02/06 01:37:53 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_direction_hook(mlx_key_data_t keydata, t_param *p)
{
	if (keydata.key == MLX_KEY_UP)
	{
		p->origine_coordinate.imaginary += (long double)p->height
			* p->move_step;
		return (TRUE);
	}
	else if (keydata.key == MLX_KEY_DOWN)
	{
		p->origine_coordinate.imaginary -= (long double)p->height
			* p->move_step;
		return (TRUE);
	}
	else if (keydata.key == MLX_KEY_RIGHT)
	{
		p->origine_coordinate.reel -= (long double)p->width * p->move_step;
		return (TRUE);
	}
	else if (keydata.key == MLX_KEY_LEFT)
	{
		p->origine_coordinate.reel += (long double)p->width * p->move_step;
		return (TRUE);
	}
	return (FALSE);
}

// int	ft_action_hook(mlx_key_data_t keydata, t_param *p)
// {
// 	return (FALSE);
// }

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_param *p;
	int is_key;

	p = (t_param *)param;
	is_key = FALSE;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(p->mlx);
		return ;
	}
	if (!is_key)
		is_key = ft_direction_hook(keydata, p);
	// if (!is_key)
	// 	is_key = ft_action_hook(keydata, p);
	if (is_key)
		ft_draw_image(p);
}