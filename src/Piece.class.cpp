/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 05:23:03 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 05:25:16 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Piece.class.hpp"

Piece::Piece( void )
{
	_type = 		DEFAULT;
	_position =		DEFAULT;
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
}
