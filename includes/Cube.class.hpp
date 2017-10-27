/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:59 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 03:20:38 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm> // std::find
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgproc/imgproc.hpp"

using namespace cv; // SHAME
using namespace std;

enum Instruction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	BACK,
	FRONT,
	RUP,
	RDOWN,
	RLEFT,
	RRIGHT,
	RBACK,
	RFRONT
}

enum CornerPosition
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEXEN,
	EIGHT
}

enum Rotation
{
	CW, //clockwise
	CCW // countterclockwise
}
enum CornerOrientation
{
	ALPHA,
	BETA,
	GAMMA
}

enum RidgePosition
{
	A_RIDGE,
	B_RIDGE,
	C_RIDGE,
	D_RIDGE,
	E_RIDGE,
	F_RIDGE,
	G_RIDGE,
	I_RIDGE,
	J_RIDGE,
	K_RIDGE,
	L_RIDGE
}

enum RidgeOrientation
{
	TRUE,
	FALSE
}

class Cube
{
	public:
		Scalar _face[6][9];
		Cube( void );
		Cube( Cube const & src );
		~Cube( void );
		void changeFace(int faceId, std::vector<int> face);
		Cube &	operator=( Cube const & rhs);

		//detection
		void changeFace(int faceId, std::vector<int> face);

		//algo
		static void			move(Instruction instruction);
	private:
		/*
		 * Cube decrit comme 8 coin et 12 arete.
		 * Chaque arete 
		 * */
		Corner _corners[8];
		Ridge  _ridges[12];
};

std::ostream &		operator<<(std::ostream & out, const Npuzzle &rhs);

#endif
