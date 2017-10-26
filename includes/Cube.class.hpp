/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:59 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 04:53:28 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CLASS_HPP
# define CUBE_CLASS_HPP

#include <iostream>
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
		void changeFace(int faceId, std::vector<int> face);
		Cube &	operator=( Cube const & rhs);
	private:
};
#endif
