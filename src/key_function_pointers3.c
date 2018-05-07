/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_pointers3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:08:36 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:08:37 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_fp_pg_down(t_m *m, int press)
{
	m->togs->pg_down = press ? 1 : 0;
}

void	key_fp_plus(t_m *m, int press)
{
	m->togs->numpad_plus = press ? 1 : 0;
}

void	key_fp_minus(t_m *m, int press)
{
	m->togs->numpad_minus = press ? 1 : 0;
}

void	key_fp_multiply(t_m *m, int press)
{
	if (press)
	{
		if (m->current_pulser == NUM_PULSERS - 1)
			m->current_pulser = 0;
		else
			m->current_pulser++;
	}
}

void	key_fp_divide(t_m *m, int press)
{
	if (press)
		m->togs->pulse_toggle = !m->togs->pulse_toggle;
}
