/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencvHandler.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:38:06 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 02:56:13 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OpenCvHandler.class.hpp"

//         ###
//         ###
//         ###
//
// ### ### ### ###
// ### ### ### ### // Cube display pattern
// ### ### ### ###  // 12 square, 3 big spacing, 8 small spacing
// 
//         ###      // ll need width / ()
//         ###
//         ###
// 
//
//void OpenCvHandler::draw_cube(Mat& img, Cube cube) //, Cube face color Data, will see
//{
//	Point start(10, 10);
//	int total_width = 150;
//	int face_spacing = 10;
//	int square_spacing = 2;
//	int square_width = (total_width - 3*face_spacing - 3*square_spacing) / 12;
//	int void_line_decal = 6*square_width + 4*square_spacing + 2* face_spacing;
//	int decal_square = square_spacing + square_width;
//	int decal_face = square_spacing * 2 + square_width * 3 + face_spacing;
//	Scalar color(255,0,0);
//
//
//	//first line
//	for (int i = 0; i < 3; i++) // 3
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			Point p1 =  Point(start.x + void_line_decal + i * decal_square, start.y + j * decal_square);
//			Point p2 = Point(p1.x + square_width, p1.y + square_width);
//			cv::rectangle(img, p1, p2, cube._face[UP][3*j + i], -1,8,0);
//		}
//	}
//	// second line 
//	for (int face = 0; face < 4; face++)
//	{
//		for (int i = 0; i < 3; i++) // 3
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				Point p1 =  Point(start.x + face * decal_face + i * decal_square, start.y + decal_face + j * decal_square);
//				Point p2 = Point(p1.x + square_width, p1.y + square_width);
//				cv::rectangle(img, p1, p2, cube._face[1 + face][j+3 + i], -1,8,0);
//			}
//		}
//	}
//	//last
//	for (int i = 0; i < 3; i++) // 3
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			Point p1 =  Point(start.x + void_line_decal + i * decal_square, start.y + (2*decal_face) + j * decal_square);
//			Point p2 = Point(p1.x + square_width, p1.y + square_width);
//			cv::rectangle(img, p1, p2, cube._face[DOWN][j+3 + i], -1,8,0);
//		}
//	}
//}

std::vector<bool> OpenCvHandler::getColorPresenceMap(Mat &img)
{
	std::vector<bool> ret(20);

	int used = 300;
	int size = 30;
	int limit = (size * size) * 50 / 100; // 60% rempli =couleur est la
	int space_between = (used - 3 * size ) / 2;

	int startW = (FRAME_WIDTH - used) / 2;
	int startH = (FRAME_HEIGHT - used) / 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Mat square(img, Rect(startW + i*(size + space_between),startH + j*(size + space_between), size,size));
			ret[i*3 + j] =countNonZero(square) > limit;
		}
	}
	return ret;
}

void OpenCvHandler::morphOps(Mat &src, Mat &dst)
{
	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle
	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
    //dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

	erode(src,dst,erodeElement);
	erode(src,dst,erodeElement);


	dilate(src,dst,dilateElement);
	dilate(src,dst,dilateElement);
}

void OpenCvHandler::draw_valid_square(Mat& img, const Scalar& color, vector<bool> boolMat) // user use this too see where to put his cube
{
	int used = 300;
	int size = 30;
	int space_between = (used - 3 * size ) / 2;

	int startW = (FRAME_WIDTH - used) / 2;
	int startH = (FRAME_HEIGHT - used) / 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (boolMat[i * 3 + j])
			cv::rectangle(img, Point(startW + i*(size + space_between), startH + j*(size + space_between)),
							Point(startW + size + i*(size + space_between), startH + size + j*(size + space_between)), color, -1,8,0);
		}
	}
}

void OpenCvHandler::draw_square(Mat& img, const Scalar& color) // user use this too see where to put his cube
{
	int used = 300;
	int size = 30;
	int space_between = (used - 3 * size ) / 2;

	int startW = (FRAME_WIDTH - used) / 2;
	int startH = (FRAME_HEIGHT - used) / 2;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cv::rectangle(img, Point(startW + i*(size + space_between), startH + j*(size + space_between)),
							Point(startW + size + i*(size + space_between), startH + size + j*(size + space_between)), color, 1,8,0);
		}
	}
}

void OpenCvHandler::run(void)
{
	while (1)
	{
		// capture and convert
		_capture.read(_cameraFeed); // capture matrix from camera feed
		cvtColor(_cameraFeed,_HSVMat,COLOR_BGR2HSV); // convert to HSV mat

		//range each Color
		for (int i = 0; i < 6; i++)
		{
			inRange(_HSVMat, Scalar(_HSVConfig[i][H_MIN],_HSVConfig[i][S_MIN],_HSVConfig[i][V_MIN]),
				Scalar(_HSVConfig[i][H_MAX],_HSVConfig[i][S_MAX],_HSVConfig[i][V_MAX]),_faceMat[i]);
			morphOps(_faceMat[i], _filtredFaceMat[i]);
			_boolPresenceMats[i] = getColorPresenceMap(_filtredFaceMat[i]);
		}
		draw_square(_cameraFeed, Scalar(255,0,0));
		for (int i = 0; i < 6; i++)
		{
			draw_valid_square(_cameraFeed, _colorsScalar[i], _boolPresenceMats[i]);
		}
		cv::flip(_cameraFeed, _mirorCameraFeed,1);
		//draw_cube(_mirorCameraFeed, cube); //, Cube face color Data, will see
		imshow(MAIN_WINDOW_NAME, _mirorCameraFeed);
		waitKey(30);
	}
}

template <typename T>
void alloc_vector(std::vector<T> &vect, int nb)
{
	for (int i = 0; i < nb; i++)
	{
		vect.push_back(T());
	}
}

OpenCvHandler::OpenCvHandler( void )
{
	//setting
	alloc_vector(_faceMat, 6);
	//_faceMat.reserve(6);
	alloc_vector(_HSVConfig, 6);
	//_HSVConfig.reserve(6);
	std::cout << "OpenCvHandler succefully instanciate 1" << std::endl;
	for (int i = 0;i < 6; i++)
		alloc_vector(_HSVConfig[i],6);
	alloc_vector(_colorsScalar, 6);

	std::cout << "OpenCvHandler succefully instanciate 1" << std::endl;
	//_filtredFaceMat.reserve(6);
	//_bundlePresenceMat.reserve(9);
	//_boolPresenceMats.reserve(6);
	
	alloc_vector(_filtredFaceMat,6);
	alloc_vector(_bundlePresenceMat,9);
	alloc_vector(_boolPresenceMats,6);
	for (int i = 0;i < 6; i++)
	{
		alloc_vector(_boolPresenceMats[i],9);
		}

	std::cout << "OpenCvHandler succefully instanciate 2" << std::endl;
	_colorsScalar[WHITE] = Scalar(255,255,255);
	_colorsScalar[YELLOW] = Scalar(0,255,255);
	_colorsScalar[GREEN] = Scalar(0,255,0);
	_colorsScalar[BLUE] = Scalar(255,0,0);
	_colorsScalar[RED] = Scalar(0,0,255);
	_colorsScalar[ORANGE] = Scalar(0,125,255);

	// try this
	_HSVConfig[RED][H_MIN] = 128;
	_HSVConfig[RED][H_MAX] = 213;
	_HSVConfig[RED][V_MIN] = 0;
	_HSVConfig[RED][V_MAX] = 256;
	_HSVConfig[RED][S_MIN] = 198;
	_HSVConfig[RED][S_MAX] = 256;
	
	_HSVConfig[WHITE][H_MIN] = 18;
	_HSVConfig[WHITE][H_MAX] = 83;
	_HSVConfig[WHITE][V_MIN] = 148;
	_HSVConfig[WHITE][V_MAX] = 210;
	_HSVConfig[WHITE][S_MIN] = 0;
	_HSVConfig[WHITE][S_MAX] = 26;
	
	_HSVConfig[YELLOW][H_MIN] = 0;
	_HSVConfig[YELLOW][H_MAX] = 41;
	_HSVConfig[YELLOW][V_MIN] = 217;
	_HSVConfig[YELLOW][V_MAX] = 256;
	_HSVConfig[YELLOW][S_MIN] = 54;
	_HSVConfig[YELLOW][S_MAX] = 159;

	_HSVConfig[ORANGE][H_MIN] = 0;
	_HSVConfig[ORANGE][H_MAX] = 41;
	_HSVConfig[ORANGE][V_MIN] = 217;
	_HSVConfig[ORANGE][V_MAX] = 256;
	_HSVConfig[ORANGE][S_MIN] = 54;
	_HSVConfig[ORANGE][S_MAX] = 159;

	_HSVConfig[BLUE][H_MIN] = 0;
	_HSVConfig[BLUE][H_MAX] = 41;
	_HSVConfig[BLUE][V_MIN] = 217;
	_HSVConfig[BLUE][V_MAX] = 256;
	_HSVConfig[BLUE][S_MIN] = 54;
	_HSVConfig[BLUE][S_MAX] = 159;

	_HSVConfig[GREEN][H_MIN] = 0;
	_HSVConfig[GREEN][H_MAX] = 41;
	_HSVConfig[GREEN][V_MIN] = 217;
	_HSVConfig[GREEN][V_MAX] = 256;
	_HSVConfig[GREEN][S_MIN] = 54;
	_HSVConfig[GREEN][S_MAX] = 159;

	//init
	_capture.open(0);
	_capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	_capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);

	std::cout << "OpenCvHandler succefully instanciate" << std::endl;
}

OpenCvHandler::OpenCvHandler( OpenCvHandler const & src )
{
}

OpenCvHandler::~OpenCvHandler( void )
{
}

/*OpenCvHandler &OpenCvHandler::operator=( OpenCvHandler const & rhs )
{
}*/
