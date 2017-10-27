/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:53:59 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/27 05:27:50 by hhismans         ###   ########.fr       */
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

using namespace cv; // SHAME
using namespace std;

class Cube
{
	public:
		Scalar _face[6][9];
		Cube( void );
		Cube( Cube const & src );
		~Cube( void );
		Cube &	operator=( Cube const & rhs);

		//detection
		void changeFace(int faceId, std::vector<int> face);
		void initCubeWithFace(std::vector<int> faces);

		//algo
		static void			move(Instruction instruction);
	private:
		/*
		 * Cube decrit comme 8 coin et 12 arete.
		 * Chaque arete 
		 * */
//		Piece	_corners[8];
//		Piece	_ridges[12];
};

#endif
