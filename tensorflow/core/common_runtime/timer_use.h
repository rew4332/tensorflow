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
		double initGPU();
		void initGPUStart();
		void initGPUEnd();
        void hello();

		double memcpyHostToDevice();
		void memcpyHostToDeviceStart();
		void memcpyHostToDeviceEnd();

	private:
		double tInitGPU;
		clock_t tInitGPUStartStamp;
		clock_t tInitGPUEndStamp;
		
		double tMemH2D;
		clock_t tMemH2DStartStamp;
		clock_t tMemH2DEndStamp;
	};
}