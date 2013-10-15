/*
 * MatUtilityTesting.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: ryan
 */

#include "MatUtilityTesting.h"

MatUtilityTesting::MatUtilityTesting(int row, int col, int channels) {
	mTest = cv::Mat::zeros(row, col, channels); //<<<<<
	//ShowImage();
}

void MatUtilityTesting::WriteUsingAtColor() {

}

void MatUtilityTesting::WriteUsingAtGray() {
	for(int i = 0; i < mTest.rows; i++) {
		for(int j = 0; j < mTest.cols; j++) {
			mTest.at<uchar>(i,j) = 255.0;
		}
	}
}

void MatUtilityTesting::WriteUsingPtrColor() {

}

void MatUtilityTesting::WriteUsingPtrGray() {
	uchar *ptr = NULL;
	int row = mTest.rows;
	int col = mTest.cols;

	if(mTest.isContinuous()) {
		col = row * col;
		row = 1;
	}

	for(int j = 0; j < mTest.rows;j++) {
		ptr = mTest.data + j*mTest.step;
		for(int i = 0; i < mTest.cols;i++) {
			ptr[i] = 255;
		}
	}
}

void MatUtilityTesting::ShowImage() {
	cv::imshow("mTest", mTest);
	cv::waitKey(0);
	cv::destroyWindow("mTest");
}
