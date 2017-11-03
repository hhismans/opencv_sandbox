/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencvHandler.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:38:06 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/03 02:52:01 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OpenCvHandler.class.hpp"

#include "../includes/Cube.class.hpp"
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
void OpenCvHandler::draw_cube(Mat& img) //, Cube face color Data, will see, Please do not puke on this code
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
			cv::rectangle(img, p1, p2, _cube._face[FACEUP][3*i + i], -1,8,0);
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
				cv::rectangle(img, p1, p2, _cube._face[1 + face][i*3 + j], -1,8,0);
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
			cv::rectangle(img, p1, p2, _cube._face[FACEDOWN][i*3 + j], -1,8,0);
		}
	}
}



void on_trackbar( int, void* )
{
	//This function gets called whenever a
	// trackbar position is changed
	for (int i = 0; i < 6 ; i++)
	{
		switch (i)
		{
			case WHITE: 	cout << "WHITE : " << endl;
			case BLUE:		cout << "BLUE : " << endl;
			case RED:		cout << "RED : " << endl;
			case ORANGE:	cout << "ORANGE : " << endl;
			case YELLOW:	cout << "YELLOW : " << endl;
			case GREEN: 	cout << " GREEN : " << endl;
			default : std::cerr << "Error using debug function" << std::endl;return;
		}
	}
}

enum {
	NORMAL,
	FILTRED
};

void OpenCvHandler::debug_window(int color, int type){
	std::string window_name = "debug window : ";
	std::string track_bar_name = "trackBar : ";
	cv::Mat mat_to_show;

	switch (color)
	{
		case WHITE: 	track_bar_name += "WHITE";window_name += "WHITE"; break;
		case BLUE:		track_bar_name += "BLUE";window_name += "BLUE"; break;
		case RED:		track_bar_name += "RED";window_name += "RED"; break;
		case ORANGE:	track_bar_name += "ORANGE";window_name += "ORANGE"; break;
		case YELLOW:	track_bar_name += "YELLOE";window_name += "YELLOW"; break;
		case GREEN: 	track_bar_name += "GREEN";window_name += "GREEN"; break;
		default : std::cerr << "Error using debug function" << std::endl;return;
	}
	switch (type)
	{
		case NORMAL		: window_name += " NORMAL";mat_to_show = _faceMat[color];break;
		case FILTRED	: window_name += " FILTRED";mat_to_show = _filtredFaceMat[color];break;
	}

	imshow(window_name, mat_to_show);
	if (!_debugShown[color])
	{
	imshow(track_bar_name, mat_to_show);
	cv::createTrackbar( "H_MIN",track_bar_name , &_HSVConfig[color][H_MIN], 256, on_trackbar );
    cv::createTrackbar( "H_MAX",track_bar_name , &_HSVConfig[color][H_MAX], 256, on_trackbar );

	cv::createTrackbar( "V_MIN",track_bar_name , &_HSVConfig[color][V_MIN], 256, on_trackbar );
    cv::createTrackbar( "V_MAX",track_bar_name , &_HSVConfig[color][V_MAX], 256, on_trackbar );

	cv::createTrackbar( "S_MIN",track_bar_name , &_HSVConfig[color][S_MIN], 256, on_trackbar );
    cv::createTrackbar( "S_MAX",track_bar_name , &_HSVConfig[color][S_MAX], 256, on_trackbar );
	_debugShown[color] = true;
	}

}

void OpenCvHandler::createTrackBars(){

	Mat src;
	std::string trackbarWindowName = "Trackbar";
	src = imread("cat.jpg");
	imshow(trackbarWindowName, src);
	cv::namedWindow(trackbarWindowName, 0);

	cv::createTrackbar( "H_MIN", trackbarWindowName, &_HSVConfig[WHITE][H_MIN], 256, on_trackbar );
    cv::createTrackbar( "H_MAX", trackbarWindowName, &_HSVConfig[WHITE][H_MAX], 256, on_trackbar );

	cv::createTrackbar( "V_MIN", trackbarWindowName, &_HSVConfig[WHITE][V_MIN], 256, on_trackbar );
    cv::createTrackbar( "V_MAX", trackbarWindowName, &_HSVConfig[WHITE][V_MAX], 256, on_trackbar );

	cv::createTrackbar( "S_MIN", trackbarWindowName, &_HSVConfig[WHITE][S_MIN], 256, on_trackbar );
    cv::createTrackbar( "S_MAX", trackbarWindowName, &_HSVConfig[WHITE][S_MAX], 256, on_trackbar );

	cout << "H [" << _HSVConfig[BLUE][H_MIN] << "," << _HSVConfig[BLUE][H_MAX] << endl;
	cout << "V [" << _HSVConfig[BLUE][V_MIN] << "," << _HSVConfig[BLUE][V_MAX] << endl;
	cout << "S [" << _HSVConfig[BLUE][S_MIN] << "," << _HSVConfig[BLUE][S_MAX] << endl;
}

std::vector<bool> OpenCvHandler::getColorPresenceMap(Mat &img)
{
	std::vector<bool> ret(20);

	int used = 300;
	int size = 30;
	int limit = (size * size) * 40 / 100; // 60% rempli =couleur est la
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
    //dilate with larger element so make sure object is nicely visible // Maybe it's too much
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

void OpenCvHandler::bundleFaces()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (_boolPresenceMats[i][j])
			{
				if (_bundlePresenceMat[j] != -1)
					cout << "CONFLICT " << endl;
				else
				_bundlePresenceMat[j] = i;
			}
		}
	}
}

void OpenCvHandler::resetBundlePresence()
{
	for (int i = 0 ;i < 9; i++)
		_bundlePresenceMat[i] = -1;
}

bool OpenCvHandler::isBundleFull()
{
	for (int i = 0 ;i < 9; i++)
		if (_bundlePresenceMat[i] == -1)return false;
	return true;
}

void OpenCvHandler::run(void)
{
	createTrackBars();
	int step = 1;
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
			draw_valid_square(_cameraFeed, _colorsScalar[i], _boolPresenceMats[i]);

		bundleFaces();
		if (_bundlePresenceMat[CENTER] == step)
		{
			cout << "VALID" <<endl;
			if (isBundleFull())
			{
				_cube.changeFace(step, _bundlePresenceMat);
				step++;
			}
		}
		cv::flip(_cameraFeed, _mirorCameraFeed,1);
		draw_cube(_mirorCameraFeed); //, Cube face color Data, will see
		imshow(MAIN_WINDOW_NAME, _mirorCameraFeed);
		//imshow("debug_window", _filtredFaceMat[WHITE]);
		debug_window(RED, NORMAL);
		debug_window(RED, FILTRED);
		resetBundlePresence();
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

	for (int i = 0;i < 6; i++)
	{
		_debugShown[i] = false;
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
	
	_HSVConfig[WHITE][H_MIN] = 0;
	_HSVConfig[WHITE][H_MAX] = 61;
	_HSVConfig[WHITE][V_MIN] = 209;
	_HSVConfig[WHITE][V_MAX] = 256;
	_HSVConfig[WHITE][S_MIN] = 0;
	_HSVConfig[WHITE][S_MAX] = 41;
	
	_HSVConfig[YELLOW][H_MIN] = 13;
	_HSVConfig[YELLOW][H_MAX] = 47;
	_HSVConfig[YELLOW][V_MIN] = 172;
	_HSVConfig[YELLOW][V_MAX] = 206;
	_HSVConfig[YELLOW][S_MIN] = 83;
	_HSVConfig[YELLOW][S_MAX] = 168;

	_HSVConfig[ORANGE][H_MIN] = 0;
	_HSVConfig[ORANGE][H_MAX] = 41;
	_HSVConfig[ORANGE][V_MIN] = 208;
	_HSVConfig[ORANGE][V_MAX] = 256;
	_HSVConfig[ORANGE][S_MIN] = 140;
	_HSVConfig[ORANGE][S_MAX] = 178;

	_HSVConfig[BLUE][H_MIN] = 88;
	_HSVConfig[BLUE][H_MAX] = 118;
	_HSVConfig[BLUE][V_MIN] = 115;
	_HSVConfig[BLUE][V_MAX] = 212;
	_HSVConfig[BLUE][S_MIN] = 239;
	_HSVConfig[BLUE][S_MAX] = 256;

	_HSVConfig[GREEN][H_MIN] = 54;
	_HSVConfig[GREEN][H_MAX] = 87;
	_HSVConfig[GREEN][V_MIN] = 133;
	_HSVConfig[GREEN][V_MAX] = 256;
	_HSVConfig[GREEN][S_MIN] = 211;
	_HSVConfig[GREEN][S_MAX] = 256;

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
