/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.algo.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 08:53:07 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/06 10:48:06 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * To finish the cube we will need that each _ridges[index]._im and _coins[index]._im
 * to be equal to index (And also _x[]._orientation to OK)
 *
 * RESUME : 
 * 		_ridges[index]._im == index && _ridges[index]._orientation == OK 
 * 		 -> _ridges[index] placed correctly
 * 		_coins[index]._im == index && _coins[index]._orientation == OK 
 * 		 -> _coins[index] placed correctly
 *
 * */

/*
 * What we need :
 * detect ridge A to D
 * will search in first layer at first (upface)
 * 		if there is [A,D] Ridge Check orientation, if orientation ok THENNNNNN ???????????????????????????????????????????
 * will search in middle layer at first (uface)
 * will search in middle layer at first (uface)
 */

bool Cube::whiteCrossIsDone()
{
	for (int i = A_RIDGE; i < A_RIDGE + 4; i++)
	{
		if (i != _ridges[i]._im || _ridges[i]._orientation != OK)
			return false;
	}
	return true;
}

int convertRidgeToRotation(int ridge)
{
	switch(ridge)
	{
		case A_RIDGE:	return IFRONT;
		case B_RIDGE:	return ILEFT;
		case C_RIDGE:	return IBACK;
		case D_RIDGE:	return IRIGHT;
		case I_RIDGE:	return IFRONT;
		case J_RIDGE:	return ILEFT;
		case K_RIDGE:	return IBACK;
		case L_RIDGE:	return IRIGHT;
		default :		return -1;
	}
}

int Cube::pieceOfCrossPlaced()
{
	int ret = 0;
	for (int r = A_RIDGE; r <= D_RIDGE; r++)
	{
		if (_ridges[r]._im == r && _ridges[r]._orientation == OK)
			ret++;
	}
	return ret;
}

void Cube::whiteCrossPlacingFromTopOK(int ridge) // place a ridge that is on UP face, orientation OK`
{
	int newPlaceOfRidge;
	if (ridge >= A_RIDGE && ridge <= D_RIDGE)
	{
		int instruction = convertRidgeToRotation(ridge);
		move(instruction);
		move(instruction);
		newPlaceOfRidge = ridge + 8;
		while (_ridges[newPlaceOfRidge]._im != newPlaceOfRidge - 8) // notre ridge est maintenant a newplace of irdge, quand 
		{
			move(IDOWN);
			newPlaceOfRidge = (newPlaceOfRidge + 3) % 4 + 8; // bin quoi ? A VERIIIFFIIIERRRRRRRRR
		}
		instruction = convertRidgeToRotation(newPlaceOfRidge);
		move(instruction);
		move(instruction);
	}
}

void Cube::whiteCrossPlacingFromTopKO(int ridge) // place a ridge that is on UP face, orientation OK`
{
	int instruction = convertRidgeToRotation(ridge);
	move(instruction)
}

void Cube::doWhiteCross() // if forest inc WHHAAAA galere le debut :(:(:(:(:( J"AI LA FLLEEEMMM
{
	int nbPlaced = pieceOfCrossPlaced();

	if (nbPlaced == 4) return; //DONE
	for (int r = A_RIDGE; r <= D_RIDGE; r++) // first layer checl
	{
		if (_ridges[r]._im >= A_RIDGE && _ridges[r] <= D_RIDGE) // cas : une des arete blanche et on top, et bien oriente
		{
			if (_ridges[r]._orientation == OK) //bien oriente, need just upmove
			{
				if (!nbPlaced)
				{
					while (_ridges[r]._im != r) // tant que ridges[X]._im n'est pas X-> UP
						move(IUP);
					doWhiteCross(); //placed something,recall the function
				}
				else {whiteCrossPlacingFromTopOK(r);doWhiteCross();} //
			}
			else
			{
					whiteCrossPlacingFromTopKO(r);
			}
		}
	}
} 
