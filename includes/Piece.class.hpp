/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 05:21:43 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 07:02:52 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_CLASS_HPP
# define PIECE_CLASS_HPP

#include "enum.hpp"

enum  EPieceType
{
	CORNER,
	RIDGES,
	DEFAULT
}

class Piece
{
	public:
		Piece( void );
		Piece( Piece const & src );
		~Piece( void );

		Piece &	operator=( Piece const & rhs);
	private:
		int				_type;
		int				_im; //I'm
		int				_orientation;
};
#endif
