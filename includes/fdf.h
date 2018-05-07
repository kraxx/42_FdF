/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 19:56:54 by jchow             #+#    #+#             */
/*   Updated: 2017/07/25 19:57:19 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define THREAD_COUNT	16

# define WIN_WIDTH		2560.0
# define WIN_HEIGHT		1440.0
# define BORDER			0.85

# define GRADIENT		10
# define COLOR_1		0x0000ff
# define COLOR_2		0x00ff00

# define TRANSLATE		8
# define ROT			0.1
# define MOUSE_SENS		0.1
# define ZOOM_IN		1.1
# define ZOOM_OUT		0.9
# define Z_SCALE_UP		1.2
# define Z_SCALE_DOWN	0.8

# define R_MASK 		0xFF0000
# define G_MASK 		0x00FF00
# define B_MASK 		0x0000FF

# define NUM_PULSERS	3

typedef struct	s_bres
{
	double	dx;
	double	dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	int		grad;
	int		hypo;
	int		level;
	int		x1;
	int		y1;
}				t_bres;

typedef	struct	s_cohen_sutherland
{
	int		code1;
	int		code2;
	int		ret_code;
	double	ret_x;
	double	ret_y;
}				t_cs;

typedef struct	s_coor
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z1;
	double	z2;
	int		c1;
	int		c2;
	int		c_lock:1;
}				t_coor;

typedef struct	s_xyz
{
	double	x;
	double	y;
	double	z;
	int		c;
	int		c_lock:1;
}				t_xyz;

typedef struct	s_line
{
	struct s_line	*next;
	char			**info;
}				t_line;

typedef struct	s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size;
	int				e;
}				t_img;

typedef struct	s_togs
{
	int	up:1;
	int	down:1;
	int	left:1;
	int	right:1;
	int	numpad_2:1;
	int	numpad_4:1;
	int	numpad_6:1;
	int	numpad_7:1;
	int	numpad_8:1;
	int	numpad_9:1;
	int	numpad_plus:1;
	int	numpad_minus:1;
	int	fn:1;
	int	bk_del:1;
	int	home:1;
	int	end:1;
	int	pg_up:1;
	int	pg_down:1;
	int	esc:1;
	int	mouse_left:1;
	int	mouse_right:1;
	int	mouse_wheel:1;
	int	mouse_wheel_up:1;
	int	mouse_wheel_down:1;
	int draw_toggle:1;
	int pulse_toggle:1;
}				t_togs;

typedef struct	s_master
{
	void	(*mouse_fp[6])(struct s_master*, int, int);
	void	(*key_fp[280])(struct s_master*, int);
	void	(*pulse_fp[3])(t_xyz**, size_t, size_t);
	t_xyz	**grid;
	t_xyz	**backup;
	t_line	*line;
	t_togs	*togs;
	t_img	*img;
	void	*mlx;
	void	*win;
	int		x_count;
	int		y_count;
	int		mouse_left_x;
	int		mouse_left_y;
	int		mouse_right_x;
	int		mouse_right_y;
	int		mouse_wheel_x;
	int		mouse_wheel_y;
	int		current_pulser:3;
	double	mid_x;
	double	mid_y;
	double	mid_z;
	double	bak_x;
	double	bak_y;
	double	bak_z;
	double	z_min;
	double	z_max;
}				t_m;

typedef struct	s_view
{
	t_m	*m;
	int	y;
	int	y_lim;
}				t_view;

/*
**		Transformations
*/

void			scale_custom(t_m *m, int i, int j, int zoom);
void			scale_center(t_m *m, double i, double j, double k);
void			translate_xyz(t_m *m, double i, double j, double k);
void			rotate_orbit(t_m *m, double x, double y);
void			rotate_obj(t_m *m, double x, double y, double z);

/*
**		Colour pulsers
*/

void			init_pulse_fp(t_m *m);
void			pulse_dark_rgb(t_xyz **grid, size_t x_count, size_t y_count);
void			pulse_pastel(t_xyz **grid, size_t x_count, size_t y_count);
void			pulse_groovy(t_xyz **grid, size_t x_count, size_t y_count);
void			pulse_wrapper(t_xyz **grid, size_t x_count, size_t y_count,
								void (pulser(t_xyz**, size_t, size_t)));
/*
**		Bresenham's line drawing algorithm
*/

void			bresenham(t_img *img, t_coor c);

/*
**		Cohen-Sutherland line clipping algorithm
*/

void			cohen_sutherland(t_img *img, t_coor c);

/*
**		Keyboard and mouse inputs
*/

void			init_key_fp(t_m *m);
int				key_press_hook(int keycode, t_m *m);
int				key_release_hook(int keycode, t_m *m);

void			init_mouse_fp(t_m *m);
int				mouse_press_hook(int keycode, int x, int y, t_m *m);
int				mouse_release_hook(int keycode, int x, int y, t_m *m);
int				mouse_motion_hook(int x, int y, t_m *m);

/*
**		MLX
*/

void			set_hooks(t_m *m);

/*
**		Utilities
*/

int				init_input(t_m *m, char *arg);
int				init_env(t_m *m);
int				is_valid_hex(char *s);
void			free_dbl(char **arr, int i);
void			reset_xyz(t_m *m);
int				color_inc(int col_1, int col_2, int level);
void			start_draw(t_m *m);
void			write_legend(void);
int				write_error(void);

#endif
