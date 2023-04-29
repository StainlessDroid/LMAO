/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:43:40 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/18 12:44:13 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INPUT_H
# define MLX_INPUT_H

typedef enum e_mbutton
{
	MBUTTON_LEFT = 1,
	MBUTTON_RIGHT = 2,
	MBUTTON_MIDDLE = 3,
	MBUTTON_SCROLLUP = 4,
	MBUTTON_SCROLLDOWN = 5
}				t_mbutton;

typedef enum e_keys
{
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	KEY_R = 15,
	KEY_T = 17,
	KEY_Y = 16,
	KEY_U = 32,
	KEY_I = 34,
	KEY_O = 31,
	KEY_P = 35,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_Z = 6,
	KEY_X = 7,
	KEY_C = 8,
	KEY_V = 9,
	KEY_B = 11,
	KEY_N = 45,
	KEY_M = 46,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 26,
	KEY_7 = 28,
	KEY_8 = 25,
	KEY_0 = 29,
	KEY_MINUS = 27,
	KEY_EQUAL = 24,
	KEY_LBRACKET = 33,
	KEY_RBRACKET = 30,
	KEY_BACKSLASH = 42,
	KEY_SEMICOLON = 41,
	KEY_QUOTE = 39,
	KEY_COLON = 33,
	KEY_DOT = 47,
	KEY_SLASH = 44,
	KEY_BACKQUOTE = 50,
	KEY_TAB = 46,
	KEY_CAPS = 272,
	KEY_LSHIFT = 257,
	KEY_LCTRL = 256,
	KEY_CMD = 259,
	KEY_LALT = 261,
	KEY_RALT = 262,
	KEY_RCTRL = 269,
	KEY_RSHIFT = 258,
	KEY_ENTER = 36,
	KEY_RETURN = 51,
	KEY_SPACE = 49,
	KEY_ESCAPE = 53,
	KEY_ARROW_LEFT = 123,
	KEY_ARROW_RIGHT = 124,
	KEY_ARROW_DOWN = 125,
	KEY_ARROW_UP = 126,
	KEY_INSERT = 114,
	KEY_END = 119,
	KEY_DELETE = 117,
	KEY_HOME = 115,
	KEY_PAGEUP = 116,
	KEY_PAGEDOWN = 121,
	KEY_PAD_LOCK = 71,
	KEY_PAD_SLASH = 67,
	KEY_PAD_STAR = 75,
	KEY_PAD_MINUS = 78,
	KEY_PAD_PLUS = 69,
	KEY_PAD_ENTER = 76,
	KEY_PAD_DOT = 65,
	KEY_PAD_0 = 82,
	KEY_PAD_1 = 83,
	KEY_PAD_2 = 84,
	KEY_PAD_3 = 85,
	KEY_PAD_4 = 86,
	KEY_PAD_5 = 87,
	KEY_PAD_6 = 88,
	KEY_PAD_7 = 89,
	KEY_PAD_8 = 91,
	KEY_PAD_9 = 92,
}			t_keys;

#endif