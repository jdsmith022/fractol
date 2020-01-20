/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:14:59 by jesmith        #+#    #+#                */
/*   Updated: 2020/01/20 20:22:43 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "../includes/thread.h"

# define USAGE_ERR "usage error: input valid parameter \
						\nJulia\nMandelbrot\nJessie\n"
# define MALLOC_ERR "error: malloc\n"

# define ONE 18
# define TWO 19
# define THREE 20

# define ONE_START 0xffffff
# define ONE_MIDDLE 0xFFF200
# define ONE_END 0x240b36

# define TWO_START 0x1a2a6c
# define TWO_MIDDLE 0xb21f1f
# define TWO_END 0xfdbb2d

# define THREE_START 0xCC95C0
# define THREE_MIDDLE 0xdbd4b4
# define THREE_END 0x7AAA1d2

# define FOUR_START 0x1E9600
# define FOUR_MIDDLE 0xFFF200
# define FOUR_END 0xFF0000
# define DEFAULT_START 0xffa500
# define DEFAULT_MIDDLE 0xee3a6a
# define DEFAULT_END 0x72b2f3

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_PRESS 1

# define ESC 53
# define HSV 261
# define INCREASE_SATURATION 126
# define DECREASE_SATURATION 125
# define INCREASE_VALUE 123
# define DECREASE_VALUE 124
# define INCREASE_ITERATIONS 24
# define DECREASE_ITERATIONS 27
# define SPACE 49
# define RESET 51

# define WIDTH 1000
# define HEIGHT 700

# include <math.h>
# include <stdio.h> //remove later!

typedef struct	s_numbers
{
	double		c_real;
	double		c_i;
	double		new_real;
	double		new_i;
	double		old_real;
	double		old_i;
	t_complex	complex;
}				t_numbers;

typedef struct	s_events
{
	double		zoom;
	double		key;
	double		color_set;
	int			mouse_press;
	double		mouse_x;
	double		mouse_y;
	double		start_pan_x;
	double		start_pan_y;
	double		hold_x;
	double		hold_y;
	int			color_grade;
}				t_events;

typedef struct	s_points
{
	double		x;
	double		y;
}				t_points;

typedef struct	s_color
{
	int			start;
	int			end;
	double		hue;
	double		saturation;
	double		value;
	int			color_ppixel[HEIGHT * WIDTH];
}				t_color;

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*window_ptr;
	void		*image_ptr;
	char		*title;
	char		*addr_str;
	int			bits_ppixel;
	int			size_line;
	char		*argv;
	int			max_iterations;
	int			type;
	int			i;
	int			rgb_color;
	t_color		color;
	t_events	event;
	t_numbers	*numbers;
	t_points	*points;
	t_pixel		*pixel;
	t_render	render;
}				t_fractol;

int				main(int argc, char **argv);
void			mlx_setup(t_fractol *fractol);
int				fractol_manager(t_fractol *fractol);

void			check_input(t_fractol *fractol, char **argv);
void			fractol_exit(char *str, t_fractol *fractol);
t_fractol		*fractol_init(void);
t_numbers		*numbers_init(t_fractol *fractol);
t_points		*points_init(t_fractol *fractol);

int				key_press(int key, t_fractol *fractol);

int				mouse_press(int key, int x, int y, t_fractol *fractol);
int				mouse_release(int key, int x, int y, t_fractol *fracol);
int				mouse_move(int x, int y, t_fractol *fractol);

void			print_interface(t_fractol *fractol);
#endif
