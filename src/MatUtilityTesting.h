/*
 * MatUtilityTesting.h
 *
 *  Created on: Oct 15, 2013
 *      Author: ryan
 */

#ifndef MATUTILITYTESTING_H_
#define MATUTILITYTESTING_H_
#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp> //<<<<<


class MatUtilityTesting {

public:
	MatUtilityTesting(int row, int col, int channels);
	void WriteUsingPtrGray();
	void WriteUsingAtGray();
	void WriteUsingPtrColor();
	void WriteUsingAtColor();
	void ShowImage();
private:
	cv::Mat mTest;
};

#endif /* MATUTILITYTESTING_H_ */
