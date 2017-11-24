/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:59 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/24 15:50:56 by hhismans         ###   ########.fr       */
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
# include "../includes/enum.hpp"
# include "../includes/Piece.class.hpp"

using namespace cv; // SHAME
using namespace std;

// first layer formula
// pour passer au prochain ridge : (i + 1) % 4
// pour passer au precedent ridge : (i + 3) % 4


class Cube
{
	public:
		Scalar	_face[6][9];
		int		_intFace[6][9];

		Cube( void );
		Cube( Cube const & src );
		~Cube( void );
		Cube &	operator=( Cube const & rhs);


		void init();
		//detection
		void changeFace(int faceId, std::vector<int> face);
		void initCubeWithFace(int faces[6][9]);
		int	whichCornerItis(int color1, int color2, int color3);
		int	whichRidgeItis(int color1, int color2);
		int getPieceOrientation(int position, int faces[6][9]); // good coin orientation, UD color on UD face

		void setIntFace();

		//movement
		int		coinRot(int type, int coin); //Rotation of type CCW CW on _coins No coin (cf enum ONE TWO..)
		void cyclingRidge(const int cycle[4], bool changeOrientation);
		void cyclingCorner(const int cycle[4], int type);
		void			move(Instruction instruction);
		void moveString(std::string str);
		void up();

		//algo
		void doWhiteCross();
		string moveMiddleWithBuffer(int src, int dest, int orientation);
			void moveUpWellOriented(int init, int dest);
		void moveUpBadOriented(int init, int dest);
			std::string stringFromInstruction(Instruction inst);
			string moveUpWithBuffer(int src, int dest, int orientation); // exempel A_RIDGE on UP KO || OK
			bool isAllOk(int piece);
			int nbOkRidge();
			string caseCanMoveFirstLayer();
		
		Piece			_coins[8];
		Piece			_ridges[12];
		std::string		solution;
		/*
		 * Cube decrit comme 8 coin et 12 arete.
		 * Chaque arete
		 * */
	// rot array use to move _t ridge _c coin (cycle done by ridge)
	static const int _tup[4]	;
	static const int _tdown[4]	;
	static const int _tleft[4]	;
	static const int _tright[4]	;
	static const int _tback[4]	;
	static const int _tfront[4]	;

	static const int _cup[4]	;
	static const int _cdown[4]	;
	static const int _cleft[4]	;
	static const int _cright[4]	;
	static const int _cback[4]	;
	static const int _cfront[4]	;
};

ostream& operator<<(ostream& os, const Cube& Cube);
#endif
