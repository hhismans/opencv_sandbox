#include "../includes/Cube.class.cpp"
#include "../includes/enum.class.cpp"

static bool isUpRidge(int ridge){return (ridge >= A_RIDGE && ridge <= D_RIDGE);}


int faceFromPiece(int piece)
{
	switch(piece)
	{
		case A_RIDGE : return IFRONT;
		case B_RIDGE : return ILEFT;
		case C_RIDGE : return IBACK;
		case D_RIDGE : return IRIGHT;
	}
	return -1;
}

void Cube::moveUpWellOriented(int init, int dest){
	int delta = dest - init;
	if (delta == 0) return;
	else if (delta == 1 || delta == -3) move(IRUP);
	else if (delta == 2 || delta == -2) move(IRUP2);
	else if (delta == 3 || delta = -1) move(IUP);
}

void Cube::moveUpBadOriented(int init, int dest){
	int delta = dest - init;
	int decalInstruction = faceFromPiece(init);
	move(decalInstruction);
	if (delta == 0) move(IRUP); move(decalInstruction + REVERT_MOVE); move(IUP);return;
	else if (delta == 1 || delta == -3) move(decalInstruction);
	else if (delta == 2 || delta == -2) move(decalInstruction);
	else if (delta == 3 || delta = -1) move(IUP);
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
		if (isAllOk(i)) ret++;
	}
	return ret;
}

void Cube::doWhiteCross(){
	int placedRidgeNb = nbOkRidge();

	for (int i = A_RIDGE; i <= D_RIDGE; i++)
	{
		if (placedRidgeNb == 0 && isUpRidge(_ridges[i]))
		{
			if (_ridges[i]._orientation == OK)
				moveUpWellOriented(i, _ridges[i]);
			else (_ridges)
				moveUpBadOriented(i, _ridges[i]);
			doWhiteCross();
		}
	}
}
