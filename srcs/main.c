/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 16:09:45 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/23 21:35:05 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	hook_expose(t_fractol *fractol)
{
	fractol_writer(fractol);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc != 2)
		exit_failure(USAGE_ERR, NULL);
	fractol = fractol_init();
	check_input(fractol, argv[1]);
	mlx_setup(fractol);
	print_interface(fractol);
	fractol_writer(fractol);
	mlx_expose_hook(fractol->window_ptr, hook_expose, fractol);
	mlx_key_hook(fractol->window_ptr, key_press, fractol);
	mlx_hook(fractol->window_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->window_ptr, 6, 0, mouse_move, fractol);
	mlx_hook(fractol->window_ptr, 5, 0, mouse_release, fractol);
	mlx_hook(fractol->window_ptr, 17, 0, close_window, fractol);
	mlx_loop(fractol->mlx_ptr);
	return (0);
}
