/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_pointers5.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:08:46 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:08:47 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_fp_numpad_7(t_m *m, int press)
{
	m->togs->numpad_7 = press ? 1 : 0;
}

void	key_fp_numpad_9(t_m *m, int press)
{
	m->togs->numpad_9 = press ? 1 : 0;
}

void	key_fp_numpad_0(t_m *m, int press)
{
	if (press)
	{
		reset_xyz(m);
		start_draw(m);
	}
}

void	key_fp_esc(t_m *m, int press)
{
	if (press)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(0);
	}
}
