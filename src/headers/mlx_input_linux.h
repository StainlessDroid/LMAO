/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_linux.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:41:17 by mpascual          #+#    #+#             */
/*   Updated: 2023/02/18 16:45:46 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INPUT_LINUX_H
# define MLX_INPUT_LINUX_H

typedef enum s_mbutton
{
	MBUTTON_LEFT = 1,
	MBUTTON_RIGHT = 3,
	MBUTTON_MIDDLE = 2,
	MBUTTON_SCROLLUP = 4,
	MBUTTON_SCROLLDOWN = 5,
	MBUTTON_SIDE1 = 8,
	MBUTTON_SIDE2 = 9,
	MBUTTON_SCROLLLEFT = 6,
	MBUTTON_SCROLLRIGHT = 7,
}				t_mbutton;

typedef enum s_keys
{
	KEY_Q = 113,
	KEY_W = 119,
	KEY_E = 101,
	KEY_R = 114,
	KEY_T = 116,
	KEY_Y = 121,
	KEY_U = 117,
	KEY_I = 105,
	KEY_O = 111,
	KEY_P = 112,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
    KEY_Ñ = 241,
	KEY_Z = 122,
	KEY_X = 120,
	KEY_C = 99,
	KEY_V = 118,
	KEY_B = 98,
	KEY_N = 110,
	KEY_M = 109,
	KEY_1 = 49,
	KEY_2 = 50,
	KEY_3 = 51,
	KEY_4 = 52,
	KEY_5 = 53,
	KEY_6 = 54,
	KEY_7 = 55,
	KEY_8 = 56,
	KEY_9 = 57,
    KEY_0 = 48,
	KEY_MINUS = 45,
    KEY_PLUS = 43,
	KEY_SEMICOLON = 41,
    KEY_QUOTE = 39,
	KEY_COLON = 44,
	KEY_DOT = 46,
	KEY_TAB = 65289,
	KEY_CAPS = 272,
	KEY_LSHIFT = 65505,
	KEY_LCTRL = 65507,
	KEY_LALT = 65513,
	KEY_RALT = 65027,
	KEY_RCTRL = 65508,
	KEY_RSHIFT = 655,
	KEY_ENTER = 65293,
    KEY_BACKSPACE = 65288,
	KEY_SPACE = 32,
	KEY_ESCAPE = 65307,
	KEY_ARROW_LEFT = 65361,
	KEY_ARROW_RIGHT = 65363,
	KEY_ARROW_DOWN = 65364,
	KEY_ARROW_UP = 65362,
	KEY_INSERT = 65379,
	KEY_END = 65367,
	KEY_DELETE = 65535,
	KEY_HOME = 65360,
	KEY_PAGEUP = 65366,
	KEY_PAGEDOWN = 65365,
}			t_keys;

#endif