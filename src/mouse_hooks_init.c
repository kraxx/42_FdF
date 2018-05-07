/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:27:59 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:27:59 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "function_pointers.h"

static void	mouse_protect(t_m *protection, int from, int segfaults)
{
	(void)protection;
	(void)from;
	(void)segfaults;
}

int			mouse_press_hook(int keycode, int x, int y, t_m *m)
{
	if (keycode < 6 && x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT)
		m->mouse_fp[keycode](m, x, y);
	return (1);
}

int			mouse_release_hook(int keycode, int x, int y, t_m *m)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_LEFT_CLICK)
		m->togs->mouse_left = 0;
	if (keycode == MOUSE_RIGHT_CLICK)
		m->togs->mouse_right = 0;
	if (keycode == MOUSE_WHEEL_CLICK)
		m->togs->mouse_wheel = 0;
	return (1);
}

int			mouse_motion_hook(int x, int y, t_m *m)
{
	if (m->togs->mouse_left)
	{
		translate_xyz(m, x - m->mouse_left_x, y - m->mouse_left_y, 0);
		m->mouse_left_x += x - m->mouse_left_x;
		m->mouse_left_y += y - m->mouse_left_y;
	}
	if (m->togs->mouse_right)
	{
		rotate_obj(m, -(y - m->mouse_right_y) * MOUSE_SENS,
			(x - m->mouse_right_x) * MOUSE_SENS, 0);
		m->mouse_right_x += x - m->mouse_right_x;
		m->mouse_right_y += y - m->mouse_right_y;
	}
	if (m->togs->mouse_wheel)
		rotate_orbit(m, -(y - m->mouse_wheel_y) * MOUSE_SENS,
			(x - m->mouse_wheel_x) * MOUSE_SENS);
	if (m->togs->draw_toggle)
		start_draw(m);
	return (1);
}

void		init_mouse_fp(t_m *m)
{
	m->mouse_fp[0] = &mouse_protect;
	m->mouse_fp[MOUSE_LEFT_CLICK] = &mouse_press_left_click;
	m->mouse_fp[MOUSE_RIGHT_CLICK] = &mouse_press_right_click;
	m->mouse_fp[MOUSE_WHEEL_CLICK] = &mouse_press_wheel_click;
	m->mouse_fp[MOUSE_SCROLL_UP] = &mouse_press_scroll_up;
	m->mouse_fp[MOUSE_SCROLL_DOWN] = &mouse_press_scroll_down;
}
