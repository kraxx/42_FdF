/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:20:12 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:20:13 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose_hook(t_m *m)
{
	start_draw(m);
	return (1);
}

static void	loop_hook2(t_m *m)
{
	if (m->togs->numpad_plus)
		scale_center(m, ZOOM_IN, ZOOM_IN, 1);
	if (m->togs->numpad_minus)
		scale_center(m, ZOOM_OUT, ZOOM_OUT, 1);
	if (m->togs->fn)
		scale_center(m, ZOOM_IN, 1, 1);
	if (m->togs->bk_del)
		scale_center(m, ZOOM_OUT, 1, 1);
	if (m->togs->home)
		scale_center(m, 1, ZOOM_IN, 1);
	if (m->togs->end)
		scale_center(m, 1, ZOOM_OUT, 1);
	if (m->togs->pg_up)
		scale_center(m, 1, 1, Z_SCALE_UP);
	if (m->togs->pg_down)
		scale_center(m, 1, 1, Z_SCALE_DOWN);
	if (m->togs->pulse_toggle || m->togs->draw_toggle)
		start_draw(m);
	if (m->togs->pulse_toggle)
		pulse_wrapper(m->grid, m->x_count, m->y_count,
			m->pulse_fp[m->current_pulser]);
}

static int	loop_hook(t_m *m)
{
	m->togs->draw_toggle = 0;
	if (m->togs->up)
		translate_xyz(m, 0, -TRANSLATE, 0);
	if (m->togs->down)
		translate_xyz(m, 0, TRANSLATE, 0);
	if (m->togs->left)
		translate_xyz(m, -TRANSLATE, 0, 0);
	if (m->togs->right)
		translate_xyz(m, TRANSLATE, 0, 0);
	if (m->togs->numpad_8)
		rotate_obj(m, 1, 0, 0);
	if (m->togs->numpad_2)
		rotate_obj(m, -1, 0, 0);
	if (m->togs->numpad_4)
		rotate_obj(m, 0, -1, 0);
	if (m->togs->numpad_6)
		rotate_obj(m, 0, 1, 0);
	if (m->togs->numpad_7)
		rotate_obj(m, 0, 0, -1);
	if (m->togs->numpad_9)
		rotate_obj(m, 0, 0, 1);
	loop_hook2(m);
	return (1);
}

static int	exit_hook(t_m *m)
{
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}

void		set_hooks(t_m *m)
{
	mlx_hook(m->win, 12, 0, expose_hook, m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	mlx_hook(m->win, 3, 0, key_release_hook, m);
	mlx_hook(m->win, 4, 0, mouse_press_hook, m);
	mlx_hook(m->win, 5, 0, mouse_release_hook, m);
	mlx_hook(m->win, 6, 0, mouse_motion_hook, m);
	mlx_hook(m->win, 17, 0, exit_hook, m);
	mlx_loop_hook(m->mlx, loop_hook, m);
	init_mouse_fp(m);
	init_key_fp(m);
	init_pulse_fp(m);
}
