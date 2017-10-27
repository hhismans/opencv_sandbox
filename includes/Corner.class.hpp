/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Corner.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 05:09:31 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 05:22:20 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORNER_CLASS_HPP
# define CORNER_CLASS_HPP

# include "../includes/enum.hpp"


class 
{
	public:
		Corner( void );
		Corner( Corner const & src );
		~Corner( void );

		Corner &	operator=( Corner const & rhs);
	private:
		EPieceTypep		_type;
		int				_position;
		int				_orientation;
};
#endif
