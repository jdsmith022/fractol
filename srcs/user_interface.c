/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   user_interface.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 20:41:34 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/23 18:41:17 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		print_side_line(t_fractol *fractol)
{
	int y;
	int color;

	y = 0;
	color = 0xfafafaf;
	while (y < HEIGHT)
	{
		mlx_pixel_put(fractol->mlx_ptr, fractol->window_ptr, 399, y, color);
		y++;
	}
}

void			print_interface(t_fractol *fractol)
{
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 30, 120, 0xafafaf,
		"THE AMAZING AND WONDERFUL FRACT'OL\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 170, 0xafafaf,
		"press and drag mouse to move\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 200, 0xafafaf,
		"zoom:                   scroll\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 230, 0xafafaf,
		"change iteration:       + & -\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 260, 0xafafaf,
		"move (arrow keys):      ^ & v\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 290, 0xafafaf,
		"change color:           spacebar\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 320, 0xafafaf,
		"change fractol:         1, 2, & 3\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 350, 0xafafaf,
		"un/freeze Julia:        alt\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 380, 0xafafaf,
		"reset:                  backspace\n");
	mlx_string_put(fractol->mlx_ptr, fractol->window_ptr, 50, 410, 0xafafaf,
		"quit:                   escape\n");
	print_side_line(fractol);
}
