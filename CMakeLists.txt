cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
set (NAME_SRC
		src/main.cpp
		src/OpenCvHandler.class.cpp
		src/Cube.class.cpp
		src/Piece.class.cpp
		)
set (NAME_HEADERS
	includes/OpenCvHandler.class.hpp
	includes/Cube.class.hpp
	includes/Piece.class.hpp
	)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS}/includes)
add_executable( DisplayImage ${NAME_SRC} ${NAME_HEADERS} )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
