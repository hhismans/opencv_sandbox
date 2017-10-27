/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:40 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 03:19:09 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube.class.hpp"
enum
{
	WHITE,
	ORANGE,
	GREEN,
	RED,
	BLUE,
	YELLOW
};

void Cube::changeFace(int faceId, std::vector<int> face)
{
	for (int i = 0; i < 9; i++)
	switch (face[i])
	{
		case WHITE	: _face[faceId][i] = Scalar(255,255,255);break;
		case ORANGE	: _face[faceId][i] = Scalar(0,125,255);break;
		case GREEN	: _face[faceId][i] = Scalar(0,255,0);break;
		case RED	: _face[faceId][i] = Scalar(0,0,255);break;
		case BLUE	: _face[faceId][i] = Scalar(255,0,0);break;
		case YELLOW : _face[faceId][i] = Scalar(0,255,255);break;
	}
}


Cube::Cube( void )
{
cout << "cube created" << endl;
	for (int face = 0; face < 6 ; face++)
	{
		for (int square = 0; square < 9; square++)
		{
			switch (face)
			{
				case WHITE : _face[face][square] = Scalar(255,255,255);break;
				case ORANGE : _face[face][square] = Scalar(0,125,255);break;
				case GREEN : _face[face][square] = Scalar(0,255,0);break;
				case RED : _face[face][square] = Scalar(0,0,255);break;
				case BLUE : _face[face][square] = Scalar(255,0,0);break;
				case YELLOW : _face[face][square] = Scalar(0,255,255);break;
			}
		}
	}
}

Cube::Cube( Cube const & src )
{
}

Cube::~Cube( void )
{
}
/*Cube &Cube::operator=( Cube const & rhs )
{
}*/

// part 2
#include "rubiks.class.hpp"


Cube::~Cube(void) {}
// cycle A -> B -> C -> D -> A [A,B,C,D]
void Cube::cyclingRidge(std::vector<RidgePosition> & cycle, bool changeOrientation)
{
	Ridge r_tmp;
	r_tmp = _ridges[cycle.back()];
	for (int pos = 0; pos < cycle.size(); pos++)
	{
		_ridges[cycle[pos + 1]] = _ridges[cycle[pos]];
		if (changeOrientation)
			_ridges[cycle[pos + 1]].side = !_ridges[cycle[pos + 1]].side;
	}
		_ridges[cycle.front()] = r_tmp;
		if (changeOrientation)
			_ridges[cycle.front()] = ! _ridges[cycle.front()];
}

void Cube::up(Instruction instruction)
{
	cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
/*	Ridge r_tmp;
	
	r_tmp = _ridges[D_RIDGE];
	for (RidgePosition pos = A_RIDGE; pos < D_RIDGE; pos++)
		_ridges[pos + 1] = _ridges[pos];
	_ridges[A_RIDGE] = r_tmp;*/ 
}

void Cube::move(Instruction instruction)
{
	std::vector<RidgePosition> cyclesRidge[12];
	cyclesRidge[UP] = [ONE,TWO,THREE,FOUR];

	switch (instruction)
	{
		case UP :	cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case DOWN : cyclingRidge([I_RIDGE,J_RIDGE,K_RIDGE,L_RIDGE], false);
					cyclingCorner([FIVE,SIX,SEVEN,EIGHT], false);
					break;
		case LEFT : cyclingRidge([B_RIDGE,E_RIDGE,J_RIDGE,F_RIDGE], true);
					cyclingCorner([TWO,,THREE,FOUR], true);
					break;
		case RIGHT: cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case BACK:  cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case FRONT: cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RUP :	 cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RDOWN : cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RLEFT : cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RRIGHT: cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RBACK:  cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
		case RFRONT: cyclingRidge([A_RIDGE,B_RIDGE,C_RIDGE,D_RIDGE], false);
					cyclingCorner([ONE,TWO,THREE,FOUR], false);
					break;
	}
}
