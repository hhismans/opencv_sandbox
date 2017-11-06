/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.algo.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:47:39 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/06 18:07:13 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube.class.hpp"
#include "../includes/enum.hpp"

static bool isUpRidge(int ridge){return (ridge >= A_RIDGE && ridge <= D_RIDGE);}

//int faceFromPiece(int piece)
std::string getDecalInstruction(int src, int dst, string instruction)
{
	int delta = dst - src;
	if (instruction == "U")
	{
		if (delta == 0) return "";
		else if (delta == 1 || delta == -3) return "U";
		else if (delta == 2 || delta == -2) return "U2";
		else if (delta == -1 || delta == 3) return "U'";
	}
	else if ( instruction == "D")
	{
		if (delta == 0) return "";
		else if (delta == 1 || delta == -3) return "D'";
		else if (delta == 2 || delta == -2) return "D2";
		else if (delta == -1 || delta == 3) return "D";
	}
}

Instruction faceFromPiece(int piece)
{
	switch(piece)
	{
		case A_RIDGE : return IFRONT;
		case B_RIDGE : return ILEFT;
		case C_RIDGE : return IBACK;
		case D_RIDGE : return IRIGHT;
	}
	return ERROR;
}


void Cube::moveUpWellOriented(int init, int dest){
/*	int delta = dest - init;
	if (delta == 0) return;
	else if (delta == 1 || delta == -3) move(IRUP);
	else if (delta == 2 || delta == -2) move(IRUP2);
	else if (delta == 3 || delta = -1) move(IUP);*/
}

void Cube::moveUpBadOriented(int init, int dest){
/*	int delta = dest - init;
	int decalInstruction = faceFromPiece(init);
	move(decalInstruction);
	if (delta == 0) move(IRUP); move(decalInstruction + REVERT_MOVE); move(IUP);return;
	else if (delta == 1 || delta == -3) move(decalInstruction);
	else if (delta == 2 || delta == -2) move(decalInstruction);
	else if (delta == 3 || delta = -1) move(IUP);*/
}

bool Cube::isAllOk(int piece)
{
	return (_ridges[piece]._im == piece && _ridges[piece]._orientation == OK);
}

int Cube::nbOkRidge()
{
	int ret = 0;
	for (int i = A_RIDGE; i <= D_RIDGE; i++)
	{
		cout << "i = " <<i << " ridge[i] == " << _ridges[C_RIDGE]._im<<endl;
		if ( isAllOk(i) ) {ret++;cerr<<i<<endl;}
	}
	cerr << "ret = "<<ret<<endl;
	return ret;
}

string Cube::caseCanMoveFirstLayer()
{
	string instruction = "";
	for (int i = A_RIDGE; i <= D_RIDGE; i++)
	{
		if (isUpRidge(_ridges[i]._im) && _ridges[i]._orientation == OK)
		{
			instruction = getDecalInstruction(i, _ridges[i]._im,  "U");
		}
	}
	cerr << "first layer isntruction ; " << instruction << endl;
	moveString(instruction);
	return instruction;
}

std::string Cube::stringFromInstruction(Instruction inst)
{
	switch (inst)
	{
		case IUP :	return "U";
		case IDOWN : return "D";
		case ILEFT : return "L";
		case IRIGHT: return "R";
		case IBACK: return "B";
		case IFRONT:return "F";
	}
}


string Cube::moveUpWithBuffer(int src, int dest, int orientation){ // exempel A_RIDGE on UP KO || OK
	std::string instruction = "";
	int delta = dest - src;

	int src_decal;
	if (orientation == OK) // mais oui cest clair
	{//example
		cerr << "in moveupwithbuffer : OK src = "<<src << " dst = " << dest<<  endl;
		instruction += stringFromInstruction(faceFromPiece(src));
		instruction += "2"; // for now, (FBLR)2
		instruction += getDecalInstruction(src, dest,"D");
		instruction += stringFromInstruction(faceFromPiece(dest)); //R2
		instruction += "2";
	}
	else if (orientation == KO)
	{ // example, A_RIDGE is C_RIDGE KO 
		cerr << "in moveupwithbuffer : KO src = "<<src << " dst = " << dest<<  endl;
		instruction += stringFromInstruction(faceFromPiece(src)); // F
		if (dest == ((src+3) % 4)) return (instruction + stringFromInstruction(faceFromPiece((src+3)%4))); // mais oui c'est clair
		instruction += stringFromInstruction(faceFromPiece((src + 3) % 4)); // R'
		instruction += "'";
		src_decal = (src + 3) % 4;
		instruction += getDecalInstruction (src_decal, dest, "D"); //D
		instruction += stringFromInstruction(faceFromPiece(dest)); //R2
		instruction += "2";
		if (isAllOk(src_decal)) instruction += stringFromInstruction(faceFromPiece((src + 3) % 4)); // replace buffer decal if is correct
	} // end
	cerr << "instruction for this case"<< instruction << endl;
	moveString(instruction);
	return instruction;
}

string middleToDown(int piece, int orientation, int & src_decal)
{
		case E_RIDGE : orientation == OK ? return "L" : return "F'";
		case F_RIDGE : orientation == OK ? return "L'" : return "B";
		case G_RIDGE : orientation == OK ? return "R" : return "B'";
		case H_RIDGE : orientation == OK ? return "R'" : return "F";
}

string downToMiddle(int piece, int orientation)
{
		case E_RIDGE : orientation == OK ? return "L'" : return "F";
		case F_RIDGE : orientation == OK ? return "L" : return "B'";
		case G_RIDGE : orientation == OK ? return "R'" : return "B";
		case H_RIDGE : orientation == OK ? return "R" : return "F'";
}

int ridgeFromString(string inst)
{
	switch (inst[0])
	{
		case 'L': return B_RIDGE;
		case 'R': return D_RIDGE;
		case 'B': return C_RIDGE;
		case 'F': return A_RIDGE;
	}
}
string moveMiddleWithBuffer(i, _ridges[i]._im, _ridges[i]._orientation)
{
	std::string instruction = "";
	int delta = dest - src;
	int src_decal;

	if (orientation == OK)
	{//example
		//cerr << "in moveupwithbuffer : OK src = "<<src << " dst = " << dest<<  endl;
		instruction += middleToDown(src, orientation, src_decal);
		src_decal = ridgeFromString(instruction);
		instruction += getDecalInstruction(src, dest,"D");
		if (isAllOk(src_decal)) instruction += stringFromInstruction(faceFromPiece((src + 3) % 4)); // replace buffer decal if is correct
		instruction += stringFromInstruction(faceFromPiece(dest)); //R2
		instruction += "2";
		if (isAllOk(src_decal)) instruction += stringFromInstruction(faceFromPiece((src + 3) % 4)); // replace buffer decal if is correct
	} // end
}

void Cube::doWhiteCross(){
	int placedRidgeNb = nbOkRidge();
	cout <<"efterit"<<endl;
	string instruction ="";
	if (placedRidgeNb == 0) instruction = caseCanMoveFirstLayer(); // simple
	if (placedRidgeNb == 4) return; // simple
	for (int i = A_RIDGE; i <= D_RIDGE ; i++) // HERE if something was on top layer, it will alredy right placed, but not if there's 2 on top ladder
	{
		if (isUpRidge(_ridges[i]._im))
		{
			instruction += moveUpWithBuffer(i, _ridges[i]._im, _ridges[i]._orientation);
			doWhiteCross();
		}
	}
	for (int i = E_RIDGE; i < H_RIDGE; i++)
	{
		if (isUpRidge(_ridges[i]._im))
			instruction += moveMiddleWithBuffer(i, _ridges[i]._im, _ridges[i]._orientation);
	}
	cout << instruction << endl;
}
