/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:33:27 by jchow             #+#    #+#             */
/*   Updated: 2017/09/13 06:03:03 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "function_pointers.h"

static void	key_protect(t_m *prevents, int segfaults)
{
	(void)prevents;
	(void)segfaults;
}

static void	add_protection(t_m *m)
{
	int	i;

	i = -1;
	while (++i < 280)
		m->key_fp[i] = &key_protect;
}

int			key_press_hook(int keycode, t_m *m)
{
	if (keycode < 280)
		m->key_fp[keycode](m, 1);
	return (1);
}

int			key_release_hook(int keycode, t_m *m)
{
	if (keycode < 280)
		m->key_fp[keycode](m, 0);
	return (1);
}

void		init_key_fp(t_m *m)
{
	add_protection(m);
	m->key_fp[KEY_UP] = &key_fp_up;
	m->key_fp[KEY_DOWN] = &key_fp_down;
	m->key_fp[KEY_LEFT] = &key_fp_left;
	m->key_fp[KEY_RIGHT] = &key_fp_right;
	m->key_fp[KEY_NUM_0] = &key_fp_numpad_0;
	m->key_fp[KEY_NUM_2] = &key_fp_numpad_2;
	m->key_fp[KEY_NUM_4] = &key_fp_numpad_4;
	m->key_fp[KEY_NUM_6] = &key_fp_numpad_6;
	m->key_fp[KEY_NUM_7] = &key_fp_numpad_7;
	m->key_fp[KEY_NUM_8] = &key_fp_numpad_8;
	m->key_fp[KEY_NUM_9] = &key_fp_numpad_9;
	m->key_fp[KEY_PLUS] = &key_fp_plus;
	m->key_fp[KEY_MINUS] = &key_fp_minus;
	m->key_fp[KEY_MULTIPLY] = &key_fp_multiply;
	m->key_fp[KEY_DIVIDE] = &key_fp_divide;
	m->key_fp[KEY_ESC] = &key_fp_esc;
	m->key_fp[KEY_FN] = &key_fp_fn;
	m->key_fp[KEY_DEL] = &key_fp_bk_del;
	m->key_fp[KEY_HOME] = &key_fp_home;
	m->key_fp[KEY_END] = &key_fp_end;
	m->key_fp[KEY_PAGE_UP] = &key_fp_pg_up;
	m->key_fp[KEY_PAGE_DOWN] = &key_fp_pg_down;
}
