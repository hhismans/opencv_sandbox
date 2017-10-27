/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:40 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 08:53:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube.class.hpp"
#include "../includes/enum.hpp"

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

int	Cube::whichCornerItis(int color1, int color2, int color3)
{
	if (color1 == WHITE || color2 == WHITE || color3 == WHITE)
	{
		if (color1 == RED || color2 == RED || color3 == RED)
		{
			if (color1 == BLUE || color2 == BLUE || color2 == BLUE)
				return ONE;
			else
				return TWO;
		}
		else
		{
			if (color1 == GREEN || color2 == GREEN || color2 == GREEN)
				return THREE;
			else
				return FOUR;
		}
	}
	else
	{
		if (color1 == RED || color2 == RED || color3 == RED)
		{
			if (color1 == BLUE || color2 == BLUE || color2 == BLUE)
				return FIVE;
			else
				return SIX;
		}
		else
		{
			if (color1 == GREEN || color2 == GREEN || color2 == GREEN)
				return SEVEN;
			else
				return EIGHT;
		}
	}
}

int	Cube::whichRidgeItis(int color1, int color2)
{
	if (color1 == WHITE || color2 == WHITE)
	{
		if (color1 == WHITE) color1 = color2;
		if (color1 == RED || color2 == RED) return A_RIDGE;
		else if (color1 == GREEN || color2 == GREEN) return B_RIDGE;
		else if (color1 == ORANGE || color2 == ORANGE) return C_RIDGE;
		else if (color1 == BLUE || color2 == BLUE) return D_RIDGE;
		else cerr << "ERROR in WHICHRIDGEITIS in WHITE" << endl;
	}
	else if(color1 == YELLOW || color2 == YELLOW)
	{
		if (color1 == YELLOW) color1 = color2;
		if (color1 == RED) 			return I_RIDGE;
		else if (color1 == GREEN)	return J_RIDGE;
		else if (color1 == ORANGE)	return K_RIDGE;
		else if (color1 == BLUE) 	return L_RIDGE;
		else cerr << "ERROR in WHICHRIDGEITIS inYELLOW" << endl;
	}
	else if (color1 == RED || color2 == RED)
	{
		if (color1 == RED) color1 = color2;
		if (color1 == BLUE)			return H_RIDGE;
		else if (color1 == GREEN)	return E_RIDGE;
		else cerr << "ERROR in WHICHRIDGEITIS in RED" << endl;
	}
	else if (color1 == ORANGE || color2 == ORANGE)
	{
		if (color1 == RED) color1 = color2;
		if (color1 == GREEN)		return F_RIDGE;
		else if (color1 == GREEN	return G_RIDGE;
		else cerr << "ERROR in WHICHRIDGEITIS in ORANGE" << endl;
	}
}

bool isUD(int color) {return (color == WHITE || color == YELLOW);} // is updown
bool isLR(int color) (return (color == BLUE || color == GREEN);} // is left right
bool isFB(int color) (return (color == RED || color == ORANGE);} // is fornt back
{
	return (color == WHITE || color == YELLOW);
}
int Cube::getPieceOrientation(int position, std::vector<int> faces) // good coin orientation, UD color on UD face
{
	if (position == ONE)
	{
		if (isUD(faces[UP][BOTTOMRIGHT])) return OK;
		else if (isUD(face[RIGHT][TOPLEFT])) return CCW;
		else if (isUD(face[FRONT][TOPRIGHT])) return CW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == TWO)
	{
		if (isUD(faces[UP][BOTTOMLEFT])) return OK;
		else if (isUD(face[LEFT][TOPRIGHT])) return CW;
		else if (isUD(face[FRONT][TOPLEFT])) return CCW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == THREE)
	{
		if (isUD(faces[UP][TOPLEFT])) return OK;
		else if (isUD(face[LEFT][TOPLEFT])) return CCW;
		else if (isUD(face[BACK][TOPRIGHT])) return CW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == FOUR)
	{
		if (isUD(faces[UP][TOPRIGHT])) return OK;
		else if (isUD(face[RIGHT][TOPRIGHT])) return CW;
		else if (isUD(face[BACK][TOPLEFT])) return CCW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == FIVE)
	{
		if (isUD(faces[DOWN][TOPRIGHT])) return OK;
		else if (isUD(face[RIGHT][BOTTOMLEFT])) return CW;
		else if (isUD(face[FRONT][BOTTOMRIGHT])) return CCW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == SIX)
	{
		if (isUD(faces[DOWN][TOPLEFT])) return OK;
		else if (isUD(face[LEFT][BOTTOMRIGHT])) return CCW;
		else if (isUD(face[FRONT][BOTTOMLEFT])) return CW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == SEVEN)
	{
		if (isUD(faces[DOWN][BOTTOMLEFT])) return OK;
		else if (isUD(face[LEFT][BOTTOMLEFT])) return CW;
		else if (isUD(face[BACK][BOTTOMRIGHT])) return CCW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == EIGHT)
	{
		if (isUD(faces[DOWN][BOTTOMRIGHT])) return OK;
		else if (isUD(face[RIGHT][BOTTOMRIGHT])) return CCW;
		else if (isUD(face[FRONT][BOTTOMLEFT])) return CW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
}

//Une arête avec une couleur U/D sur une face U/D est bien orientée.
//Une arête avec une couleur L/R sur une face L/R est bien orientée.
//Une arête avec une couleur U/D sur une face L/R est mal orientée.
//Une arête avec une couleur L/R sur une face U/D est mal orientée.
// cf for visual : https://www.francocube.com/deadalnix/blindfold_step_2
int	getRidgeOrientation(int position, std::vector<int> faces)
{
	switch (position)
	{
		case A_RIDGE: 
			if (isUD(faces[UP][BOTTOMMIDDLE]) || isLR(faces[FRONT][TOPMIDDLE])) return OK;
			else return KO;
			break;
		case B_RIDGE: 
			if (isUD(faces[UP][MIDDLELEFT]) || isLR(faces[LEFT][TOPMIDDLE])) return OK;
			else return KO;
			break;
		case C_RIDGE: 
			if (isUD(faces[UP][TOPMIDDLE]) || isLR(faces[BACK][TOPMIDDLE])) return OK;
			else return KO;
			break;
		case D_RIDGE: 
			if (isUD(faces[UP][TOPMIDDLE]) || isLR(faces[BACK][TOPMIDDLE])) return OK;
			else return KO;
			break;
		case E_RIDGE: 
			if (isUD(faces[FRONT][MIDDLERIGHT]) || isLR(faces[RIGHT][MIDDLELEFT])) return OK;
			else return KO;
			break;
		case F_RIDGE: 
			if (isUD(faces[FRONT][MIDDLELEFT]) || isLR(faces[LEFT][MIDDLERIGHT])) return OK;
			else return KO;
			break;
		case G_RIDGE: 
			if (isUD(faces[BACK][MIDDLERIGHT]) || isLR(faces[LEFT][MIDDLELEFT])) return OK;
			else return KO;
			break;
		case H_RIDGE: 
			if (isUD(faces[BACK][MIDDLELEFT]) || isLR(faces[RIGHT][MIDDLELRIGHT])) return OK;
			else return KO;
			break;
		case I_RIDGE: 
			if (isUD(faces[DOWN][TOPMIDDLE]) || isLR(faces[FRONT][BOTTOMMIDDLE])) return OK;
			else return KO;
			break;
		case J_RIDGE: 
			if (isUD(faces[DOWN][MIDDLELEFT]) || isLR(faces[LEFT][BOTTOMMIDDLE])) return OK;
			else return KO;
			break;
		case K_RIDGE: 
			if (isUD(faces[DOWN][BOTTOMMIDDLE]) || isLR(faces[BACK][BOTTOMMIDDLE])) return OK;
			else return KO;
			break;
		case L_RIDGE: 
			if (isUD(faces[DOWN][MIDDLERIGHT]) || isLR(faces[RIGHT][BOTTOMMIDDLE])) return OK;
			else return KO;
			break;
	}
}

void Cube::initCubeWithFace(std::vector<int> faces)
{
	//finding coin
	_coins[ONE].im		= whichCoinItis(faces[UP][BOTTOMRIGHT],faces[RIGHT][TOPLEFT],faces[FRONT][TOPRIGHT]);
	_coins[TWO].im		= whichCoinItis(faces[UP][BOTTOMLEFT],faces[LEFT][TOPRIGHT],faces[FRONT][TOPLEFT]);
	_coins[THREE].im	= whichCoinItis(faces[UP][TOPLEFT],faces[LEFT][TOPLEFT],faces[BACK][TOPRIGHT]);
	_coins[FOUR].im		= whichCoinItis(faces[UP][TOPRIGHT],faces[RIGHT][TOPRIGHT],faces[BACK][TOPLEFT]);
	_coins[FIVE].im		= whichCoinItis(faces[DOWN][TOPRIGHT],faces[RIGHT][BOTTOMLEFT],faces[FRONT][BOTTOMRIGHT]);
	_coins[SIX].im		= whichCoinItis(faces[DOWN][TOPLEFT],faces[LEFT][BOTTOMRIGHT],faces[FRONT][BOTTOMLEFT]);
	_coins[SEVEN].im	= whichCoinItis(faces[DOWN][BOTTOMLEFT],faces[LEFT][BOTTOMLEFT],faces[BACK][BOTTOMRIGHT]);
	_coins[EIGHT].im	= whichCoinItis(faces[DOWN][BOTTOMRIGHT],faces[RIGHT][BOTTOMRIGHT],faces[BACK][BETTOMLEFT]);

	//orientation of coin
	for (int coin = 0 ; coin < 9 ; coin++)
		_coins[coin].orientation = getPieceOrientation(coin,faces);

	//finding ridge 
	_ridges[A_RIDGE].im = whichRidgeItis(faces[UP][BOTTOMMIDDLE], face[FRONT][TOPMIDDLE]);
	_ridges[B_RIDGE].im = whichRidgeItis(faces[UP][MIDDLELEFT],face[LEFT][TOPMIDDLE]);
	_ridges[C_RIDGE].im = whichRidgeItis(faces[UP][TOPMIDDLE], face[BACK][TOPMIDDLE]);
	_ridges[D_RIDGE].im = whichRidgeItis(faces[UP][MIDDLERIGHT], face[RIGHT][TOPMIDDLE]);

	_ridges[E_RIDGE].im = whichRidgeItis(faces[FRONT][MIDDLERIGHT], face[RIGHT][MIDDLELEFT]);
	_ridges[F_RIDGE].im = whichRidgeItis(faces[FRONT][MIDDLELEFT], face[LEFT][MIDDLERIGHT]);
	_ridges[G_RIDGE].im = whichRidgeItis(faces[BACK][MIDDLERIGHT], face[LEFT][MIDDLELEFT]);
	_ridges[H_RIDGE].im = whichRidgeItis(faces[BACK][MIDDLELEFT], face[RIGHT][MIDDLERIGHT]);

	_ridges[I_RIDGE].im = whichRidgeItis(faces[DOWN][TOPMIDDLE], face[FRONT][BOTTOMMIDDLE]);
	_ridges[J_RIDGE].im = whichRidgeItis(faces[DOWN][MIDDLELEFT], face[LEFT][BOTTOMMIDDLE]);
	_ridges[K_RIDGE].im = whichRidgeItis(faces[DOWN][BOTTOMMIDDLE], face[BACK][BOTTOMMIDDLE]);
	_ridges[L_RIDGE].im = whichRidgeItis(faces[DOWN][MIDDLERIGHT], face[RIGHT][BOTTOMMIDDLE]);

	for (int ridge = 0; ridge < 12; ridge++)
		_ridges.orientation = getRidgeOrientation(ridge, faces);
	// YOUHOU !
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
