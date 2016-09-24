#include "tensorflow/core/common_runtime/device.h"
#include "tensorflow/core/framework/rendezvous.h"
#include "tensorflow/core/framework/session_state.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/graph/graph.h"
#include "tensorflow/core/lib/core/notification.h"
#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/platform/logging.h"
#include "tensorflow/core/platform/macros.h"
#include <ctime>

namespace tensorflow
{
	class timer_use
	{
	public:
					
		static double getInitGPU();
		static void initGPUStart();
		static void initGPUStop();

		static double getMemH2D();
		static void memH2DStart();
		static void memH2DStop();
		
		static double getMemD2H();
		static void memD2HStart();
		static void memD2HStop();
		
		static double getCreateExe();
		static void createExeStart();
		static void createExeStop();
		
		static double getSendInput();
		static void sendInputStart();
		static void sendInputStop();
		
		static double getRecvOutput();
		static void recvOutputStart();
		static void recvOutputStop();
		
		static double getRunAsync();
		static void runAsyncStart();
		static void runAsyncStop();
		
		static void setOpTime(int,double);
		static double getOpTime(int);
		

		

	private:
		static double tInitGPU;
		static clock_t tInitGPUStartStamp;
		static clock_t tInitGPUStopStamp;
		
		static double tMemH2D;
		static clock_t tMemH2DStartStamp;
		static clock_t tMemH2DStopStamp;
		
		static double tMemD2H;
		static clock_t tMemD2HStartStamp;
		static clock_t tMemD2HStopStamp;
		
		static double tCreateExe;
		static clock_t tCreateExeStartStamp;
		static clock_t tCreateExeStopStamp;
		
		static double tSendInput;
		static clock_t tSendInputStartStamp;
		static clock_t tSendInputStopStamp;
		
		static double tRecvOutput;
		static clock_t tRecvOutputStartStamp;
		static clock_t tRecvOutputStopStamp;
		
		static double tRunAsync;
		static clock_t tRunAsyncStartStamp;
		static clock_t tRunAsyncStopStamp;
		
		static double tArgmax;
	};
}
