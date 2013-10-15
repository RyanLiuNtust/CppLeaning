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
#include "MatUtilityTesting.h"

int main() {

	MatUtilityTesting *U = new MatUtilityTesting(100, 100, CV_8UC1);
	U->WriteUsingAtGray();
	U->ShowImage();
	return 0;
}
