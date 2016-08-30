#include "timer_use.h"
#include <ctime>
#include <iostream>

namespace tensorflow
{
	double timer_use::n = 0;
        clock_t timer_use::tInitGPUStartStamp = 0;
	clock_t timer_use::tInitGPUEndStamp = 0;
	double timer_use::tInitGPU = 0;

	timer_use::timer_use()
	{
		tInitGPU = 0;
		tMemH2D = 0;
	}

	double timer_use::initGPU()
	{
		return timer_use::tInitGPU;
	}

	void timer_use::initGPUStart()
	{
		timer_use::tInitGPUStartStamp = clock();
	}

	void timer_use::initGPUEnd()
	{
		timer_use::tInitGPUEndStamp = clock();
		timer_use::tInitGPU+=(double)(timer_use::tInitGPUEndStamp-timer_use::tInitGPUStartStamp)/CLOCKS_PER_SEC;
	}
	
	double timer_use::memcpyHostToDevice()
	{
		return this->tMemH2D;
	}

	void timer_use::memcpyHostToDeviceStart()
	{
		//tMemH2DStartStamp = now();
	}

	void timer_use::memcpyHostToDeviceEnd()
	{
		//self.tMemH2D += now() - tInitGPUStartStamp;
	}

        void timer_use::hello()
        { 
		timer_use::n=1;
                //std::cout<<"\n\nhello hello hello timer_use.cc\n\n";
        }
	double timer_use::get()
	{
		return timer_use::n;
	}
}
