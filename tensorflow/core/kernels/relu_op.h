/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

// See docs in ../ops/nn_ops.cc.

#ifndef TENSORFLOW_KERNELS_RELU_OP_H_
#define TENSORFLOW_KERNELS_RELU_OP_H_

#define EIGEN_USE_THREADS

#include "third_party/eigen3/unsupported/Eigen/CXX11/Tensor"
#include "tensorflow/core/framework/numeric_op.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "tensorflow/core/framework/register_types.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/kernels/relu_op_functor.h"
#include "tensorflow/core/lib/core/errors.h"
#include "tensorflow/core/common_runtime/timer_use.h"

namespace tensorflow {

template <typename Device, typename T>
class ReluOp : public UnaryElementWiseOp<T, ReluOp<Device, T>> {
 public:
  using UnaryElementWiseOp<T, ReluOp<Device, T>>::UnaryElementWiseOp;

  void Operate(OpKernelContext* context, const Tensor& input, Tensor* output) {
	clock_t startStamp = clock();
    functor::Relu<Device, T> functor;
    functor(context->eigen_device<Device>(), input.flat<T>(),
            output->flat<T>());
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
  }
};

// Out of line check to save code space (we have this code once, rather
// than once for every NDIMS * NumTypes * Num_different_relu_variants
// functions.
struct ReluHelpers {
  static void ValidateSameSizeHelper(OpKernelContext* context, const Tensor& g,
                                     const Tensor& a) {
    OP_REQUIRES(context, a.IsSameSize(g),
                errors::InvalidArgument("g and a must be the same size"));
  }
  static bool ValidateSameSize(OpKernelContext* context, const Tensor& g,
                               const Tensor& a) {
    ValidateSameSizeHelper(context, g, a);
    return context->status().ok();
  }
};

template <typename Device, typename T>
class ReluGradOp : public BinaryElementWiseOp<T, ReluGradOp<Device, T>> {
 public:
  using BinaryElementWiseOp<T, ReluGradOp<Device, T>>::BinaryElementWiseOp;

  void OperateNoTemplate(OpKernelContext* context, const Tensor& g,
                         const Tensor& a, Tensor* output);

  // INPUTS:
  //   g (gradients): backpropagated gradients
  //   a (inputs): either the inputs that were passed to ReluOp(), or its
  //               outputs (using either one yields the same result here).
  // OUTPUT:
  //   gradients to backprop
  template <int NDIMS>
  void Operate(OpKernelContext* context, const Tensor& g, const Tensor& a,
               Tensor* output) {
	clock_t startStamp = clock();
    OperateNoTemplate(context, g, a, output);
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
  }
};

template <typename Device, typename T>
void ReluGradOp<Device, T>::OperateNoTemplate(OpKernelContext* context,
                                              const Tensor& g, const Tensor& a,
                                              Tensor* output) {
  if (!ReluHelpers::ValidateSameSize(context, g, a)) return;
  functor::ReluGrad<Device, T> functor;
  functor(context->eigen_device<Device>(), g.flat<T>(), a.flat<T>(),
          output->flat<T>());
}

template <typename Device, typename T>
class Relu6Op : public UnaryElementWiseOp<T, Relu6Op<Device, T>> {
 public:
  using UnaryElementWiseOp<T, Relu6Op<Device, T>>::UnaryElementWiseOp;

  void Operate(OpKernelContext* context, const Tensor& input, Tensor* output) {
	 clock_t startStamp = clock();
    functor::Relu6<Device, T> functor;
    functor(context->eigen_device<Device>(), input.flat<T>(),
            output->flat<T>());
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
  }
};

template <typename Device, typename T>
class Relu6GradOp : public BinaryElementWiseOp<T, Relu6GradOp<Device, T>> {
 public:
  using BinaryElementWiseOp<T, Relu6GradOp<Device, T>>::BinaryElementWiseOp;

  void OperateNoTemplate(OpKernelContext* context, const Tensor& g,
                         const Tensor& a, Tensor* output);

  // INPUTS:
  //   g (gradients): backpropagated gradients
  //   a (inputs): inputs that were passed to Relu6Op()
  // OUTPUT:
  //   gradients to backprop
  template <int NDIMS>
  void Operate(OpKernelContext* context, const Tensor& g, const Tensor& a,
               Tensor* output) {
	clock_t startStamp = clock();
    OperateNoTemplate(context, g, a, output);
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
  }
};

template <typename Device, typename T>
void Relu6GradOp<Device, T>::OperateNoTemplate(OpKernelContext* context,
                                               const Tensor& g, const Tensor& a,
                                               Tensor* output) {
  if (!ReluHelpers::ValidateSameSize(context, g, a)) return;
  functor::Relu6Grad<Device, T> functor;
  functor(context->eigen_device<Device>(), g.flat<T>(), a.flat<T>(),
          output->flat<T>());
}

template <typename Device, typename T>
class EluOp : public UnaryElementWiseOp<T, EluOp<Device, T>> {
 public:
  using UnaryElementWiseOp<T, EluOp<Device, T>>::UnaryElementWiseOp;

  void Operate(OpKernelContext* context, const Tensor& input, Tensor* output) {
	clock_t startStamp = clock();
    functor::Elu<Device, T> functor;
    functor(context->eigen_device<Device>(), input.flat<T>(),
            output->flat<T>());
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
  }
};

template <typename Device, typename T>
class EluGradOp : public BinaryElementWiseOp<T, EluGradOp<Device, T>> {
 public:
  using BinaryElementWiseOp<T, EluGradOp<Device, T>>::BinaryElementWiseOp;

  void OperateNoTemplate(OpKernelContext* context, const Tensor& g,
                         const Tensor& a, Tensor* output);

  // INPUTS:
  //   g (gradients): backpropagated gradients
  //   a (outputs): outputs of the EluOp()
  // OUTPUT:
  //   gradients to backprop
  template <int NDIMS>
  void Operate(OpKernelContext* context, const Tensor& g, const Tensor& a,
               Tensor* output) {
	clock_t startStamp = clock();
    OperateNoTemplate(context, g, a, output);
	clock_t stopStamp= clock();
	double period = (double)(stopStamp-startStamp)/CLOCKS_PER_SEC;
	timer_use::setOpTime(16,period);
	
  }
};

template <typename Device, typename T>
void EluGradOp<Device, T>::OperateNoTemplate(OpKernelContext* context,
                                             const Tensor& g, const Tensor& a,
                                             Tensor* output) {
  if (!ReluHelpers::ValidateSameSize(context, g, a)) return;
  functor::EluGrad<Device, T> functor;
  functor(context->eigen_device<Device>(), g.flat<T>(), a.flat<T>(),
          output->flat<T>());
}

}  // namespace tensorflow

#undef EIGEN_USE_THREADS

#endif  // TENSORFLOW_KERNELS_RELU_OP_H_
