/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_function_pointers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 04:39:38 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:04:12 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_press_left_click(t_m *m, int x, int y)
{
	if (!m->togs->mouse_left)
	{
		m->mouse_left_x = x;
		m->mouse_left_y = y;
	}
	m->togs->mouse_left = 1;
}

void	mouse_press_right_click(t_m *m, int x, int y)
{
	if (!m->togs->mouse_right)
	{
		m->mouse_right_x = x;
		m->mouse_right_y = y;
	}
	m->togs->mouse_right = 1;
}

void	mouse_press_wheel_click(t_m *m, int x, int y)
{
	if (!m->togs->mouse_wheel)
	{
		m->mouse_wheel_x = x;
		m->mouse_wheel_y = y;
	}
	m->togs->mouse_wheel = 1;
}

void	mouse_press_scroll_up(t_m *m, int x, int y)
{
	scale_custom(m, x, y, 1);
	start_draw(m);
}

void	mouse_press_scroll_down(t_m *m, int x, int y)
{
	scale_custom(m, x, y, 0);
	start_draw(m);
}
