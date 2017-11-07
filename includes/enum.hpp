/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 04:29:36 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/07 09:22:46 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_HPP
# define ENUM_HPP


#define DEFAULT -1
enum
{
	TOPLEFT,
	TOPMIDDLE,      // position square on a face as
	TOPRIGHT,		// 0 1 2
	MIDDLELEFT,		// 3 4 5
	CENTER,			// 6 7 8
	MIDDLERIGHT,
	BOTTOMLEFT,
	BOTTOMMIDDLE,
	BOTTOMRIGHT
};  // position square on a face as

enum
{
	WHITE,
	ORANGE,
	GREEN,
	RED,
	BLUE,
	YELLOW
};

enum EFace
{
	UP,
	BACK,
	LEFT,
	FRONT,
	RIGHT,
	DOWN
};

enum // face enum
{
	FACEUP,
	FACEBACK,
	FACELEFT,
	FACEFRONT,
	FACERIGHT,
	FACEDOWN
};

enum // hsv config enum
{
	H_MIN,
	H_MAX,
	S_MIN,
	S_MAX,
	V_MIN,
	V_MAX
};


enum Instruction
{
	IUP,
	IDOWN,
	ILEFT,
	IRIGHT,
	IBACK,
	IFRONT,
	IRUP,
	IRDOWN,
	IRLEFT,
	IRRIGHT,
	IRBACK,
	IRFRONT,
	ERROR = -1
};

enum CornerPosition
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
};

enum Rotation
{
	CW, //clockwise
	CCW, // countterclockwise
	OK,
	KO
};

enum CornerOrientation
{
	ALPHA,
	BETA,
	GAMMA
};

enum RidgePosition
{
	A_RIDGE,
	B_RIDGE,
	C_RIDGE,
	D_RIDGE,
	E_RIDGE,
	F_RIDGE,
	G_RIDGE,
	H_RIDGE,
	I_RIDGE,
	J_RIDGE,
	K_RIDGE,
	L_RIDGE
};

enum RidgeOrientation
{
	TRUE,
	FALSE
};


#endif
