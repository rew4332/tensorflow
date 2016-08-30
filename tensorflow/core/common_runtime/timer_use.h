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
		timer_use();
		static double initGPU();
		static void initGPUStart();
		static void initGPUEnd();

                static void hello();
		static double get();

		double memcpyHostToDevice();
		void memcpyHostToDeviceStart();
		void memcpyHostToDeviceEnd();

	private:
		static double tInitGPU;
		static double n;
		static clock_t tInitGPUStartStamp;
		static clock_t tInitGPUEndStamp;
		
		double tMemH2D;
		clock_t tMemH2DStartStamp;
		clock_t tMemH2DEndStamp;
	};
}
