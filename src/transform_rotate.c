/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:40:46 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 15:40:47 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_z(t_m *m, double sin, double cos)
{
	double	bak_x;
	double	bak_y;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_x = m->grid[y][x].x;
			bak_y = m->grid[y][x].y;
			m->grid[y][x].x = bak_x * cos - bak_y * sin;
			m->grid[y][x].y = bak_x * sin + bak_y * cos;
		}
	}
}

static void	rotate_y(t_m *m, double sin, double cos)
{
	double	bak_x;
	double	bak_z;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_x = m->grid[y][x].x;
			bak_z = m->grid[y][x].z;
			m->grid[y][x].x = bak_x * cos + bak_z * sin;
			m->grid[y][x].z = -(bak_x * sin) + bak_z * cos;
		}
	}
}

static void	rotate_x(t_m *m, double sin, double cos)
{
	double	bak_y;
	double	bak_z;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_y = m->grid[y][x].y;
			bak_z = m->grid[y][x].z;
			m->grid[y][x].y = bak_y * cos - bak_z * sin;
			m->grid[y][x].z = bak_y * sin + bak_z * cos;
		}
	}
}

void		rotate_orbit(t_m *m, double x, double y)
{
	double temp_z;

	temp_z = -m->mid_z;
	translate_xyz(m, -m->mouse_wheel_x, -m->mouse_wheel_y, -m->mid_z);
	if (x)
		rotate_x(m, sin(x * ROT * MOUSE_SENS), cos(x * ROT * MOUSE_SENS));
	if (y)
		rotate_y(m, sin(y * ROT * MOUSE_SENS), cos(y * ROT * MOUSE_SENS));
	translate_xyz(m, m->mouse_wheel_x, m->mouse_wheel_y, temp_z);
	m->togs->draw_toggle = 1;
}

void		rotate_obj(t_m *m, double x, double y, double z)
{
	double temp[3];

	temp[0] = m->mid_x;
	temp[1] = m->mid_y;
	temp[2] = m->mid_z;
	translate_xyz(m, -m->mid_x, -m->mid_y, -m->mid_z);
	if (x)
		rotate_x(m, sin(x * ROT), cos(x * ROT));
	if (y)
		rotate_y(m, sin(y * ROT), cos(y * ROT));
	if (z)
		rotate_z(m, sin(z * ROT), cos(z * ROT));
	translate_xyz(m, temp[0], temp[1], temp[2]);
	m->togs->draw_toggle = 1;
}
