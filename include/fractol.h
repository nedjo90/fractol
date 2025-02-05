/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:58:24 by nhan              #+#    #+#             */
/*   Updated: 2025/02/05 23:41:16 by nhan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define TITLE "Fractol"
# define TRUE 1
# define FALSE 0
# define D_WIDTH 1600
# define D_HEIGHT 900
# define D_MAX_ITER 128
# define D_MAX_CONVERGENCE 10
# define D_ZOOM 2.0
# define D_OFFSET_X -1.21
# define D_OFFSET_Y -1.21
# define RGB_RED 0xda
# define RGB_GREEN 0x44
# define RGB_BLUE 0x00
# define VOID_COLOR 0x000000FF
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF

typedef struct s_coordinate
{
	long double		imaginary;
	long double		reel;
}					t_coordinate;

typedef struct s_param
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	width;
	unsigned int	height;
	unsigned int	color;
	unsigned int	iterator;
	unsigned int	max_iteration;
	unsigned int	max_convergence;
	long double		zoom_count;
	long double		resolution;
	t_coordinate	origine_coordinate;
	t_coordinate	coordinate;
	t_coordinate	compute_coordinate;
	t_coordinate	temp_coordinate;
	mlx_t			*mlx;
	mlx_image_t		*img;
}					t_param;

void				initial_coordinate(t_param *p);
void				init_param(t_param *p);
int					fractol(t_param *p);
int					ft_draw_image(t_param *p);
void				ft_compute_set(t_param *p);
void				ft_set_color(t_param *p);

#endif