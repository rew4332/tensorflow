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
	};
}
