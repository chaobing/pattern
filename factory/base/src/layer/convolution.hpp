#pragma once
#include "Layer.hpp"
namespace layer_base{
class Convolution: public Layer{
	public:
		Convolution();
		~Convolution();
	public:
		virtual void exec() override;
};
}
