/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:40 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 04:53:54 by hhismans         ###   ########.fr       */
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
