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


#include <omp.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/thread/thread.hpp>
#include <sys/time.h>
using namespace std;

#define Width 1024
#define DATA_SIZE Width*Width

int data[DATA_SIZE];
int data_cpu_single[DATA_SIZE];
int data_cpu_mp[DATA_SIZE];
int error[DATA_SIZE];

void GenerateNumbers(int *number, int size)
{
	for(int i = 0; i < size; i++)
		number[i] = rand() % 10;
}

void test_time_accuracy() {
	boost::progress_timer timer_accuracy;
	boost::timer time_multi_thread;
	timeval real_start_time;
	timeval real_end_time;
	gettimeofday(&real_start_time, 0);
	boost::this_thread::sleep(boost::posix_time::seconds(10));
	gettimeofday(&real_end_time, 0);
	cout << "boost_timer:accuracy:" << time_multi_thread.elapsed() << endl;
	cout << "timeval:accuracy:" << real_end_time.tv_sec - real_start_time.tv_sec << endl;
}

void omp() {
	boost::progress_timer timer;
	#pragma omp parallel for
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Width; j++)
			for(int k = 0; k < Width; k++)
				data_cpu_mp[i*Width+j] += data[i*Width+k] * data[k*Width+j];

}

void single() {
	boost::progress_timer timer2;
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Width; j++)
			for(int k = 0; k < Width; k++)
				data_cpu_single[i*Width+j] += data[i*Width+k] * data[k*Width+j];
}

int main()
{
	timeval real_start_time;
	timeval real_end_time;

	GenerateNumbers(data, DATA_SIZE);
	test_time_accuracy();

	boost::timer time_multi_thread;
	gettimeofday(&real_start_time, 0);
	omp();
	gettimeofday(&real_end_time, 0);
	cout << "mp_time_consuming:" << time_multi_thread.elapsed()<< "s\n";
	cout << "multithread timeval: " << real_end_time.tv_sec - real_start_time.tv_sec << "s\n";

	boost::timer time_used_cpu_single;
	gettimeofday(&real_start_time, 0);
	single();
	gettimeofday(&real_end_time, 0);
	cout << "time (CPU_single):" << time_used_cpu_single.elapsed() << "s\n";
	cout << "singal timeval: " << real_end_time.tv_sec - real_start_time.tv_sec << "s\n";

	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Width; j++)
			error[i*Width+j] = (data_cpu_single[i*Width+j]-data_cpu_mp[i*Width+j]);

	int sum_error = 0 ;
	for(int i = 0; i < Width; i++)
		for(int j = 0; j < Width; j++)
			sum_error += error[i*Width+j] ;
			cout<< sum_error << "\n";

	return 0;
}
