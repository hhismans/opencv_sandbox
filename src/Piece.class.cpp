/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 05:23:03 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/03 08:15:05 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Piece.class.hpp"
#include "../includes/Cube.class.hpp"
#include "../includes/enum.hpp"

Piece::Piece( void )
{
	_type = 		DEFAULT;
	_im =			DEFAULT;
	_orientation =	DEFAULT;
}

Piece::Piece( Piece const & src )
{
}

Piece::~Piece( void )
{
}

Piece &Piece::operator=( Piece const & rhs )
{
	_type = rhs._type;
	_im = rhs._im;
	_orientation = rhs._orientation;
}

std::ostream& operator<<(std::ostream& os, const Piece& rhs)
{
	if (rhs._type == CORNER)
	{
		switch (rhs._im)
		{
			case ONE: 
				os << "RED WHITE BLUE";
				break;
			case TWO: 
				os << "RED WHITE GREEN";
				break;
			case THREE: 
				os << "ORANGE GREEN WHITE";
				break;
			case FOUR: 
				os << "ORANGE WHITE BLUE";
				break;
			case FIVE: 
				os << "RED BLUE YELLOW";
				break;
			case SIX: 
				os << "RED GREEN YELLOW";
				break;
			case SEVEN: 
				os << "GREEN ORANGE YELLOW";
				break;
			case EIGHT: 
				os << "BLUE ORANGE YELLOW";
				break;
		}
	}
	else if (rhs._type == RIDGES)
	{
		switch (rhs._im)
		{
			case A_RIDGE: 
				os << "RED AND WHITE";
				break;
			case B_RIDGE: 
				os << "GREEN AND WHITE";
				break;
			case C_RIDGE: 
				os << "ORANGE AND WHITE";
				break;
			case D_RIDGE: 
				os << "BLUE AND WHITE";
				break;
			case E_RIDGE: 
				os << "RED AND GREEN";
				break;
			case F_RIDGE: 
				os << "GREEN AND ORANGE";
				break;
			case G_RIDGE: 
				os << "BLUE AND ORANGE";
				break;
			case H_RIDGE: 
				os << "RED AND BLUE";
				break;
			case I_RIDGE: 
				os << "RED AND YELLOW";
				break;
			case J_RIDGE: 
				os << "YELLOW AND GREEN";
				break;
			case K_RIDGE: 
				os << "YELLOW AND ORANGEj";
				break;
			case L_RIDGE: 
				os << "BLUE AND YELLOW";
				break;

		}
	}
}
