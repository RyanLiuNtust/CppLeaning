//============================================================================
// Name        : cpp.cpp
// Author      : pohsienliu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// 1. Alt+/ autocomplete for c++
// 2. Ctrl+Shift+t can use function name to find the function declaration
// 3. Don't use namespace and global variable
// 4. Ctrl+F11 run , F11 debug
//============================================================================

#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <string>
#include <time.h>
#include <omp.h>
#include <ctime>

int main() {

	std::string lenaPath = "/home/ryan/workspace/picture/basic/lena.jpg";
	cv::Mat Lena = cv::imread(lenaPath, 0);
	cv::namedWindow("lena",0);
	cv::imshow("lena",Lena);
	cv::waitKey(0);

	return 0;
}
