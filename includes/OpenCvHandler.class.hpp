/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencvHandler.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:32:30 by hhismans          #+#    #+#             */
/*   Updated: 2017/10/25 04:56:50 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENCVHANDLER_CLASS_HPP
# define OPENCVHANDLER_CLASS_HPP

# include <iostream>
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/imgproc/imgproc.hpp"

# include "../includes/Cube.class.hpp"

# define FRAME_WIDTH  640
# define FRAME_HEIGHT  480
# define MAIN_WINDOW_NAME "Main window"

#define CENTER 4

using namespace cv;
using namespace std;
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

enum
{
	H_MIN,
	H_MAX,
	S_MIN,
	S_MAX,
	V_MIN,
	V_MAX
};

class OpenCvHandler
{
	public:
		OpenCvHandler( void );
		OpenCvHandler( OpenCvHandler const & src );
		~OpenCvHandler( void );

		OpenCvHandler &	operator=( OpenCvHandler const & rhs);
		void createTrackBars();
		void run();
		void draw_square(Mat& img, const Scalar& color); // user use this too see where to put his cube
		void draw_valid_square(Mat& img, const Scalar& color, vector<bool> boolMat); // user use this too see where to put his cube
		void draw_cube(Mat& img); //, Cube face color Data, will see
		void morphOps(Mat &src, Mat &dst);

		void resetBundlePresence();
		void bundleFaces();
		bool isBundleFull();

		std::vector<bool>getColorPresenceMap(Mat &img);
		

	private:
		Cube								_cube;
		cv::VideoCapture					_capture;
		cv::Mat								_cameraFeed;
		cv::Mat								_mirorCameraFeed;
		cv::Mat								_HSVMat;
		std::vector<cv::Mat>				_faceMat;
		std::vector<cv::Mat>				_filtredFaceMat;
		std::vector<int>					_bundlePresenceMat;
		std::vector< std::vector<bool> >	_boolPresenceMats;
		std::vector< std::vector<int> >		_HSVConfig;
		std::vector<cv::Scalar>				_colorsScalar;

};

#endif
