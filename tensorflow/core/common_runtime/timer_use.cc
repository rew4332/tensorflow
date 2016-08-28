#include "timer_use.h"
#include <ctime>
#include <iostream>

namespace tensorflow
{
	int timer_use::n = 0;

	timer_use::timer_use()
	{
		tInitGPU = 0;
		tMemH2D = 0;
	}

	double timer_use::initGPU()
	{
		return this->tInitGPU;
	}

	void timer_use::initGPUStart()
	{
		tInitGPUStartStamp = clock();
	}

	void timer_use::initGPUEnd()
	{
		tInitGPUEndStamp = clock();
		this->tInitGPU = tInitGPUEndStamp-tInitGPUStartStamp;
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
		timer_use::n++;
        std::cout<<"\n\nhello hello hello timer_user.cc\n\n";
    }
	int timer_use::get()
	{
		return timer_use::n;
	}
}