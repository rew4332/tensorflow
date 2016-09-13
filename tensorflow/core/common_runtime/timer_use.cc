#include "timer_use.h"
#include <ctime>
#include <iostream>

namespace tensorflow
{
	
	clock_t timer_use::tInitGPUStartStamp = 0;
	clock_t timer_use::tInitGPUStopStamp = 0;
	double timer_use::tInitGPU = 0;
	
	clock_t timer_use::tMemH2DStartStamp = 0;
	clock_t timer_use::tMemH2DStopStamp = 0;
	double timer_use::tMemH2D = 0;
	
	clock_t timer_use::tMemD2HStartStamp = 0;
	clock_t timer_use::tMemD2HStopStamp = 0;
	double timer_use::tMemD2H = 0;
		
	//GPU Init
	double timer_use::getInitGPU()
	{
		return timer_use::tInitGPU;
	}

	void timer_use::initGPUStart()
	{
		timer_use::tInitGPUStartStamp = clock();
	}

	void timer_use::initGPUStop()
	{
		timer_use::tInitGPUStopStamp = clock();
		double t = (double)(timer_use::tInitGPUStopStamp-timer_use::tInitGPUStartStamp)/CLOCKS_PER_SEC;
		timer_use::tInitGPU+=t;
		
	}
	
	//H2D
	double timer_use::getMemH2D()
	{
		return timer_use::tMemH2D;
	}

	void timer_use::memH2DStart()
	{
		timer_use::tMemH2DStartStamp = clock();
	}

	void timer_use::memH2DStop()
	{
		timer_use::tMemH2DStopStamp = clock();
		double t = (double)(timer_use::tMemH2DStopStamp-timer_use::tMemH2DStartStamp)/CLOCKS_PER_SEC;
		timer_use::tMemH2D+=t;
	}
	
	//D2H
	double timer_use::getMemD2H()
	{
		return timer_use::tMemD2H;
	}

	void timer_use::memD2HStart()
	{
		timer_use::tMemD2HStartStamp = clock();
	}

	void timer_use::memD2HStop()
	{
		timer_use::tMemD2HStopStamp = clock();
		double t = (double)(timer_use::tMemD2HStopStamp-timer_use::tMemD2HStartStamp)/CLOCKS_PER_SEC;
		timer_use::tMemD2H+=t;
	}
     
}
