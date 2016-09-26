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
	//op time
	double timer_use::tArgmax = 0;
	double timer_use::tVariable = 0;
	double timer_use::tAssign = 0;
	double timer_use::tIdentity = 0;
	double timer_use::tRandomUniform = 0;
	double timer_use::tPlaceholder = 0;
	double timer_use::tMatMul = 0;
	double timer_use::tFill = 0;
	double timer_use::tReshape = 0;
	double timer_use::tShape = 0;
	double timer_use::tTile = 0;
	double timer_use::tCast = 0;
	double timer_use::tRange = 0;
	double timer_use::tDynamicStitch = 0;
	double timer_use::tBroadcastGradientArgs = 0;
	double timer_use::tApplyGradientDescent = 0;
	double timer_use::tRelu = 0;
	double timer_use::tBinary = 0;
	double timer_use::tUnary = 0;
	double timer_use::tReduction = 0;
	
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
	
	//op
	void timer_use::setOpTime(int opNum,double period)
	{
		switch(opNum)
		{
			case 0:
				timer_use::tArgmax+=period;
				break;
			case 1:
				timer_use::tVariable+=period;
				break;
			case 2:
				timer_use::tAssign+=period;
				break;
			case 3:
				timer_use::tIdentity+=period;
				break;
			case 4:
				timer_use::tRandomUniform+=period;
				break;
			case 5:
				timer_use::tPlaceholder+=period;
				break;
			case 6:
				timer_use::tMatMul+=1;//period;
				break;
			case 7:
				timer_use::tFill+=period;
				break;
			case 8:
				timer_use::tReshape+=period;
				break;
			case 9:
				timer_use::tShape+=period;
				break;
			case 10:
				timer_use::tTile+=period;
				break;
			case 11:
				timer_use::tCast+=period;
				break;
			case 12:
				timer_use::tRange+=period;
				break;
			case 13:
				timer_use::tDynamicStitch+=period;
				break;
			case 14:
				timer_use::tBroadcastGradientArgs+=period;
				break;
			case 15:
				timer_use::tApplyGradientDescent+=period;
				break;
			case 16:
				timer_use::tRelu+=period;
				break;
			case 17:
				timer_use::tBinary+=period;
				break;
			case 18:
				timer_use::tUnary+=period;
				break;
			case 19:
				timer_use::tReduction+=period;
		}
		
	}
	double timer_use::getOpTime(int opNum)
	{
		switch(opNum)
		{
			case 0:
				return timer_use::tArgmax;
				break;
			case 1:
				return timer_use::tVariable;
				break;
			case 2:
				return timer_use::tAssign;
				break;
			case 3:
				return timer_use::tIdentity;
				break;
			case 4:
				return timer_use::tRandomUniform;
				break;
			case 5:
				return timer_use::tPlaceholder;
				break;
			case 6:
				return timer_use::tMatMul;
				break;
			case 7:
				return timer_use::tFill;
				break;
			case 8:
				return timer_use::tReshape;
				break;
			case 9:
				return timer_use::tShape;
				break;
			case 10:
				return timer_use::tTile;
				break;
			case 11:
				return timer_use::tCast;
				break;
			case 12:
				return timer_use::tRange;
				break;
			case 13:
				return timer_use::tDynamicStitch;
				break;
			case 14:
				return timer_use::tBroadcastGradientArgs;
				break;
			case 15:
				return timer_use::tApplyGradientDescent;
				break;
			case 16:
				return timer_use::tRelu;
				break;
			case 17:
				return timer_use::tBinary;
				break;
			case 18:
				return timer_use::tUnary;
				break;
			case 19:
				return timer_use::tReduction;
				break;
			
			
		}
		return -1;
	}
	
     
}
