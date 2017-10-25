/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:59 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 02:29:56 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

#include <iostream>
#include "../includes/OpenCvHandler.class.hpp"
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;
class Cube
{
	public:
		Scalar _face[6][9];
		Cube( void );
		Cube( Cube const & src );
		~Cube( void );

		Cube &	operator=( Cube const & rhs);
	private:
};
#endif
