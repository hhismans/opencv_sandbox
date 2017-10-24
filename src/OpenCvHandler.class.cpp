/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencvHandler.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:38:06 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 01:51:07 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenCvHandler.class.hpp"

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
void OpenCvHandler::draw_cube(Mat& img, Cube cube) //, Cube face color Data, will see
{
	Point start(10, 10);
	int total_width = 150;
	int face_spacing = 10;
	int square_spacing = 2;
	int square_width = (total_width - 3*face_spacing - 3*square_spacing) / 12;
	int void_line_decal = 6*square_width + 4*square_spacing + 2* face_spacing;
	int decal_square = square_spacing + square_width;
	int decal_face = square_spacing * 2 + square_width * 3 + face_spacing;
	Scalar color(255,0,0);


	//first line
	for (int i = 0; i < 3; i++) // 3
	{
		for (int j = 0; j < 3; j++)
		{
			Point p1 =  Point(start.x + void_line_decal + i * decal_square, start.y + j * decal_square);
			Point p2 = Point(p1.x + square_width, p1.y + square_width);
			cv::rectangle(img, p1, p2, cube._face[UP][3*j + i], -1,8,0);
		}
	}
	// second line 
	for (int face = 0; face < 4; face++)
	{
		for (int i = 0; i < 3; i++) // 3
		{
			for (int j = 0; j < 3; j++)
			{
				Point p1 =  Point(start.x + face * decal_face + i * decal_square, start.y + decal_face + j * decal_square);
				Point p2 = Point(p1.x + square_width, p1.y + square_width);
				cv::rectangle(img, p1, p2, cube._face[1 + face][j+3 + i], -1,8,0);
			}
		}
	}
	//last
	for (int i = 0; i < 3; i++) // 3
	{
		for (int j = 0; j < 3; j++)
		{
			Point p1 =  Point(start.x + void_line_decal + i * decal_square, start.y + (2*decal_face) + j * decal_square);
			Point p2 = Point(p1.x + square_width, p1.y + square_width);
			cv::rectangle(img, p1, p2, cube._face[DOWN][j+3 + i], -1,8,0);
		}
	}
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
	VideoCapture capture;
	while (1)
	{
		// capture and convert
		capture.read(_cameraFeed); // capture matrix from camera feed
		cvtColor(_cameraFeed,_HSVMAT,COLOR_BGR2HSV); // convert to HSV mat

		//range each Color
		for (int i = 0; i < 6; i++)
		{
			inRange(_HSVMAT, Scalar(_HSVConfig[i][H_MIN],_HSVConfig[i][S_MIN],_HSVConfig[i][V_MIN]),
				Scalar(_HSVConfig[i][H_MAX],_HSVConfig[i][S_MAX],_HSVConfig[i][V_MAX]),_faceMat[i]);
			morphOps(_faceMat[i], _filtredFaceMat[i]);
			_colorPresenceMatrix = getColorPresenceMap(_filtredFaceMat[i]);
		}
		draw_square(cameraFeed, Scalar(255,0,0));
		for (int i = 0; i < 6; i++)
		{
			draw_valid_square(_cameraFeed, _colorScalar[i], _colorPresenceMatrix[i]);
		}
		cv::flip(_cameraFeed, _mirorCameraFeed,1);
		draw_cube(miror_cameraFeed, cube); //, Cube face color Data, will see
		imshow(MAIN_WINDOW_NAME, _mirorCameraFeed);
		waitKey(30);
	}
}

OpenCvHandler::OpenCvHandler( void )
{
	//setting
	_faceMat = new std::vector<cv::Mat>(6);
	_colorMatrix = new std::vector<int>(6);
	_HSVConfig = new std::vector<std::vector<int>>(6);
	for (int i = 0;i < 6; i++)
		_hsvConfig[i] = new std::vector<int>(6);
	_colorsScalar = new std::vector<cv::Scalar>(6);
	_colorsScalar[WHITE] = Scalar(255,255,255);
	_colorsScalar[YELLOW] = Scalar(0,255,255);
	_colorsScalar[GREEN] = Scalar(0,255,0);
	_colorsScalar[BLUE] = Scalar(255,0,0);
	_colorsScalar[RED] = Scalar(0,0,255);
	_colorsScalar[ORANGE] = Scalar(0,125,255);

	// try this
	_HSVCONFIG[RED][H_MIN] = 128;
	_HSVCONFIG[RED][H_MAX] = 213;
	_HSVCONFIG[RED][V_MIN] = 0;
	_HSVCONFIG[RED][V_MAX] = 256;
	_HSVCONFIG[RED][S_MIN] = 198;
	_HSVCONFIG[RED][S_MAX] = 256;
	
	_HSVCONFIG[WHITE][H_MIN] = 18;
	_HSVCONFIG[WHITE][H_MAX] = 83;
	_HSVCONFIG[WHITE][V_MIN] = 148;
	_HSVCONFIG[WHITE][V_MAX] = 210;
	_HSVCONFIG[WHITE][S_MIN] = 0;
	_HSVCONFIG[WHITE][S_MAX] = 26;
	
	_HSVCONFIG[YELLOW][H_MIN] = 0;
	_HSVCONFIG[YELLOW][H_MAX] = 41;
	_HSVCONFIG[YELLOW][V_MIN] = 217;
	_HSVCONFIG[YELLOW][V_MAX] = 256;
	_HSVCONFIG[YELLOW][S_MIN] = 54;
	_HSVCONFIG[YELLOW][S_MAX] = 159;

	_HSVCONFIG[ORANGE][H_MIN] = 0;
	_HSVCONFIG[ORANGE][H_MAX] = 41;
	_HSVCONFIG[ORANGE][V_MIN] = 217;
	_HSVCONFIG[ORANGE][V_MAX] = 256;
	_HSVCONFIG[ORANGE][S_MIN] = 54;
	_HSVCONFIG[ORANGE][S_MAX] = 159;

	_HSVCONFIG[BLUE][H_MIN] = 0;
	_HSVCONFIG[BLUE][H_MAX] = 41;
	_HSVCONFIG[BLUE][V_MIN] = 217;
	_HSVCONFIG[BLUE][V_MAX] = 256;
	_HSVCONFIG[BLUE][S_MIN] = 54;
	_HSVCONFIG[BLUE][S_MAX] = 159;

	_HSVCONFIG[GREEN][H_MIN] = 0;
	_HSVCONFIG[GREEN][H_MAX] = 41;
	_HSVCONFIG[GREEN][V_MIN] = 217;
	_HSVCONFIG[GREEN][V_MAX] = 256;
	_HSVCONFIG[GREEN][S_MIN] = 54;
	_HSVCONFIG[GREEN][S_MAX] = 159;

	//init
	VideoCapture capture;
	capture.open(0);
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
}

OpenCvHandler::OpenCvHandler( OpenCvHandler const & src )
{
}

OpenCvHandler::~OpenCvHandler( void )
{
	delete _faceMat;
	delete _colorMatrix;
	
	for (int i = 0;i < 6; i++)
		_HSVConfig[i] = new std::vector<int>(6);
	_HSVConfig = new std::vector<std::vector<int>>(6);
}

OpenCvHandler &OpenCvHandler::operator=( OpenCvHandler const & rhs )
{
}
