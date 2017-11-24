/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:40 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/24 16:11:42 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube.class.hpp"
#include "../includes/enum.hpp"

//TODO : movestring()


const int Cube::_tup[]		=	{A_RIDGE,D_RIDGE,C_RIDGE,B_RIDGE};
const int Cube::_tdown[]	=	{I_RIDGE,J_RIDGE,K_RIDGE,L_RIDGE};
const int Cube::_tleft[]	=	{B_RIDGE,F_RIDGE,J_RIDGE,E_RIDGE};
const int Cube::_tright[]	=	{D_RIDGE,H_RIDGE,L_RIDGE,G_RIDGE};
const int Cube::_tback[]	=	{C_RIDGE,G_RIDGE,K_RIDGE,F_RIDGE};
const int Cube::_tfront[]	=	{A_RIDGE,E_RIDGE,I_RIDGE,H_RIDGE};

const int Cube::_cup[]	=		{ONE, FOUR, THREE, TWO};
const int Cube::_cdown[]	=	{FIVE, SIX, SEVEN, EIGHT};
const int Cube::_cleft[]	=	{TWO, THREE,SEVEN, SIX};
const int Cube::_cright[]	=	{ONE, FIVE, EIGHT, FOUR};
const int Cube::_cback[]	=	{FOUR, EIGHT, SEVEN, THREE};
const int Cube::_cfront[]	=	{ONE, TWO, SIX, FIVE};


ostream& operator<<(ostream& os, const Cube& cube)
{
	for (int i = 0; i < 6; i++)
	{
		os << "face " << i << endl;
		for (int j = 0; j < 9; j++)
		{
			if (!(j %3)) os << endl;
			os << cube._intFace[i][j];
		}
		os << endl;
	}
	os << "-------------------" << endl;
	for (int i = 0; i < 8; i++)
	{
		os << "Corner " << i + 1 << " is " << cube._coins[i] << " and need ";
		if (cube._coins[i]._orientation == CW)
			os << "CW";
		else if (cube._coins[i]._orientation == CCW)
			os << "CCW";
		else
			os << "ok";
		os <<endl;
	}
	os <<endl;
	for (int i = 0; i < 12; i++)
	{
		os << "ridge " << char(i + 'A') << " is " << cube._ridges[i] << " and is ";
		cube._ridges[i]._orientation == OK ?  os << "OK" : os << "KO";
		os << endl;
	}
	os << "---------------------------------------" << endl;
	return os;
}

void Cube::changeFace(int faceId, std::vector<int> face)
{
	for (int i = 0; i < 9; i++)
	{
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
		else cerr << "ERROR in WHICHRIDGEITIS in WHITE (" << color1 << " "<< color2 << endl;
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
		if (color1 == ORANGE) color1 = color2;
		if (color1 == GREEN)		return F_RIDGE;
		else if (color1 == BLUE)	return G_RIDGE;
		else cerr << "ERROR in WHICHRIDGEITIS in ORANGE" << endl;
	}
	return DEFAULT;
}

bool isUD(int color) {return (color == WHITE || color == YELLOW);} // is updown
bool isLR(int color) {return (color == BLUE || color == GREEN);} // is left right
bool isFB(int color) {return (color == RED || color == ORANGE);} // is fornt back

int Cube::getPieceOrientation(int position, int faces[6][9]) // good coin orientation, UD color on UD face
{
	if (position == ONE)
	{
		if (isUD(faces[UP][BOTTOMRIGHT])) return OK;
		else if (isUD(faces[RIGHT][TOPLEFT])) return CCW;
		else if (isUD(faces[FRONT][TOPRIGHT])) return CW;
		else cerr << "ERROR in pieceOrientation in ONE" << endl;
	}
	else if (position == TWO)
	{
		if (isUD(faces[UP][BOTTOMLEFT])) return OK;
		else if (isUD(faces[LEFT][TOPRIGHT])) return CW;
		else if (isUD(faces[FRONT][TOPLEFT])) return CCW;
		else cerr << "ERROR in pieceOrientation in TWO" << endl;
	}
	else if (position == THREE)
	{
		if (isUD(faces[UP][TOPLEFT])) return OK;
		else if (isUD(faces[LEFT][TOPLEFT])) return CCW;
		else if (isUD(faces[BACK][TOPRIGHT])) return CW;
		else cerr << "ERROR in pieceOrientation in THREE" << endl;
	}
	else if (position == FOUR)
	{
		if (isUD(faces[UP][TOPRIGHT])) return OK;
		else if (isUD(faces[RIGHT][TOPRIGHT])) return CW;
		else if (isUD(faces[BACK][TOPLEFT])) return CCW;
		else cerr << "ERROR in pieceOrientation in FOUR" << endl;
	}
	else if (position == FIVE)
	{
		if (isUD(faces[DOWN][TOPRIGHT])) return OK;
		else if (isUD(faces[RIGHT][BOTTOMLEFT])) return CW;
		else if (isUD(faces[FRONT][BOTTOMRIGHT])) return CCW;
		else cerr << "ERROR in pieceOrientation in FICE" << endl;
	}
	else if (position == SIX)
	{
		if (isUD(faces[DOWN][TOPLEFT])) return OK;
		else if (isUD(faces[LEFT][BOTTOMRIGHT])) return CCW;
		else if (isUD(faces[FRONT][BOTTOMLEFT])) return CW;
		else cerr << "ERROR in pieceOrientation in SIX" << endl;
	}
	else if (position == SEVEN)
	{
		if (isUD(faces[DOWN][BOTTOMLEFT])) return OK;
		else if (isUD(faces[LEFT][BOTTOMLEFT])) return CW;
		else if (isUD(faces[BACK][BOTTOMRIGHT])) return CCW;
		else cerr << "ERROR in pieceOrientation in SEVEn" << *this<<  endl;
	}
	else if (position == EIGHT)
	{
		if (isUD(faces[DOWN][BOTTOMRIGHT])) return OK;
		else if (isUD(faces[RIGHT][BOTTOMRIGHT])) return CCW;
		else if (isUD(faces[FRONT][BOTTOMLEFT])) return CW;
		else cerr << "ERROR in pieceOrientation in EIGHT" << endl;
	}
	return -1;
}

//Une arête avec une couleur U/D sur une face U/D est bien orientée.
//Une arête avec une couleur L/R sur une face L/R est bien orientée.
//Une arête avec une couleur U/D sur une face L/R est mal orientée.
//Une arête avec une couleur L/R sur une face U/D est mal orientée.
// cf for visual : https://www.francocube.com/deadalnix/blindfold_step_2
int	getRidgeOrientation(int position, int faces[6][9])
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
			if (isUD(faces[BACK][MIDDLELEFT]) || isLR(faces[RIGHT][MIDDLERIGHT])) return OK;
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
	return -1;
}

void Cube::init()
{
	//initCubeWithFace(_intFace);
	_ridges[A_RIDGE]._im = H_RIDGE;
	_ridges[B_RIDGE]._im = H_RIDGE;
	_ridges[C_RIDGE]._im = H_RIDGE;
	_ridges[D_RIDGE]._im = D_RIDGE;

	_ridges[A_RIDGE]._orientation = KO;
	_ridges[B_RIDGE]._orientation = KO;
	_ridges[C_RIDGE]._orientation = OK;
	_ridges[D_RIDGE]._orientation = KO;

	_ridges[A_RIDGE]._im = C_RIDGE;
	_ridges[A_RIDGE]._orientation = OK;

	_ridges[B_RIDGE]._im = H_RIDGE;
	_ridges[B_RIDGE]._orientation = KO;
	_ridges[C_RIDGE]._im = H_RIDGE;
	_ridges[C_RIDGE]._orientation = KO;
	_ridges[D_RIDGE]._im = H_RIDGE;
	_ridges[D_RIDGE]._orientation = KO;

}

void Cube::initCubeWithFace(int faces[6][9])
{
	//finding coin
	_coins[ONE]._im		= whichCornerItis(faces[UP][BOTTOMRIGHT],faces[RIGHT][TOPLEFT],faces[FRONT][TOPRIGHT]);
	_coins[TWO]._im		= whichCornerItis(faces[UP][BOTTOMLEFT],faces[LEFT][TOPRIGHT],faces[FRONT][TOPLEFT]);
	_coins[THREE]._im	= whichCornerItis(faces[UP][TOPLEFT],faces[LEFT][TOPLEFT],faces[BACK][TOPRIGHT]);
	_coins[FOUR]._im	= whichCornerItis(faces[UP][TOPRIGHT],faces[RIGHT][TOPRIGHT],faces[BACK][TOPLEFT]);
	_coins[FIVE]._im	= whichCornerItis(faces[DOWN][TOPRIGHT],faces[RIGHT][BOTTOMLEFT],faces[FRONT][BOTTOMRIGHT]);
	_coins[SIX]._im		= whichCornerItis(faces[DOWN][TOPLEFT],faces[LEFT][BOTTOMRIGHT],faces[FRONT][BOTTOMLEFT]);
	_coins[SEVEN]._im	= whichCornerItis(faces[DOWN][BOTTOMLEFT],faces[LEFT][BOTTOMLEFT],faces[BACK][BOTTOMRIGHT]);
	_coins[EIGHT]._im	= whichCornerItis(faces[DOWN][BOTTOMRIGHT],faces[RIGHT][BOTTOMRIGHT],faces[BACK][BOTTOMLEFT]);

	//orientation of coin
	for (int coin = 0 ; coin < 9 ; coin++)
		_coins[coin]._orientation = getPieceOrientation(coin,faces);

	//finding ridge 
	_ridges[A_RIDGE]._im = whichRidgeItis(faces[UP][BOTTOMMIDDLE], faces[FRONT][TOPMIDDLE]);
	_ridges[B_RIDGE]._im = whichRidgeItis(faces[UP][MIDDLELEFT],faces[LEFT][TOPMIDDLE]);
	_ridges[C_RIDGE]._im = whichRidgeItis(faces[UP][TOPMIDDLE], faces[BACK][TOPMIDDLE]);
	_ridges[D_RIDGE]._im = whichRidgeItis(faces[UP][MIDDLERIGHT], faces[RIGHT][TOPMIDDLE]);

	_ridges[E_RIDGE]._im = whichRidgeItis(faces[FRONT][MIDDLELEFT], faces[LEFT][MIDDLERIGHT]);
	_ridges[F_RIDGE]._im = whichRidgeItis(faces[LEFT][MIDDLELEFT], faces[BACK][MIDDLERIGHT]);
	_ridges[G_RIDGE]._im = whichRidgeItis(faces[BACK][MIDDLELEFT], faces[RIGHT][MIDDLERIGHT]);
	_ridges[H_RIDGE]._im = whichRidgeItis(faces[RIGHT][MIDDLELEFT], faces[FRONT][MIDDLERIGHT]);

	_ridges[I_RIDGE]._im = whichRidgeItis(faces[DOWN][TOPMIDDLE], faces[FRONT][BOTTOMMIDDLE]);
	_ridges[J_RIDGE]._im = whichRidgeItis(faces[DOWN][MIDDLELEFT], faces[LEFT][BOTTOMMIDDLE]);
	_ridges[K_RIDGE]._im = whichRidgeItis(faces[DOWN][BOTTOMMIDDLE], faces[BACK][BOTTOMMIDDLE]);
	_ridges[L_RIDGE]._im = whichRidgeItis(faces[DOWN][MIDDLERIGHT], faces[RIGHT][BOTTOMMIDDLE]);

	for (int ridge = 0; ridge < 12; ridge++)
		_ridges[ridge]._orientation = getRidgeOrientation(ridge, faces);
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
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			_intFace[i][j] = i;
		}
	}
	for (int i = 0; i < 8;i++)
		_coins[i]._type = CORNER;
	for (int i = 0; i < 12;i++)
		_ridges[i]._type = RIDGES;

	_ridges[A_RIDGE]._im = C_RIDGE;
	_ridges[A_RIDGE]._orientation = KO;

	_ridges[B_RIDGE]._im = H_RIDGE;
	_ridges[B_RIDGE]._orientation = KO;
	_ridges[C_RIDGE]._im = H_RIDGE;
	_ridges[C_RIDGE]._orientation = KO;
	_ridges[D_RIDGE]._im = H_RIDGE;
	_ridges[D_RIDGE]._orientation = KO;

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
//#include "rubiks.class.hpp"

// cycle A -> B -> C -> D -> A [A,B,C,D]
void Cube::cyclingRidge(const int cycle[4], bool changeOrientation)
{
	Piece r_tmp;
	
	cerr << "cycle "  << cycle <<endl;
	cerr << "cycle[0] =  "  << cycle[0] <<endl;
	cerr << "_ridges[0] =  "  << _ridges[0] <<endl;
	cerr << "cyclingRidge in b"  << endl;
	r_tmp = _ridges[cycle[0]];
	cerr << "cyclingRidge in for"  << endl;
	for (int pos = 0; pos < 3; pos++) // OLOL You know iterator right ?, nevermind
	{
	cerr << "cyclingRidge in for"  << endl;
		_ridges[cycle[pos]] = _ridges[cycle[pos + 1]];
		if (changeOrientation)
			_ridges[cycle[pos]]._orientation = !_ridges[cycle[pos]]._orientation;
	}
		_ridges[cycle[3]] = r_tmp;
		if (changeOrientation)
			_ridges[cycle[3]]._orientation = ! _ridges[cycle[3]]._orientation;
}

int		Cube::coinRot(int type, int coin)
{
	if (type == CCW)
	{
		if (_coins[coin]._orientation == CCW)
			_coins[coin]._orientation = OK;
		else if(_coins[coin]._orientation == CW)
			_coins[coin]._orientation = CCW;
		else if(_coins[coin]._orientation == OK)
			_coins[coin]._orientation = CW;
		else cerr << "err : wrong ccw rot \n" << endl;
	}
	else if (type == CW)
	{
		if (_coins[coin]._orientation == CCW )
			_coins[coin]._orientation = CW;
		else if(_coins[coin]._orientation == CW ) // OMG "C)" SO DISTRUBING ROLF
			_coins[coin]._orientation = OK;
		else if(_coins[coin]._orientation == OK )
			_coins[coin]._orientation = CCW;
		else cerr << "err : Wrong cw rot\n" << endl;
	}
	else cerr << "err : Wrong rot celection\n" << endl;
	if (type == CW) return CCW;
	else if (type == CCW) return CW;
	else return -1;
}

void Cube::cyclingCorner(const int cycle[4], int type)
{
	Piece r_tmp;
	r_tmp = _coins[cycle[0]];
	for (int pos = 0; pos < 3; pos++) // OLOL You know iterator right ?, nevermind
	{
		_coins[cycle[pos]] = _coins[cycle[pos + 1]];
		if (type == CCW || type == CW)
		{
			//cout << "type == " << type<< endl;
			//cout << "coin == " << _coins[cycle[pos]] << endl;
			type = coinRot(type, cycle[pos]);
		}
	}
		_coins[cycle[3]] = r_tmp;
		if (type == CCW || type == CW)
		coinRot(type, cycle[3]);
}

void Cube::up()
{
	int m[4] = {A_RIDGE,D_RIDGE,C_RIDGE,B_RIDGE};
	cyclingRidge(m, false);
/*	Ridge r_tmp;
	
	r_tmp = _ridges[D_RIDGE];
	for (RidgePosition pos = A_RIDGE; pos < D_RIDGE; pos++)
		_ridges[pos + 1] = _ridges[pos];
	_ridges[A_RIDGE] = r_tmp;*/
}

//const int Cube::_cup[]	=		{ONE, FOUR, THREE, TWO};
//const int Cube::_cdown[]	=	{FIVE, SIX, SEVEN, EIGHT};
//const int Cube::_cleft[]	=	{TWO, THREE,SEVEN, SIX};
//const int Cube::_cright[]	=	{ONE, FIVE, EIGHT, FOUR};
//const int Cube::_cback[]	=	{FOUR, EIGHT, SEVEN, THREE};
//const int Cube::_cfront[]	=	{ONE, TWO, SIX, FIVE};

void Cube::moveString(std::string str)
{
	std::string instruction;
	int instruction_size;
	while (str.size())
	{
		if (str[1] == '2' || str[1] == '\'')
			instruction_size = 2;
		else
			instruction_size = 1;
		instruction = str.substr(0, instruction_size);
	cerr << "caseCanMoveFirstLayer after substr"<< endl;
		str.erase(0,instruction_size);
	cerr << "caseCanMoveFirstLayer after erase"  << endl;
		if (instruction == "U") move(IUP);
		else if (instruction == "D") move(IDOWN);
		else if (instruction == "L") move(ILEFT);
		else if (instruction == "R") move(IRIGHT);
		else if (instruction == "B") move(IBACK);
		else if (instruction == "F") move(IFRONT);

		else if (instruction == "U'") for(int i = 0;i<3;i++)move(IUP);
		else if (instruction == "D'") for(int i = 0;i<3;i++)move(IDOWN);
		else if (instruction == "L'") for(int i = 0;i<3;i++)move(ILEFT);
		else if (instruction == "R'") for(int i = 0;i<3;i++)move(IRIGHT);
		else if (instruction == "B'") for(int i = 0;i<3;i++)move(IBACK);
		else if (instruction == "F'") for(int i = 0;i<3;i++)move(IFRONT);

		else if (instruction == "U2") for(int i = 0;i<2;i++){cout << "hey" << endl;move(IUP);}
		else if (instruction == "D2") for(int i = 0;i<2;i++)move(IDOWN);
		else if (instruction == "L2") for(int i = 0;i<2;i++)move(ILEFT);
		else if (instruction == "R2") for(int i = 0;i<2;i++)move(IRIGHT);
		else if (instruction == "B2") for(int i = 0;i<2;i++)move(IBACK);
		else if (instruction == "F2") for(int i = 0;i<2;i++)move(IFRONT);
/*
		switch()
		{
			case "U" : move(IUP);break;
			case "D" : move(IDOWN);break;
			case "L" : move(ILEFT);break;
			case "R" : move(IRIGHT);break;
			case "B" : move(IBACK);break;
			case "F" : move(IFRONT);break;

			case "U'" : for(int i = 0;i<3;i++)move(IUP);break;
			case "D'" : for(int i = 0;i<3;i++)move(IDOWN);break;
			case "L'" : for(int i = 0;i<3;i++)move(ILEFT);break;
			case "R'" : for(int i = 0;i<3;i++)move(IRIGHT);break;
			case "B'" : for(int i = 0;i<3;i++)move(IBACK);break;
			case "F'" : for(int i = 0;i<3;i++)move(IFRONT);break;

			case "U2" : for(int i = 0;i<2;i++)move(IUP);break;
			case "D2" : for(int i = 0;i<2;i++)move(IDOWN);break;
			case "L2" : for(int i = 0;i<2;i++)move(ILEFT);break;
			case "R2" : for(int i = 0;i<2;i++)move(IRIGHT);break;
			case "B2" : for(int i = 0;i<2;i++)move(IBACK);break;
			case "F2" : for(int i = 0;i<2;i++)move(IFRONT);break;
		}*/
	}
}

void Cube::move(Instruction instruction)
{
	//std::vector<RidgePosition> cyclesRidge[12];
	//cyclesRidge[UP] = [ONE,TWO,THREE,FOUR];

	switch (instruction)
	{
		case IUP :	
					cerr << "HEyYY" << endl;
					cerr << "Cube : " << Cube::_tup<< endl;
					cyclingRidge(Cube::_tup, false);
					cout << "ridge ok" <<endl;
					cyclingCorner(Cube::_cup, -1);
					cout << "corner ok" <<endl;
					cout << "UP CALL" <<endl;
					break;
		case IDOWN : cyclingRidge(Cube::_tdown, false);
					cyclingCorner(Cube::_cdown, -1);
					cout << "DOWN CALL" <<endl;
					break;
		case ILEFT : cyclingRidge(Cube::_tleft, true);
					cyclingCorner(Cube::_cleft, CW);
					cout << "LEFT CALL" <<endl;
					break;
		case IRIGHT: cyclingRidge(Cube::_tright, false);
					cyclingCorner(Cube::_cright, CCW);
					cout << "RIGHT CALL" <<endl;
					break;
		case IBACK:  cyclingRidge(Cube::_tback, false);
					cyclingCorner(Cube::_cback, CCW); 
					cout << "BACK CALL" <<endl;
					break;
		case IFRONT: cyclingRidge(Cube::_tfront, false);
					cyclingCorner(Cube::_cfront, CW);
					cout << "FRONT CALL" <<endl;
					break;
	}
}
