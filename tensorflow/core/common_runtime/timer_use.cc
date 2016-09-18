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
	
	double timer_use::tCreateExe = 0;
	clock_t timer_use::tCreateExeStartStamp = 0;
	clock_t timer_use::tCreateExeStopStamp = 0;
	
	double timer_use::tSendInput = 0;
	clock_t timer_use::tSendInputStartStamp = 0;
	clock_t timer_use::tSendInputStopStamp = 0;
	
	double timer_use::tRecvOutput = 0;
	clock_t timer_use::tRecvOutputStartStamp = 0;
	clock_t timer_use::tRecvOutputStopStamp = 0;
	
	double timer_use::tRunAsync = 0;
	clock_t timer_use::tRunAsyncStartStamp = 0;
	clock_t timer_use::tRunAsyncStopStamp = 0;
		
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
	
		
	//getOrCreateExecutor
	double timer_use::getCreateExe()
	{
		return timer_use::tCreateExe;
	}
	
	void timer_use::createExeStart()
	{
		timer_use::tCreateExeStartStamp = clock();
	}
	
	void timer_use::createExeStop()
	{
		timer_use::tCreateExeStopStamp = clock();
		double t = (double)(timer_use::tCreateExeStopStamp-timer_use::tCreateExeStartStamp)/CLOCKS_PER_SEC;
		timer_use::tCreateExe+=t;
	}
	
	//sendInput
	double timer_use::getSendInput()
	{
		return timer_use::tSendInput;
	}
	
	void timer_use::sendInputStart()
	{
		timer_use::tSendInputStartStamp = clock();
	}
	
	void timer_use::sendInputStop()
	{
		timer_use::tSendInputStopStamp = clock();
		double t = (double)(timer_use::tSendInputStopStamp-timer_use::tSendInputStartStamp)/CLOCKS_PER_SEC;
		timer_use::tSendInput+=t;
	}
	
	//receiveOutput
	double timer_use::getRecvOutput()
	{
		return timer_use::tRecvOutput;
	}
	
	void timer_use::recvOutputStart()
	{
		timer_use::tRecvOutputStartStamp = clock();
	}
	
	void timer_use::recvOutputStop()
	{
		timer_use::tRecvOutputStopStamp = clock();
		double t = (double)(timer_use::tRecvOutputStopStamp-timer_use::tRecvOutputStartStamp)/CLOCKS_PER_SEC;
		timer_use::tRecvOutput+=t;
	}
	
	//runAsynchro
	double timer_use::getRunAsync()
	{
		return timer_use::tRunAsync;
	}
	
	void timer_use::runAsyncStart()
	{
		timer_use::tRunAsyncStartStamp = clock();
	}
	
	void timer_use::runAsyncStop()
	{
		timer_use::tRunAsyncStopStamp = clock();
		double t = (double)(timer_use::tRunAsyncStopStamp-timer_use::tRunAsyncStartStamp)/CLOCKS_PER_SEC;
		timer_use::timer_use::tRunAsync+=t;
	}
	
     
}
