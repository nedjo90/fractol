/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhan <nhan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:58:24 by nhan              #+#    #+#             */
/*   Updated: 2025/02/06 04:05:58 by nhan             ###   ########.fr       */
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
# define D_ZOOM_STEP 0.75
# define ZOOM_IN 1
# define ZOOM_OUT 0
# define D_OFFSET_X -1.21
# define D_OFFSET_Y -1.21
# define D_GRADIENT_FACTOR 1.5
# define RGB_RED 0xda
# define RGB_GREEN 0x44
# define RGB_BLUE 0x00
# define TRANSPARENT 0x000000FF
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3
# define D_MOVE_STEP 0.1

typedef struct s_coordinate
{
	long double		imaginary;
	long double		reel;
}					t_coordinate;

typedef struct s_param
{
	unsigned int	x;
	unsigned int	y;
	char			set;
	unsigned int	width;
	unsigned int	height;
	unsigned int	color;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	alpha;
	unsigned int	rgb_red;
	unsigned int	rgb_green;
	unsigned int	rgb_blue;
	unsigned int	iterator;
	unsigned int	max_iteration;
	unsigned int	max_convergence;
	float			gradient;
	float			gradient_factor;
	long double		zoom_count;
	long double		zoom_step;
	long double		resolution;
	long double		move_step;
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
void				ft_set_hooks(t_param *p);
void				ft_key_hook(mlx_key_data_t keydata, void *param);
void				ft_scroll_hook(double xdelta, double ydelta, void *param);
void				ft_point_to_pixel(t_param *p);
void				ft_pixel_to_point(t_param *p);

#endif