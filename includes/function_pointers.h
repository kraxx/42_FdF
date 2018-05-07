/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:11:07 by jchow             #+#    #+#             */
/*   Updated: 2018/05/05 17:11:08 by jchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_POINTERS_H
# define FUNCTION_POINTERS_H

# include "fdf.h"

/*
**		Keyboard event function pointers
*/

void	key_fp_up(t_m *m, int press);
void	key_fp_down(t_m *m, int press);
void	key_fp_left(t_m *m, int press);
void	key_fp_right(t_m *m, int press);
void	key_fp_fn(t_m *m, int press);
void	key_fp_bk_del(t_m *m, int press);
void	key_fp_home(t_m *m, int press);
void	key_fp_end(t_m *m, int press);
void	key_fp_pg_up(t_m *m, int press);
void	key_fp_pg_down(t_m *m, int press);
void	key_fp_plus(t_m *m, int press);
void	key_fp_minus(t_m *m, int press);
void	key_fp_multiply(t_m *m, int press);
void	key_fp_divide(t_m *m, int press);
void	key_fp_numpad_2(t_m *m, int press);
void	key_fp_numpad_4(t_m *m, int press);
void	key_fp_numpad_6(t_m *m, int press);
void	key_fp_numpad_7(t_m *m, int press);
void	key_fp_numpad_8(t_m *m, int press);
void	key_fp_numpad_9(t_m *m, int press);
void	key_fp_numpad_0(t_m *m, int press);
void	key_fp_esc(t_m *m, int press);

/*
**		Mouse event function pointers
*/

void	mouse_press_left_click(t_m *m, int x, int y);
void	mouse_press_right_click(t_m *m, int x, int y);
void	mouse_press_wheel_click(t_m *m, int x, int y);
void	mouse_press_scroll_up(t_m *m, int x, int y);
void	mouse_press_scroll_down(t_m *m, int x, int y);

#endif
