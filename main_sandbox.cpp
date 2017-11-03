#include <sstream>
#include <string>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

enum
{
	WHITE,
	ORANGE,
	GREEN,
	RED,
	BLUE,
	YELLOW
};

enum
{
	UP,
	BACK,
	LEFT,
	FRONT,
	RIGHT,
	DOWN
};

class Cube
{
	public :
		Scalar _face[6][9];
		Cube();
};

Cube::Cube(){
	cout << "cube created" << endl;
	for (int face = 0; face < 6 ; face++)
	{
		for (int square = 0; square < 9; square++)
		{
			switch (face)
			{
				case WHITE : _face[face][square] = Scalar(255,255,255);break;
				case ORANGE : _face[face][square] = Scalar(0,125,255);break;
				case GREEN : _face[face][square] = Scalar(0,255,0);break;
				case RED : _face[face][square] = Scalar(0,0,255);break;
				case BLUE : _face[face][square] = Scalar(255,0,0);break;
				case YELLOW : _face[face][square] = Scalar(0,255,255);break;
			}
		}
	}
}

enum
{
	H_MIN,
	H_MAX,
	S_MIN,
	S_MAX,
	V_MIN,
	V_MAX
};

int REDCONFIG[6];
int WHITECONFIG[6];
int YELLOWCONFIG[6];
int ORANGECONFIG[6];
int BLUECONFIG[6];
int GREENCONFIG[6];




const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

const string WINDOW_NAME = "main";
const string WINDOW_HSV = "HSV";
const string WINDOW_3 = "thresholded Image Title";
const string trackbarWindowName = "after shit";

void on_trackbar( int, void* )
{//This function gets called whenever a
	// trackbar position is changed
	cout << "H [" << WHITECONFIG[H_MIN] << "," << WHITECONFIG[H_MAX] << endl;
	cout << "V [" << WHITECONFIG[V_MIN] << "," << WHITECONFIG[V_MAX] << endl;
	cout << "S [" << WHITECONFIG[S_MIN] << "," << WHITECONFIG[S_MAX] << endl;
}

void createTrackBars(){

	Mat src;
	
	src = imread("cat.jpg");
	imshow(trackbarWindowName, src);
	cv::namedWindow(trackbarWindowName, 0);

	cv::createTrackbar( "H_MIN", trackbarWindowName, &WHITECONFIG[H_MIN], 256, on_trackbar );
    cv::createTrackbar( "H_MAX", trackbarWindowName, &WHITECONFIG[H_MAX], 256, on_trackbar );

	cv::createTrackbar( "V_MIN", trackbarWindowName, &WHITECONFIG[V_MIN], 256, on_trackbar );
    cv::createTrackbar( "V_MAX", trackbarWindowName, &WHITECONFIG[V_MAX], 256, on_trackbar );

	cv::createTrackbar( "S_MIN", trackbarWindowName, &WHITECONFIG[S_MIN], 256, on_trackbar );
    cv::createTrackbar( "S_MAX", trackbarWindowName, &WHITECONFIG[S_MAX], 256, on_trackbar );
    //cv::createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
    //cv::createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
    //cv::createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    //cv::createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
}
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
void draw_cube(Mat& img, Cube cube) //, Cube face color Data, will see
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

std::vector<Mat*> *crop_in_squares(Mat& img)
{
	int used = 300;
	int size = 30;
	int space_between = (used - 3 * size ) / 2;

	int startW = (FRAME_WIDTH - used) / 2;
	int startH = (FRAME_HEIGHT - used) / 2;

	std::vector<Mat *> *ret = new vector<Mat*>;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Rect croppe(startW + i*(size + space_between),startH + j*(size + space_between), size, size);
			ret->push_back(new Mat());
		}
	}
	return ret;
}

void draw_square(Mat& img, const Scalar& color) // user use this too see where to put his cube
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

void draw_valid_square(Mat& img, const Scalar& color, vector<bool> boolMat) // user use this too see where to put his cube
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

void morphOps(Mat &src, Mat &dst)
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

int ROI_countNonZero(Mat &img, Rect ROI)
{
	Mat croppedMat(img, ROI);
	return countNonZero(croppedMat);
}

void analyse_square(Mat &img)
{
	int used = 300;
	int size = 30;
	int space_between = (used - 3 * size ) / 2;

	int startW = (FRAME_WIDTH - used) / 2;
	int startH = (FRAME_HEIGHT - used) / 2;

	Mat square(img, Rect(startW,startH, size,size));
	if (countNonZero(square) > 500)
		cout << "FOUND" << endl;
	else
		cout << "NOT FOUND" << endl;
}

std::vector<bool>getColorPresenceMap(Mat &img)
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
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ret[i*3 + j] << "\t";
		}
		cout << endl;
	}

	cout << "--------------------" <<  endl;
	return ret;
}

int main (int argc, char **argv )
{
REDCONFIG[H_MIN] = 128;
REDCONFIG[H_MAX] = 213;
REDCONFIG[V_MIN] = 0;
REDCONFIG[V_MAX] = 256;
REDCONFIG[S_MIN] = 198;
REDCONFIG[S_MAX] = 256;

WHITECONFIG[H_MIN] = 18;
WHITECONFIG[H_MAX] = 83;
WHITECONFIG[V_MIN] = 148;
WHITECONFIG[V_MAX] = 210;
WHITECONFIG[S_MIN] = 0;
WHITECONFIG[S_MAX] = 26;

YELLOWCONFIG[H_MIN] = 0;
YELLOWCONFIG[H_MAX] = 41;
YELLOWCONFIG[V_MIN] = 217;
YELLOWCONFIG[V_MAX] = 256;
YELLOWCONFIG[S_MIN] = 54;
YELLOWCONFIG[S_MAX] = 159;

	createTrackBars();

	//Matrix to store each frame of the webcam feed
	Cube cube;
	Mat filtred_red;
	Mat cameraFeed;
	Mat miror_cameraFeed;
	//matrix storage for HSV image
	Mat HSV;
	//matrix storage for binary threshold image
	Mat whiteMat;
	Mat redMat;
	Mat yellowMat;

	VideoCapture capture;
	capture.open(0);
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);


	
		//void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
//std::vector<Mat> crop_in_squares(Mat& img)
	while (1)
	{
		capture.read(cameraFeed); // capture matrix from camera feed


		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV); // convert to HSV mat
		inRange(HSV,Scalar(WHITECONFIG[H_MIN],WHITECONFIG[S_MIN],WHITECONFIG[V_MIN]),
				Scalar(WHITECONFIG[H_MAX],WHITECONFIG[S_MAX],WHITECONFIG[V_MAX]),whiteMat);
		inRange(HSV,Scalar(YELLOWCONFIG[H_MIN],YELLOWCONFIG[S_MIN],YELLOWCONFIG[V_MIN]),
				Scalar(YELLOWCONFIG[H_MAX],YELLOWCONFIG[S_MAX],YELLOWCONFIG[V_MAX]),yellowMat);
		inRange(HSV,Scalar(REDCONFIG[H_MIN],REDCONFIG[S_MIN],REDCONFIG[V_MIN]),
				Scalar(REDCONFIG[H_MAX],REDCONFIG[S_MAX],REDCONFIG[V_MAX]),redMat);
		draw_square(cameraFeed, Scalar(255,0,0));

		morphOps(redMat, filtred_red);

		std::vector<bool> tab= getColorPresenceMap(filtred_red);
		draw_valid_square(cameraFeed, Scalar(0,0,255), tab);

//		imshow(WINDOW_HSV, HSV);
		cv::flip(cameraFeed, miror_cameraFeed,1);
		//std::vector<Mat*> *allSquares = crop_in_squares(miror_cameraFeed);
		draw_cube(miror_cameraFeed, cube); //, Cube face color Data, will see

		imshow(WINDOW_NAME, miror_cameraFeed);
		//imshow("firstSquare", *allSquares->front());
		//imshow("filtred red finder", redMat);
		//imshow("yellow finder", yellowMat);
		//imshow("white finder", whiteMat);
		imshow("filtred red", filtred_red);
		//imshow(WINDOW_3, threshold);
		waitKey(30);
	}
	cv::waitKey(0);
}

/*
#include <cv.h>
#include <highgui.h>

using namespace cv;

/// Global Variables
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

/// Matrices to store images
Mat src1;
Mat src2;
Mat dst;

void on_trackbar( int, void* )
{
 alpha = (double) alpha_slider/alpha_slider_max ;
 beta = ( 1.0 - alpha );

 addWeighted( src1, alpha, src2, beta, 0.0, dst);

 imshow( "Linear Blend", dst );
}

int main( int argc, char** argv )
{
 /// Read image ( same size, same type )
 src1 = imread("one.jpg");
 src2 = imread("two.jpg");


 if( !src1.data ) { printf("Error loading src1 \n"); return -1; }
 if( !src2.data ) { printf("Error loading src2 \n"); return -1; }

 /// Initialize values
 alpha_slider = 0;

 /// Create Windows
 namedWindow("Linear Blend", 1);

 /// Create Trackbars
 char TrackbarName[50];
 sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

 createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

 /// Show some stuff
 on_trackbar( alpha_slider, 0 );

 /// Wait until user press some key
 waitKey(0);
 return 0;
}*/
