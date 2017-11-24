/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piece.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 05:21:43 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/24 15:26:25 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_CLASS_HPP
# define PIECE_CLASS_HPP

# include <iostream>

enum EPieceType
{
	CORNER,
	RIDGES
};

class Piece
{
	public:
		Piece( void );
		Piece( Piece const & src );
		~Piece( void );

		Piece &	operator=( Piece const & rhs);

		//brah
		int				_type;
		int				_im; //I'm
		int				_orientation;
	private:
};

std::ostream& operator<<(std::ostream& os, const Piece& rhs);
#endif
